#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;


// Number of data points
const int NRECORDS = 3;

// Structure to store monthly traffic counts
struct BridgeTraffic {
    double gg; // Golden Gate Counts
    double sm; // San Mateo
    double bb; // Bay Bridge
    
};

int main() {
    // Array to hold traffic information for three months
    BridgeTraffic data[NRECORDS];

    // Get input values for each month
    for (int i = 0; i < NRECORDS; i++) {
        cout << "Enter month "<<  i + 1 <<" traffic across the Golden Gate Bridge : ";
        cin >> data[i].gg;
        cout << "Enter month "<<  i + 1 <<" traffic across the San Mateo Bridge: ";
        cin >> data[i].sm;
        cout << "Enter month "<<  i + 1 <<" traffic across the Bay Bridge: ";
        cin >> data[i].bb;
        
    }   // Calculate average and max values for each bridge
    double avgGG = 0.0, maxGG = data[0].gg;
    double avgBB = 0.0, maxBB = data[0].bb;
    double avgSM = 0.0, maxSM = data[0].sm;

    for (int i = 0; i < NRECORDS; i++) {
        avgGG += data[i].gg;
        avgBB += data[i].bb;
        avgSM += data[i].sm;

        if (data[i].gg > maxGG) {
            maxGG = data[i].gg;
        }

        if (data[i].sm > maxSM) {
            maxSM = data[i].sm;
        }
        
        if (data[i].bb > maxBB) {
            maxBB = data[i].bb;
        }

        
    }

    avgGG /= NRECORDS;
    avgSM /= NRECORDS;
    avgBB /= NRECORDS;
    
    // Display the output in a table
    cout << fixed << setprecision(2);
    cout << "\nBridge Traffic Statistics" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "Bridge       Average Traffic (Millions)  Max Traffic (Millions)" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "Golden Gate  " << setw(18) << avgGG << "  " << setw(20) << maxGG << endl;
    cout << "San Mateo    " << setw(18) << avgSM << "  " << setw(20) << maxSM << endl;
    cout << "Bay Bridge   " << setw(18) << avgBB << "  " << setw(20) << maxBB << endl;
    cout << "-------------------------------------------------------" << endl;

    return 0;
}