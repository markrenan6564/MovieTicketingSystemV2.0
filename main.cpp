#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <string>

#include "Film.h"

using namespace std;

static vector<Film> SavedFilms;

void mainProgHeader ();

void inpErr();

void parentMenu (int&);

void programTerminator (int&);

void mainMenu (int&);

void adminLogin (int&);

void adminMenu (int&);

int main() {

    // Index
    // menSel = Menu Selector
    // Program Terminator = -1
    // Parent Menu = 0
    // Main Mode = 1
    // Admin Login = 2
    // Admin Mode = 3


    int menSel;

    if (menSel == -1) {
        programTerminator (menSel);
    }

    else if (menSel == 0) {
        parentMenu (menSel);
    }

    else {
        parentMenu (menSel);
    }


}

void mainProgHeader () {

    cout << "\n"
         << " " << "Movie Ticketing System [Version 69.420.666]" << "\n"
         << " " << "(c) 2021 Group 4 | BSIT 1 - 4. All rights reserved." << "\n"
         << endl;
}

void inpErr () {

    cout << " " << "[ERROR] Invalid input. Please enter a valid value" << "\n"
         << endl;
}

void parentMenu (int& menSel) {

    mainProgHeader();

    cout << " " << "HOME >> MODE SELECTION" << "\n"
         << endl;

    cout << " " << "====================================================" << "\n"
         << " " << "[1] Main Mode" << "\n"
         << " " << "[2] Admin Mode" << "\n"
         << " " << "[0] Terminate Program" << "\n"
         << " " << "====================================================" << "\n"
         << endl;

    int menuSel;
    cout << " " << "[INP] Select Mode: ";
    cin >> menuSel;
        while (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n')
            inpErr();
            cout << " " << "[INP] Select Mode: ";
            cin >> menuSel;
        }


}
