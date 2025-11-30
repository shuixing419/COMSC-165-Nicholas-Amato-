#include <iostream>
#include <string>
#include "time.h"

using namespace std;

// Function to shuffle the playlist
void shufflePlaylist(string* playlist, int size) {
    srand(time(0));
    for (int i = size - 1; i > 0; i--) {
        int swapidx = rand() % (i + 1);
        string tmp = playlist[i];
        playlist[i] = playlist[swapidx];
        playlist[swapidx] = tmp;
    }
}

// Function to show the playlist
void showPlaylist(string* playlist, int size) {
    cout << "\nCurrent Playlist\n----------------\n";
    for (int i = 0; i < size; i++) {
        cout << playlist[i] << endl;
    }
}

int main() {
    string* playlist = nullptr;
    int size = 0;
    int choice;

    do {
        cout << "\nMenu\n1) Create playlist\n2) Shuffle playlist\n3) Show playlist\n4) Quit\nYour choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (playlist != nullptr) {
                    delete[] playlist;
                }
                cout << "How many songs in the playlist: ";
                cin >> size;
                cin.ignore();
                playlist = new string[size];
                for (int i = 0; i < size; i++) {
                    cout << "Enter song # " << (i + 1) << ": ";
                    getline(cin, playlist[i]);
                }
                break;
            case 2:
                shufflePlaylist(playlist, size);
                cout << "Shuffling...\n";
                break;
            case 3:
                showPlaylist(playlist, size);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please choose again.\n";
        }
    } while (choice != 4);

    if (playlist != nullptr) {
        delete[] playlist;
    }

    return 0;
}
