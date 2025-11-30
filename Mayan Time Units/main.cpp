// 1 kin    = 1 day
    // 1 uinal  = 20 kin (20 days)
    // 1 tun    = 18 uinal (360 days)
    // 1 baktun = 20 katun (144,000 days)
    // 1 pictun = 20 baktun ( 2,880,000 days)

#include <iostream>
using namespace std;

const int KIN = 1;
const int UINAL = 20 * KIN;
const int TUN = 18 * UINAL;
const int KATUN = 20 * TUN;
const int BAKTUN = 20 * KATUN;
const int PICTUN = 20 * BAKTUN;

int mayanUnitsToDays(int kin, int uinal, int tun, int katun, int baktun, int pictun) {
    // Calculate and return the total number of days
    return kin*KIN + uinal *UINAL+ tun *TUN+ katun*KATUN + baktun*BAKTUN + pictun*PICTUN;
}
void daysToMayaUnits(int days,
                     int &kin, int &uinal, int &tun,
                     int &katun, int &baktun, int &pictun) {
    // Initialize all the variables to zero
    pictun = katun = baktun = uinal = tun = kin = 0;

    // Perform the conversion
    if (days >= PICTUN) {
        pictun = days / PICTUN;
        days -= pictun * PICTUN;
    }
    if (days >= KATUN) {
        katun = days / KATUN;
        days -= katun * KATUN;
    }
    if (days >= BAKTUN) {
        baktun = days / BAKTUN;
        days -= baktun * BAKTUN;
    }
    if (days >= UINAL) {
        uinal = days / UINAL;
        days -= uinal * UINAL;
    }
    if (days >= TUN) {
        tun = days / TUN;
        days -= tun * TUN;
    }
    kin = days; // Whatever remains is the number of kin
}
int main(){
             int choice;
    do {
              cout << "Menu" << endl;
              cout << "----" << endl;
              cout << "1. Convert Mayan time units to days" << endl;
              cout << "2. Convert days to Mayan time units" << endl;
              cout << "3. Exit" << endl;
              cout << "Your choice? ";
              cin >> choice;
 switch (choice) {
            case 1:
                int kin, uinal, tun, katun, baktun, pictun;
                cout << "Number of kin? ";
                cin >> kin;
                cout << "Number of uinal? ";
                cin >> uinal;
                cout << "Number of tun? ";
                cin >> tun;
                cout << "Number of katun? ";
                cin >> katun;
                cout << "Number of baktun? ";
                cin >> baktun;
                cout << "Number of pictun? ";
                cin >> pictun;

                cout << "This set of time units represents: " <<mayanUnitsToDays(kin, uinal, tun, katun, baktun, pictun) << " days." << endl;
                break;

            case 2:
                int days;
                cout << "Enter the number of days: ";
                cin >> days;
                daysToMayaUnits(days, kin, uinal, tun, katun, baktun, pictun);
                cout << "The conversion is:" << endl;
                cout << "    " << kin << " kin" << endl;
                cout << "    " << uinal << " uinal" << endl;
                cout << "    " << tun << " tun" << endl;
                cout << "    " << katun << " katun" << endl;
                cout << "    " << baktun << " baktun" << endl;
                cout << "    " << pictun << " pictun" << endl;
                break;

            case 3:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
