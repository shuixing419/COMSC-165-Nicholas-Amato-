#include <iostream>
#include <map>
#include <string>
#include <limits>
using namespace std;
class AddressBook {
private:
    std::map<std::string, std::string> addressMap;

public:
    void addAddress(const std::string& name, const std::string& email) {
        addressMap[name] = email;
        std::cout << "Added 1 entry (new total: " << addressMap.size() << ")\n";
    }

    void removeAddress(const std::string& name) {
        auto it = addressMap.find(name);
        if (it != addressMap.end()) {
            addressMap.erase(it);
            std::cout << "Deleted 1 entry (new total: " << addressMap.size() << ")\n";
        } else {
            std::cout << "Name not found. No entry deleted.\n";
        }
    }

    void searchAddress(const std::string& name) {
        auto it = addressMap.find(name);
        if (it != addressMap.end()) {
            std::cout << "Name: " << it->first << "\n";
            std::cout << "Address: " << it->second << "\n";
        } else {
            std::cout << "Name not found.\n";
        }
    }
};

int main() {
    AddressBook addressBook;
    int choice;

    do {
        std::cout << "Menu\n----\n";
        std::cout << "1) Add an email address\n";
        std::cout << "2) Remove an email address\n";
        std::cout << "3) Search for an address with a name\n";
        std::cout << "4) Exit\n";
        std::cout << "Your choice: ";

        if (!(std::cin >> choice)) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard the rest of the line
            std::cout << "Invalid choice. Please try again.\n";
            continue; // skip the rest of the loop
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard the rest of the line

        switch (choice) {
            case 1: {
                std::string name, email;
                std::cout << "Enter the name: ";
                std::getline(std::cin, name);
                std::cout << "Enter their email address: ";
                std::getline(std::cin, email);
                addressBook.addAddress(name, email);
                break;
            }
            case 2: {
                std::string nameToRemove;
                std::cout << "Enter the name to remove: ";
                std::getline(std::cin, nameToRemove);
                addressBook.removeAddress(nameToRemove);
                break;
            }
            case 3: {
                std::string nameToSearch;
                std::cout << "Enter the name to find: ";
                std::getline(std::cin, nameToSearch);
                addressBook.searchAddress(nameToSearch);
                break;
            }
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
