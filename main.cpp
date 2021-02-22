#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <string>

#include "Film.h"

using namespace std;

static vector<Film> SavedFilms;

void mainProgHeader ();

void parentMenu (int&);

void programTerminator (int&);

void mainMenu (int&);

void adminLogin (int&);

void adminMenu (int&);

int main() {

    // Index
    // Program Terminator = -1
    // Parent Menu = 0
    // Main Mode = 1
    // Admin Login = 2
    // Admin Mode = 3


    int MenuSelector;

    if (MenuSelector == -1) {

    }

    else if () {

    }

    else {
        parentMenu (MenuSelector);
    }


}

void mainProgHeader () {

    cout << "\n"
         << " " << "Movie Ticketing System [Version 69.420.666]" << "\n"
         << " " << "(c) 2021 Group 4 | BSIT 1 - 4. All rights reserved." << "\n"
         << endl;
}
