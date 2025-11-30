#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // For any_of function

using namespace std;

const int N_CHECK_PASSWORDS = 100; // Num. to read from test file
const int N_COMMON_PASSWORDS = 200; // Num. to read from common file
const string CHECK_PW_FILE = "testpwd.txt"; // Passwords to check
const string COMMON_PW_FILE = "200sorted.txt"; // Common passwords file, sorted

const int NOT_FOUND = -1; // Define NOT_FOUND

// Binary search function to find a password in the common passwords array
bool searchList(string list[], int numElems, string value) {
  int low = 0, high = numElems - 1;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (value > list[mid])
      low = mid + 1;
    else if (value < list[mid])
      high = mid - 1;
    else
      return true; // Password found in the common passwords list
  }

  return false; // Password not found
}

int main() {
  string checkPW[N_CHECK_PASSWORDS]; // Array to hold passwords to check
  string commonPW[N_COMMON_PASSWORDS]; // Array to hold common passwords

  ifstream checkPWFile(CHECK_PW_FILE);
  ifstream commonPWFile(COMMON_PW_FILE);

  // Check that each file was opened successfully
  if (!checkPWFile.good()) {
    cout << "Unable to open check passwords file (" << CHECK_PW_FILE << ")" << endl;
    return -1;
  }
  if (!commonPWFile.good()) {
    cout << "Unable to open common passwords file (" << COMMON_PW_FILE << ")" << endl;
    return -1;
  }

  // Load common passwords into the 'commonPW' array
  for (int i = 0; i < N_COMMON_PASSWORDS; i++) {
    if (!getline(commonPWFile, commonPW[i])) {
      cout << "Error reading common passwords file." << endl;
      return -1;
    }
  }

  // Loop to check each password in the check file
  int goodPasswords = 0;
  int badPasswords = 0;

  for (int i = 0; i < N_CHECK_PASSWORDS; i++) {
    string password;
    if (!getline(checkPWFile, password)) {
      cout << "Error reading check passwords file." << endl;
      return -1;
    }

    // Check the password strength
    bool hasCapitalLetter = any_of(password.begin(), password.end(), ::isupper);
    bool hasDigit = any_of(password.begin(), password.end(), ::isdigit);
    bool hasPunctuation = any_of(password.begin(), password.end(), ::ispunct);
    bool isCommon = searchList(commonPW, N_COMMON_PASSWORDS, password);

    if (password.length() >= 8 && hasCapitalLetter && hasDigit && hasPunctuation && !isCommon) {
      goodPasswords++;
    } else {
      badPasswords++;
    }
  }

  // Output the count of good and bad passwords
  cout << "Checked " << N_CHECK_PASSWORDS << " passwords. " << endl << "Good: " << goodPasswords << " Bad: "
       << badPasswords << endl;

  return 0;
}
