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

void progStop ();

void clrscreen();

void parentMenu (int&);

void programTerminator (int&);

void mainMenu (int&);

void adminLogin (int&);

void adminMenu (int&);

int main() {

    // Index
    // menuSelector = Menu Selector
    // Program Terminator = -1
    // Parent Menu = 0
    // Main Mode = 1
    // Admin Login = 2
    // Admin Mode = 3


    int menuSelector;

    while (1) {

        if (menuSelector == -1) {
            programTerminator (menuSelector);
        }

        else if (menuSelector == 0) {
            parentMenu (menuSelector);
        }

        else if (menuSelector == 1) {
            mainMenu (menuSelector);
        }
        else if (menuSelector == 2) {
            adminLogin (menuSelector);
        }

        else {
            parentMenu (menuSelector);
        }

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

void progStop () {

    cin.clear();
    fflush(stdin);
    cout << "[INFO] Press \"Enter\" to continue";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void clrscreen () {

    cout << flush;
    system("cls");

}

void parentMenu (int& menuSelector) {

    mainProgHeader();

    cout << " " << "HOME >> MODE SELECTION" << "\n"
         << endl;

    cout << " " << "====================================================" << "\n"
         << " " << "                   MODE SELECTOR                    " << "\n"
         << " " << "====================================================" << "\n"
         << " " << "[1] Main Mode                                       " << "\n"
         << " " << "[2] Admin Mode                                      " << "\n"
         << " " << "[0] Terminate Program                               " << "\n"
         << " " << "====================================================" << "\n"
         << endl;

    while (1) {

        int input;
        cout << " " << "[INPUT] Select Mode: ";
        cin >> input;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            inpErr();
            cout << " " << "[INPUT] Select Mode: ";
            cin >> input;
        }

        if (input == 1) {

            clrscreen ();
            menuSelector = 1;
            break;
        }

        else if (input == 2) {

            clrscreen ();
            menuSelector = 2;
            break;
        }

        else if (input == 0) {

            clrscreen ();
            menuSelector = -1;
            break;
        }

        else {

            inpErr ();
        }

    }
}

void programTerminator (int& menuSelector) {

    mainProgHeader();

    cout << " " << "HOME >> MODE SELECTION >> PROGRAM TERMINATION" << "\n"
         << endl;

    cout << " " << "====================================================" << "\n"
         << " " << "                  TERMINATE PROGRAM                 " << "\n"
         << " " << "====================================================" << "\n"
         << " " << "[1] Terminate Program                               " << "\n"
         << " " << "[2] Cancel Termination                              " << "\n"
         << " " << "====================================================" << "\n"
         << endl;

    while (1) {

        int userinput;
        cout << " " << "[INPUT] Select Options: ";
        cin >> userinput;
            while (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                inpErr();
                cout << " " << "[INPUT] Select Options: ";
                cin >> userinput;
            }
        if (userinput == 1) {
            exit(1);
        }
        if (userinput == 2) {

            clrscreen();
            menuSelector = 0;
            break;
        }
        else{
            inpErr();
        }

    }

}

void mainMenu (int& menuSelector) {

    mainProgHeader();
    cout << " " << "HOME >> MODE SELECTION >> MAIN MODE" << "\n"
         << endl;

    cout << " " << "====================================================" << "\n"
         << " " << "                      MAIN MODE                     " << "\n"
         << " " << "====================================================" << "\n"
         << " " << "[ERROR] Program under development. :<               " << "\n"
         << " " << "[0] Mode Selection                                  " << "\n"
         << " " << "====================================================" << "\n"
         << endl;

    while (1) {

        int userInput;
        cout << " " << "[INPUT] Select Options: ";
        cin >> userInput;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            inpErr ();
            cout << " " << "[INPUT] Select Options: ";
            cin >> userInput;
        }
        if (userInput == 0) {

            clrscreen();
            menuSelector = 0;
            break;

        }
        else {
            inpErr();
        }
    }
}

void adminLogin (int& menuSelector) {

    mainProgHeader ();

    cout << " " << "HOME >> MODE SELECTION >> ADMIN LOGIN" << "\n"
         << endl;

    cout << " " << "====================================================" << "\n"
         << " " << "                    ADMIN LOGIN                     " << "\n"
         << " " << "====================================================" << "\n"
         << " " << "[1] Log In                                          " << "\n"
         << " " << "[0] Mode Selection                                  " << "\n"
         << " " << "====================================================" << "\n"
         << endl;

    while (1){
        int userInput;
        cout << " " << "[INPUT] Select Option: ";
        cin >> userInput;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                inpErr();
                cout << " " << "[INPUT] Select Option: ";
                cin >> userInput;
            }
        if (userInput == 1) {

            clrscreen();

        }
        else if (userInput == 0) {

            clrscreen();
            menuSelector = 0;
            break;
        }

        else {
            inpErr();
        }
    }


}


