#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <string>

#include "Film.h"


using namespace std;

static vector<Film> SavedFilms;

// Funtion Declarations

    void mainProgHeader ();
    void inpErr();
    void inpError();
    void progStop ();
    void clrscreen();
    void cinError();
    void parentMenu (int&);
    void programTerminator (int&);
    void mainMenu (int&);
    void adminLogin (int&);
    void adminMenu (int&);
    void manageFilms (int&);
    void addFilms (int&, vector<Film>&);
    void viewFilms (int&, vector<Film>&);
    void editFilms (int&, vector<Film>&);
    void deactivateFilms (int&, vector<Film>&);
    void reactivateFilms (int&, vector<Film>&);
    void deleteFilms (int&, vector<Film>&);

int main() {

/*

    INDEX for Menu Selector
    A comprehensive guide by Mark Renan

        Program Terminator = -1

        ParentMenu = 0
            Main Mode = 1
                Book Ticket = 11
                Buy Movie Snacks = 12


            Admin Login = 2 | Page before going to Admin

                Admin Mode = 3
                    Manage Films = 31
                        Add Films = 311
                        View Films = 312
                        Edit Films = 313
                        Deactivate Films = 314
                        Reactivate Films = 315
                        Delete Films = 316

                    Manage Snacks = 32
                        Add Snacks = 321
                        View Snacks = 322
                        Edit Snacks = 323
                        Deactivate Snacks = 324
                        Reactivate Snacks = 325
                        Delete Snacks = 326

                    Sales = 33
                        View Sales = 331

*/

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

        else if (menuSelector == 3) {
            adminMenu (menuSelector);
        }

        else if (menuSelector == 31) {
            manageFilms (menuSelector);
        }

        else if (menuSelector == 311) {
            addFilms (menuSelector, SavedFilms);
        }

        else if (menuSelector == 312) {
            viewFilms (menuSelector, SavedFilms);
        }

        else if (menuSelector == 313) {
            editFilms (menuSelector, SavedFilms);
        }

        else if (menuSelector == 314) {
            deactivateFilms (menuSelector, SavedFilms);
        }

        else if (menuSelector == 315) {
            reactivateFilms (menuSelector, SavedFilms);
        }

        else if (menuSelector == 316) {
            deleteFilms (menuSelector, SavedFilms);
        }

        else {
            parentMenu (menuSelector);
        }

    }
}

void mainProgHeader () {

    cout << "\n"
         << " " << "Movie Ticketing System [Version 69.420.666]" << "\n"
         << " " << "(c) 2021 Group 4 | BSIT 1-4. All rights reserved." << "\n"
         << endl;

}

void inpErr () {

    cout << " " << "[ERR] Invalid input. Please enter a valid value" << "\n"
         << endl;
}

void inpError () {

    cout << " " << "[ERR] Invalid input. Please enter a valid value" << "\n";
}

void progStop () {

    cin.clear();
    fflush(stdin);
    cout <<" " << "[SYS] Press \"Enter\" to continue";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void clrscreen () {

    cout << flush;
    system("cls");

}

void cinError () {

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void parentMenu (int& menuSelector) {

    mainProgHeader();

    cout << " " << "HOME" << "\n";

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
        cout << " " << "[INP] Select Mode: ";
        cin >> input;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            inpErr();
            cout << " " << "[INP] Select Mode: ";
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

    cout << " " << "HOME >> PROGRAM TERMINATION" << "\n";

    cout << " " << "====================================================" << "\n"
         << " " << "                  TERMINATE PROGRAM                 " << "\n"
         << " " << "====================================================" << "\n"
         << " " << "[1] Terminate Program                               " << "\n"
         << " " << "[0] Cancel Termination                              " << "\n"
         << " " << "====================================================" << "\n"
         << endl;

    while (1) {

        int userinput;
        cout << " " << "[INP] Select Option: ";
        cin >> userinput;
            while (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                inpErr();
                cout << " " << "[INP] Select Option: ";
                cin >> userinput;
            }
        if (userinput == 1) {
            exit(1);
        }
        if (userinput == 0) {

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
    cout << " " << "HOME >> MAIN MODE" << "\n";

    cout << " " << "====================================================" << "\n"
         << " " << "                      MAIN MODE                     " << "\n"
         << " " << "====================================================" << "\n"
         << " " << "[ERR] Program under development. :<               " << "\n"
         << " " << "[0] Mode Selection                                  " << "\n"
         << " " << "====================================================" << "\n"
         << endl;

    while (1) {

        int userInput;
        cout << " " << "[INP] Select Option: ";
        cin >> userInput;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            inpErr ();
            cout << " " << "[INP] Select Option: ";
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

    cout << " " << "HOME >> ADMIN LOGIN" << "\n";

    cout << " " << "====================================================" << "\n"
         << " " << "                    ADMIN LOGIN                     " << "\n"
         << " " << "====================================================" << "\n"
         << " " << "[1] Log In                                          " << "\n"
         << " " << "[0] Mode Selection                                  " << "\n"
         << " " << "====================================================" << "\n"
         << endl;

    while (1){
        int userInput;
        cout << " " << "[INP] Select Option: ";
        cin >> userInput;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                inpErr();
                cout << " " << "[INP] Select Option: ";
                cin >> userInput;
            }
        if (userInput == 1) {

            clrscreen();

            mainProgHeader ();

            cout << " " << "HOME >> ADMIN LOGIN" << "\n";

            cout << " " << "====================================================" << "\n"
                 << " " << "                    ADMIN LOGIN                     " << "\n"
                 << " " << "====================================================" << "\n";

            string username, password;

            cin.clear();
            fflush(stdin);

            cout << " " << "USERNAME: ";
            getline(cin, username);
            cout << " " << "PASSWORD: ";
            getline (cin, password);

            cout << " " << "====================================================" << "\n"
                 << endl;

                if ((username == "admin") && (password == "password")) {


                    cout << " " << "----------------------------------------------------" << "\n"
                         << " " << "[INF] Login Successful" << "\n"
                         << " " << "----------------------------------------------------" << "\n"
                         << endl;

                    progStop();
                    clrscreen ();
                    menuSelector = 3;
                }
                else {

                    cout << " " << "----------------------------------------------------" << "\n"
                         << " " << "[ERR] Login Unsuccessful | Wrong Credentials" << "\n"
                         << " " << "----------------------------------------------------" << "\n"
                         << endl;

                    progStop ();
                    clrscreen();
                    menuSelector = 2;
                }

            break;
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

void adminMenu (int& menuSelector) {

    mainProgHeader();

    cout << " " << "HOME >> ADMIN MODE" << "\n";

    cout << " " << "====================================================" << "\n"
         << " " << "                     ADMIN MODE                     " << "\n"
         << " " << "====================================================" << "\n"
         << " " << "[1] Manage Films                                    " << "\n"
         << " " << "[2] Manage Snacks                                   " << "\n"
         << " " << "[3] Sales                                           " << "\n"
         << " " << "[0] Mode Selection                                  " << "\n"
         << " " << "====================================================" << "\n"
         << endl;

    while (1) {
        int userInput;
        cout << " " << "[INP] Select Option: ";
        cin >> userInput;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            inpErr();
            cout << " " << "[INP] Select Option: ";
            cin >> userInput;
        }
        if (userInput == 1){

            clrscreen();
            menuSelector = 31;
            break;
        }
        else if (userInput == 2) {

            clrscreen();
            menuSelector = 32;
            break;
        }
        else if (userInput == 3) {

            clrscreen();
            menuSelector = 33;
            break;
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

void manageFilms (int& menuSelector) {

    mainProgHeader();

    cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS" << "\n";

    cout << " " << "====================================================" << "\n"
         << " " << "                    MANAGE FILMS                    " << "\n"
         << " " << "====================================================" << "\n"
         << " " << "[1] Add Films                                       " << "\n"
         << " " << "[2] View Films                                      " << "\n"
         << " " << "[3] Edit Films                                      " << "\n"
         << " " << "[4] Deactivate Films                                " << "\n"
         << " " << "[5] Reactivate Films                                " << "\n"
         << " " << "[6] Delete Films                                    " << "\n"
         << " " << "[0] Admin Mode                                      " << "\n"
         << " " << "====================================================" << "\n"
         << endl;

    while(1) {
        int userInput;
        cout << " " << "[INP] Select Option: ";
        cin >> userInput;
            while(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                inpErr ();
                cout << " " << "[INP] Select Option: ";
                cin >> userInput;
            }
        if (userInput == 1) {

            clrscreen();
            menuSelector = 311;
            break;
        }
        else if (userInput == 2) {

            clrscreen();
            menuSelector = 312;
            break;
        }
        else if (userInput == 3) {

            clrscreen();
            menuSelector = 313;
            break;
        }
        else if (userInput == 4) {

            clrscreen();
            menuSelector = 314;
            break;
        }
        else if (userInput == 5) {

            clrscreen();
            menuSelector = 315;
            break;
        }
        else if (userInput == 6) {

            clrscreen();
            menuSelector = 316;
            break;
        }
        else if (userInput == 0) {

            clrscreen();
            menuSelector = 3;
            break;
        }
        else {
            inpErr();
        }
    }
}

void addFilms(int& menuSelector, vector<Film>& CurrentFilms) {

    mainProgHeader();

    cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> ADD FILMS" << "\n";

    cout << " " << "====================================================" << "\n"
         << " " << "                      ADD FILMS                     " << "\n"
         << " " << "====================================================" << "\n"
         << endl;

    int usernum;
    cout << " " << "[INP] Specify number of films to add: ";
    cin >> usernum;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        inpErr();
        cout << " " << "[INP] Specify number of films to add: ";
        cin >> usernum;
        }

    cout << "\n"
         << " " << "----------------------------------------------------" << "\n"
         << " " << "[INF] You requested to add " << usernum << " films" << "\n"
         << " " << "----------------------------------------------------" << "\n"
         << "\n"
         << " " << "====================================================" << "\n"
         << endl;

    progStop();
    clrscreen();

    string title;
    string director;
    int year;
    int price;
    int seats;

        for (int i = 1; i <= usernum; i++) {

            mainProgHeader();

            cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> ADD FILMS" << "\n";

            cout << " " << "====================================================" << "\n"
                 << " " << "                      ADD FILMS                     " << "\n"
                 << " " << "====================================================" << "\n"
                 << endl;

            cout << " " << "----------------------------------------------------" << "\n"
                 << " " << "[INP] Adding " << i << " out of " << usernum << " films" << "\n"
                 << " " << "----------------------------------------------------" << endl;

            cout << " " << "Film Title     : ";
            getline(cin, title);
            cout << " " << "Film Director  : ";
            getline (cin, director);
            cout << " " << "Year Released  : ";
            cin >> year;
                while(cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    inpError();
                    cout << " " << "Year Released  : ";
                    cin >> year;
                }
            cout << " " << "Ticket Price   : ";
            cin >> price;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    inpError();
                    cout << " " << "Ticket Price   : ";
                    cin >> price;
                }
            cout << " " << "Alloted Seats  : ";
            cin >> seats;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    inpError();
                    cout << " " << "Available Seats: ";
                    cin >> seats;
                }

            Film films(title, director, year, price, seats);
            CurrentFilms.push_back(films);

            cout << " " << "----------------------------------------------------" << "\n"
                 << "\n"
                 << " " << "====================================================" << "\n"
                 << "\n"
                 << " " << "----------------------------------------------------" << "\n"
                 << " " << "[INF] Entry No. " << i << " has been successfully saved" << "\n"
                 << " " << "----------------------------------------------------" << "\n"
                 << endl;

            progStop ();
            clrscreen ();

        }

        mainProgHeader();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> ADD FILMS" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                      ADD FILMS                     " << "\n"
             << " " << "====================================================" << "\n"
             << "\n"
             << " " << "----------------------------------------------------" << "\n"
             << " " << "[INF] Successfuly added " << usernum << " films" << "\n"
             << " " << "----------------------------------------------------" << "\n"
             << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        progStop();
        clrscreen();
        menuSelector = 31;
}

void viewFilms (int& menuSelector, vector<Film>& addedFilms) {

    if (addedFilms.empty()) {

        mainProgHeader ();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> VIEW FILMS" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                     VIEW FILMS                     " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[ERR] No films to view                              " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        progStop();
        clrscreen();
        menuSelector = 31;

    }

    else {

        mainProgHeader ();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> VIEW FILMS" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                     VIEW FILMS                     " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[1] View All                                        " << "\n"
             << " " << "[2] View Specific                                   " << "\n"
             << " " << "[0] Manage Films                                    " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        while (1) {

            int userInput;
            cout << " " << "[INP] Select Option: ";
            cin >> userInput;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    inpErr();
                    cout << " " << "[INP] Select Option: ";
                    cin >> userInput;
                }

            if (userInput == 1) {

                clrscreen();
                mainProgHeader ();

                cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> VIEW FILMS >> VIEW ALL" << "\n";

                cout << " " << "====================================================" << "\n"
                      << " " << "                     VIEW FILMS                     " << "\n"
                      << " " << "====================================================" << "\n"
                      << "\n"
                      << " " << "----------------------------------------------------" << "\n"
                      << " " << "[INF] Showing all saved films                     " << "\n"
                      << " " << "----------------------------------------------------" << "\n"
                       << endl;

                int vectorSize = addedFilms.size();

                for (int i = 0; i < vectorSize ; i++) {

                    int filmctr = i + 1;

                    cout << " " << "----------------------------------------------------" << "\n"
                         << " " << "[" << filmctr << "] Title : " << addedFilms[i].getTitle() << "\n";

                    if (addedFilms[i].getStatus()) {
                         cout << " " << "    Status: Active" << "\n";
                    }

                    else {
                        cout << " " << "    Status: Inactive" << "\n";
                    }

                    cout << " " << "----------------------------------------------------" << "\n"
                         << " " << "Film Title    : " << addedFilms[i].getTitle() << "\n"
                         << " " << "Film Director : " << addedFilms[i].getDirector() << "\n"
                         << " " << "Year Released : " << addedFilms[i].getYear() << "\n"
                         << " " << "Ticket Price  : " << addedFilms[i].getPrice() << "\n"
                         << " " << "Seats Alloted : " << addedFilms[i].getSeats() << "\n"
                         << " " << "----------------------------------------------------" << "\n"
                         << endl;

                }

                cout << " " << "====================================================" << "\n"
                     << endl;

                progStop();
                clrscreen();
                menuSelector = 312;
                break;

            }

            else if (userInput == 2) {

                clrscreen();
                mainProgHeader ();

                cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> VIEW FILMS >> VIEW SPECIFIC" << "\n";

                cout << " " << "====================================================" << "\n"
                     << " " << "                     VIEW FILMS                     " << "\n"
                     << " " << "====================================================" << "\n"
                     << "\n"
                     << " " << "----------------------------------------------------" << "\n"
                     << " " << "[INF] Showing all film titles" << "\n"
                     << " " << "----------------------------------------------------" << "\n"
                     << endl;

                int vectorSize = addedFilms.size();

                for (int i = 0; i < vectorSize; i++) {

                    int filmctr = i + 1;

                    cout << " " << "----------------------------------------------------" << "\n"
                         << " " << "[" << filmctr << "] Title: " << addedFilms[i].getTitle() << "\n";
                    if (addedFilms[i].getStatus()) {
                        cout << " " << "    Status: Active" << "\n";
                    }
                    else {
                        cout << " " << "    Status: Inactive" << "\n";
                    }
                    cout << " " << "----------------------------------------------------" << "\n"
                         << endl;
                }

                cout << " " << "====================================================" << "\n"
                     << endl;

                while (1) {

                    int choice;
                    cout << " " << "[INP] Select film using reference number: ";
                    cin >> choice;
                    while (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        inpErr();
                        cout << " " << "[INP] Select film using reference number: ";
                        cin >> choice;
                    }

                    int movienum = choice - 1;

                    if ((0 < choice) && (movienum < addedFilms.size())) {

                        cout << "\n"
                             << " " << "====================================================" << "\n"
                             << endl;

                        cout << " " << "----------------------------------------------------" << "\n";
                        cout << " " << "[" << choice << "] Title: " << addedFilms[movienum].getTitle() << "\n";
                        if (addedFilms[movienum].getStatus()) {
                            cout << " " << "    Status: Active" << "\n";
                        }
                        else {
                            cout << " " << "    Status: Inactive" << "\n";
                        }
                        cout << " " << "----------------------------------------------------" << "\n"
                             << " " << "Film Title    : " << addedFilms[movienum].getTitle() << "\n"
                             << " " << "Film Director : " << addedFilms[movienum].getDirector() << "\n"
                             << " " << "Year Released : " << addedFilms[movienum].getYear() << "\n"
                             << " " << "Ticket Price  : " << addedFilms[movienum].getPrice() << "\n"
                             << " " << "Seats Alloted : " << addedFilms[movienum].getSeats() << "\n"
                             << " " << "----------------------------------------------------" << "\n"
                             << "\n"
                             << " " << "====================================================" << "\n"
                             << endl;


                        progStop ();
                        menuSelector = 312;
                        clrscreen ();
                        break;

                    }
                        else {

                            inpErr();

                        }

                }

                break;

            }

            else if (userInput == 0) {

                menuSelector = 31;
                clrscreen ();
                break;

            }

            else {

                inpErr();

            }

        }

    }

}

void editFilms (int& menuSelector, vector<Film>& currentFilms) {

    if (currentFilms.empty()) {

        mainProgHeader ();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> EDIT FILMS" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                    EDIT FILMS                      " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[ERR] No films to edit     " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        progStop();
        clrscreen();
        menuSelector = 31;

    } // 1st if  closing parethesis

    else {

        mainProgHeader ();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> EDIT FILMS" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                     EDIT FILMS                     " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[1] Edit Film Details                               " << "\n"
             << " " << "[0] Manage Films                                    " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        int userChoice;

        cout << " " << "[INP] Select Option: ";
        cin >> userChoice;

        while (cin.fail()) {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            inpErr();
            cout << " " << "[INP] Select Option: ";
            cin >> userChoice;

        } // Input checker

        while (1) {

            if (userChoice == 1) {

                clrscreen();
                mainProgHeader();

                cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> EDIT FILMS" << "\n";

                cout << " " << "====================================================" << "\n"
                     << " " << "                     EDIT FILMS                     " << "\n"
                     << " " << "====================================================" << "\n"
                     << "\n"
                     << " " << "[INF] Showing all editable films" << "\n"
                     << endl;

                int filmsNum = currentFilms.size();

                for (int i = 0; i < filmsNum; i++) {

                    int refnumber = i + 1;

                    cout << " " << "----------------------------------------------------" << "\n"
                         << " " << "[" << refnumber << "] Title  : " << currentFilms[i].getTitle() << "\n";

                    if (currentFilms[i].getStatus()) {
                        cout << " " << "    Status : Active" << "\n";
                    }

                    else {
                        cout << " " << "    Status : Inactive" << "\n";
                    }

                    cout << " " << "----------------------------------------------------" << "\n"
                         << " " << "Film Title    : " << currentFilms[i].getTitle() << "\n"
                         << " " << "Film Director : " << currentFilms[i].getDirector() << "\n"
                         << " " << "Year Released : " << currentFilms[i].getYear() << "\n"
                         << " " << "Ticket Price  : " << currentFilms[i].getPrice() << "\n"
                         << " " << "Seats Alloted : " << currentFilms[i].getSeats() << "\n"
                         << " " << "----------------------------------------------------" << "\n"
                         << endl;

                } // For showing all films

                cout << " " << "====================================================" << "\n"
                     << endl;

                while (1) {

                    int userChoice;

                    cout << " " << "[INP] Select film to edit: ";
                    cin >> userChoice;

                    while (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        inpErr();
                        cout << " " << "[INP] Select film to edit: ";
                        cin >> userChoice;
                    }

                    if ((userChoice > 0) && (userChoice <= currentFilms.size())) {

                        int realref = userChoice - 1;

                        string title, director;
                        int year, price, seats;

                        cout << "\n"
                             << " " << "----------------------------------------------------" << "\n"
                             << " " << "[INF] You're going to edit film number " << userChoice << "\n"
                             << " " << "----------------------------------------------------" << "\n"
                             << "\n"
                             << " " << "====================================================" << "\n"
                             << endl;

                        cout << " " << "[INF] Showing film current details" << "\n";

                        cout << " " << "----------------------------------------------------" << "\n"
                             << " " << "[" << userChoice << "] Title  : " << currentFilms[realref].getTitle() << "\n";

                        if (currentFilms[realref].getStatus()) {
                            cout << " " << "    Status : Active" << "\n";
                        }

                        else {
                            cout << " " << "    Status : Inactive" << "\n";
                        }

                        cout << " " << "----------------------------------------------------" << "\n"
                             << " " << "Film Title    : " << currentFilms[realref].getTitle() << "\n"
                             << " " << "Film Director : " << currentFilms[realref].getDirector() << "\n"
                             << " " << "Year Released : " << currentFilms[realref].getYear() << "\n"
                             << " " << "Ticket Price  : " << currentFilms[realref].getPrice() << "\n"
                             << " " << "Seats Alloted : " << currentFilms[realref].getSeats() << "\n"
                             << " " << "----------------------------------------------------" << "\n"
                             << "\n"
                             << " " << "====================================================" << "\n"
                             << endl;

                        cout << " " << "[INP] Please enter new details " << "\n";

                        cout << " " << "----------------------------------------------------" << "\n"
                             << " " << "[" << userChoice << "] Title  : " << currentFilms[realref].getTitle() << "\n";

                        if (currentFilms[realref].getStatus()) {
                            cout << " " << "    Status : Active" << "\n";
                        }

                        else {
                            cout << " " << "    Status : Inactive" << "\n";
                        }

                        cout << " " << "----------------------------------------------------" << "\n";

                        cin.ignore();

                        cout << " " << "Film Title    : ";
                        getline(cin, title);
                        currentFilms[realref].setTitle(title);

                        cout << " " << "Film Director : ";
                        getline(cin, director);
                        currentFilms[realref].setDirector(director);

                        cout << " " << "Year Released : ";
                        cin >> year;
                            while (cin.fail()) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                inpError();
                                cout << " " << "Year Released : ";
                                cin >> year;
                            }
                        currentFilms[realref].setYear(year);

                        cout << " " << "Ticket Price  : ";
                        cin >> price;
                            while (cin.fail()) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                inpError();
                                cout << " " << "Ticket Price  : ";
                                cin >> price;
                            }
                        currentFilms[realref].setPrice(price);

                        cout << " " << "Alloted Seats : ";
                        cin >> seats;
                            while (cin.fail()) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                inpError();
                                cout << " " << "Alloted Seats : ";
                                cin >> seats;
                            }
                        currentFilms[realref].setSeats(seats);

                        cout << " " << "----------------------------------------------------" << "\n"
                             << "\n"
                             << " " << "====================================================" << "\n"
                             << endl;

                        cout << " " << "----------------------------------------------------" << "\n"
                             << " " << "[INF] Changes to film  has been successfully saved" << "\n"
                             << " " << "----------------------------------------------------" << "\n"
                             << endl;

                        progStop();
                        break;

                    }

                    else {
                        inpErr();
                    }

                } // While loop for verifying choice from ref

                clrscreen();
                menuSelector = 313;
                break;

            } // For Editing Film Details | needs break

            else if (userChoice == 0) {

                clrscreen();
                menuSelector = 31;
                break;

            } // For going back to menu | needs break

            else {

                inpErr();

            } // When user enter a wrong input, this condition will ask it again

        } // while loop for menu selection

    } // If there is already instance of film existing

} // Function closing parenthesis

void deactivateFilms (int& menuSelector, vector<Film>& activeFilms) {

    if (activeFilms.empty()) {

        mainProgHeader ();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> DEACTIVATE FILMS" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                  DEACTIVATE FILMS                  " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[ERR] No films to deactivate                        " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        progStop();
        clrscreen();
        menuSelector = 31;

    }

    else {

        mainProgHeader ();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> DEACTIVATE FILMS" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                  DEACTIVATE FILMS                  " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[1] Deactivate Film                                 " << "\n"
             << " " << "[0] Manage Films                                    " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        while (1) {

            int usersChoice;

            cout << " " << "[INP] Select Option: ";
            cin >> usersChoice;
                while (cin.fail()) {
                    cinError();
                    inpErr();
                    cout << " " << "[INP] Select Option: ";
                    cin >> usersChoice;
                }

            if (usersChoice ==  1) {

                int numAct = 0;

                for (unsigned int i = 0; i < activeFilms.size(); i++) {

                    if (activeFilms[i].getStatus()){
                        numAct++;
                    }

                }

                if (numAct == 0) {

                            clrscreen();
                            mainProgHeader();

                            cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> DEACTIVATE FILMS" << "\n";

                            cout << " " << "====================================================" << "\n"
                                 << " " << "                  DEACTIVATE FILMS                  " << "\n"
                                 << " " << "====================================================" << "\n"
                                 << " " << "[ERR] No films to deactivate" << "\n"
                                 << " " << "====================================================" << "\n"
                                 << endl;

                            progStop();
                            clrscreen();
                            menuSelector = 314;
                            break;

                }

                else {

                    clrscreen();

                    mainProgHeader ();

                    cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> DEACTIVATE FILMS" << "\n";

                    cout << " " << "====================================================" << "\n"
                         << " " << "                  DEACTIVATE FILMS                  " << "\n"
                         << " " << "====================================================" << "\n"
                         << endl;

                    cout << " " << "----------------------------------------------------" << "\n"
                        << " " << "[SYS] Showing all active films" << "\n"
                        << " " << "----------------------------------------------------" << "\n"
                        << endl;

                    int numFilms = activeFilms.size();

                    for (int realRef = 0; realRef < numFilms; realRef++) {

                        int filmRef = realRef + 1;

                        if (!activeFilms[realRef].getStatus()) {
                            continue;
                        }

                        else {

                            cout << " " << "----------------------------------------------------" << "\n"
                                << " " << "[";

                            if (realRef < 9) {

                                cout << "0" << filmRef << "] Title         : " << activeFilms[realRef].getTitle() << "\n"
                                << " " << "     Status        : Active                                 " << "\n"
                                << " " << "----------------------------------------------------" << "\n"
                                << " " << "     Film Title    : " << activeFilms[realRef].getTitle() << "\n"
                                << " " << "     Film Director : " << activeFilms[realRef].getDirector() << "\n"
                                << " " << "     Year Released : " << activeFilms[realRef].getYear() << "\n"
                                << " " << "     Ticket Price  : " << activeFilms[realRef].getPrice() << "\n"
                                << " " << "     Seats Alloted : " << activeFilms[realRef].getSeats() << "\n"
                                << " " << "----------------------------------------------------" << "\n"
                                << endl;

                            }

                            else {

                                cout << filmRef << "] Title         : " << activeFilms[realRef].getTitle() << "\n"
                                    << " " << "     Status        : Active                                 " << "\n"
                                    << " " << "----------------------------------------------------" << "\n"
                                    << " " << "     Film Title    : " << activeFilms[realRef].getTitle() << "\n"
                                    << " " << "     Film Director : " << activeFilms[realRef].getDirector() << "\n"
                                    << " " << "     Year Released : " << activeFilms[realRef].getYear() << "\n"
                                    << " " << "     Ticket Price  : " << activeFilms[realRef].getPrice() << "\n"
                                    << " " << "     Seats Alloted : " << activeFilms[realRef].getSeats() << "\n"
                                    << " " << "----------------------------------------------------" << "\n"
                                    << endl;

                            }

                        }

                    }

                    cout << " " << "====================================================" << "\n"
                        << endl;

                    while (1) {

                        int userChoice;

                        cout << " " << "[INP] Select a Film for Deactivation: ";
                        cin >> usersChoice;
                        while (cin.fail()) {
                            cinError();
                            inpErr();
                            cout << " " << "[INP] Select a Film for Deactivation: ";
                            cin >> usersChoice;
                        }

                        int realRef = usersChoice - 1;

                        if ((usersChoice > 0) && (usersChoice <= activeFilms.size()) && (activeFilms[realRef].getStatus())) {

                            cout << " " << "[INF] The Film \"" << activeFilms[realRef].getTitle() << "\" has been selected" << "\n"
                                 << "\n"
                                 << " " << "====================================================" << "\n"
                                 << endl;

                            activeFilms[realRef].setStatus(false);

                            cout << " " << "[SYS] The Film \"" << activeFilms[realRef].getTitle() << "\" has been deactivated" << "\n";

                            progStop();
                            clrscreen();
                            break;

                        }

                        else {

                            inpErr();

                        }

                    }

                    menuSelector = 314;
                    break;

                }

            }

            else if (usersChoice == 0) {

                clrscreen();
                menuSelector = 31;
                break;

            }

            else {

                inpErr();

            }

        } // while statement

    } // else statement

} // function

void reactivateFilms (int& menuSelector, vector<Film>& inactiveFilms) {

    if (inactiveFilms.empty()) {

        mainProgHeader ();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> REACTIVATE FILMS" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                  REACTIVATE FILMS                  " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[ERR] No films to reactivate                        " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        progStop();
        clrscreen();
        menuSelector = 31;

    }

    else {

        mainProgHeader ();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> REACTIVATE FILMS" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                  REACTIVATE FILMS                  " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[1] Reactivate Film                                 " << "\n"
             << " " << "[0] Manage Films                                    " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        while (1) {

            int usersChoice;

            cout << " " << "[INP] Select Option: ";
            cin >> usersChoice;
                while (cin.fail()) {
                    cinError();
                    inpErr();
                    cout << " " << "[INP] Select Option: ";
                    cin >> usersChoice;
                }

            if (usersChoice ==  1) {

                int numAct = 0;

                for (unsigned int i = 0; i < inactiveFilms.size(); i++) {

                    if (!inactiveFilms[i].getStatus()){
                        numAct++;
                    }

                }

                if (numAct == 0) {

                            clrscreen();
                            mainProgHeader();

                            cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> REACTIVATE FILMS" << "\n";

                            cout << " " << "====================================================" << "\n"
                                 << " " << "                  REACTIVATE FILMS                  " << "\n"
                                 << " " << "====================================================" << "\n"
                                 << " " << "[ERR] No films to reactivate" << "\n"
                                 << " " << "====================================================" << "\n"
                                 << endl;

                            progStop();
                            clrscreen();
                            menuSelector = 315;
                            break;

                }

                else {

                    clrscreen();

                    mainProgHeader ();

                    cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> REACTIVATE FILMS" << "\n";

                    cout << " " << "====================================================" << "\n"
                         << " " << "                  REACTIVATE FILMS                  " << "\n"
                         << " " << "====================================================" << "\n"
                         << endl;

                    cout << " " << "----------------------------------------------------" << "\n"
                         << " " << "[SYS] Showing all inactive films" << "\n"
                         << " " << "----------------------------------------------------" << "\n"
                         << endl;

                    int numFilms = inactiveFilms.size();

                    for (int realRef = 0; realRef < numFilms; realRef++) {

                        int filmRef = realRef + 1;

                        if (inactiveFilms[realRef].getStatus()) {
                            continue;
                        }

                        else {

                            cout << " " << "----------------------------------------------------" << "\n"
                                << " " << "[";

                            if (realRef < 9) {

                                cout << "0" << filmRef << "] Title         : " << inactiveFilms[realRef].getTitle() << "\n"
                                     << " " << "     Status        : Inactive                                 " << "\n"
                                     << " " << "----------------------------------------------------" << "\n"
                                     << " " << "     Film Title    : " << inactiveFilms[realRef].getTitle() << "\n"
                                     << " " << "     Film Director : " << inactiveFilms[realRef].getDirector() << "\n"
                                     << " " << "     Year Released : " << inactiveFilms[realRef].getYear() << "\n"
                                     << " " << "     Ticket Price  : " << inactiveFilms[realRef].getPrice() << "\n"
                                     << " " << "     Seats Alloted : " << inactiveFilms[realRef].getSeats() << "\n"
                                     << " " << "----------------------------------------------------" << "\n"
                                     << endl;

                            }

                            else {

                                cout << filmRef << "] Title  : " << inactiveFilms[realRef].getTitle() << "\n"
                                     << " " << "     Status        : Inactive                              " << "\n"
                                     << " " << "----------------------------------------------------" << "\n"
                                     << " " << "     Film Title    : " << inactiveFilms[realRef].getTitle() << "\n"
                                     << " " << "     Film Director : " << inactiveFilms[realRef].getDirector() << "\n"
                                     << " " << "     Year Released : " << inactiveFilms[realRef].getYear() << "\n"
                                     << " " << "     Ticket Price  : " << inactiveFilms[realRef].getPrice() << "\n"
                                     << " " << "     Seats Alloted : " << inactiveFilms[realRef].getSeats() << "\n"
                                     << " " << "----------------------------------------------------" << "\n"
                                     << endl;

                            }

                        }

                    }

                    cout << " " << "====================================================" << "\n"
                        << endl;

                    while (1) {

                        int userChoice;

                        cout << " " << "[INP] Select a Film for Reactivation: ";
                        cin >> usersChoice;
                        while (cin.fail()) {
                            cinError();
                            inpErr();
                            cout << " " << "[INP] Select a Film for Reactivation: ";
                            cin >> usersChoice;
                        }

                        int realRef = usersChoice - 1;

                        if ((usersChoice > 0) && (usersChoice <= inactiveFilms.size()) && (!inactiveFilms[realRef].getStatus())) {

                            cout << " " << "[INF] The Film \"" << inactiveFilms[realRef].getTitle() << "\" has been selected" << "\n"
                                 << "\n"
                                 << " " << "====================================================" << "\n"
                                 << endl;

                            inactiveFilms[realRef].setStatus(true);

                            cout << " " << "[SYS] The Film \"" << inactiveFilms[realRef].getTitle() << "\" has been reactivated" << "\n";

                            progStop();
                            clrscreen();
                            break;

                        }

                        else {

                            inpErr();

                        }

                    }

                    menuSelector = 315;
                    break;

                }

            }

            else if (usersChoice == 0) {

                clrscreen();
                menuSelector = 31;
                break;

            }

            else {

                inpErr();

            }

        } // while statement

    } // else statement

} // function

void deleteFilms (int& menuSelector, vector<Film>& availableFilms) {

    if (availableFilms.empty()) {

        mainProgHeader ();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> DELETE FILMS" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                    DELETE FILMS                    " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[ERR] No films to delete                            " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        progStop();
        clrscreen();
        menuSelector = 31;

    }

    else {

        mainProgHeader();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> DELETE FILMS" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                    DELETE FILMS                    " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[1] Delete Film                                     " << "\n"
             << " " << "[0] Manage Films                                    " << "\n"             
             << " " << "====================================================" << "\n"
             << endl;
        
        while (1) {
        
            int usersChoice;

            cout << " " << "[INP] Select Option: ";
            cin >> usersChoice;
            while (cin.fail()){
                cinError();
                inpErr;
                cout << " " << "[INP] Select Option: ";
                cin >> usersChoice;             
            }

            if (usersChoice == 1) {

                clrscreen();

                mainProgHeader();

                cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> DELETE FILMS" << "\n";

                cout << " " << "====================================================" << "\n"
                     << " " << "                    DELETE FILMS                    " << "\n"
                     << " " << "====================================================" << "\n"
                     << endl;

                cout << " " << "----------------------------------------------------" << "\n"
                     << " " << "[SYS] Showing all films available for deletion      " << "\n"
                     << " " << "----------------------------------------------------" << "\n"
                     << endl;

                int numFilms = availableFilms.size();

                for (int realRef = 0; realRef < numFilms; realRef++) {
                    
                    int filmRef = realRef + 1;

                    if (realRef < 9) {
                        
                        cout << " " << "----------------------------------------------------" << "\n"
                             << " " << "[0" << filmRef << "] Title         : " << availableFilms[realRef].getTitle() << "\n";

                        if (availableFilms[realRef].getStatus()) {
                            cout << " " << "     Status        : Active" <<"\n";
                        }
                        else {
                            cout << " " << "     Status        : Inactive" <<"\n";
                        }
                        cout << " " << "----------------------------------------------------" << "\n"
                             << " " << "     Film Title    : " << availableFilms[realRef].getTitle() << "\n"
                             << " " << "     Film Director : " << availableFilms[realRef].getDirector() << "\n"
                             << " " << "     Year Released : " << availableFilms[realRef].getYear() << "\n"
                             << " " << "     Ticket Price  : " << availableFilms[realRef].getPrice() << "\n"
                             << " " << "     Alloted Seats : " << availableFilms[realRef].getSeats() << "\n"
                             << " " << "----------------------------------------------------" << "\n"
                             << endl;

                    }

                    else {

                        cout << " " << "----------------------------------------------------" << "\n"
                             << " " << "[" << filmRef << "] Title         : " << availableFilms[realRef].getTitle() << "\n";

                        if (availableFilms[realRef].getStatus()) {
                            cout << " " << "     Status        : Active" <<"\n";
                        }
                        else {
                            cout << " " << "     Status        : Inactive" <<"\n";
                        }
                        cout << " " << "----------------------------------------------------" << "\n"
                             << " " << "     Film Title    : " << availableFilms[realRef].getTitle() << "\n"
                             << " " << "     Film Director : " << availableFilms[realRef].getDirector() << "\n"
                             << " " << "     Year Released : " << availableFilms[realRef].getYear() << "\n"
                             << " " << "     Ticket Price  : " << availableFilms[realRef].getPrice() << "\n"
                             << " " << "     Alloted Seats : " << availableFilms[realRef].getSeats() << "\n"
                             << " " << "----------------------------------------------------" << "\n"
                             << endl;

                    }

                }
                
                cout << " " << "====================================================" << "\n"
                     << endl;

                while (1) {
                    
                    int usersChoice;

                    cout << " " << "[INP] Select a Film for Deletion: ";
                    cin >> usersChoice;
                    while (cin.fail()) {
                        cinError();
                        inpErr();
                        cout << " " << "[INP] Select a Film for Deletion: ";
                        cin >> usersChoice;                        
                    }

                    int realRef = usersChoice - 1;

                    if ((usersChoice > 0) && (usersChoice <= availableFilms.size())) {
                        
                        cout << " " << "[INF] The Film \"" << availableFilms[realRef].getTitle() << " has been selected" << "\n"
                             << "\n"
                             << " " << "====================================================" << "\n"
                             << "\n"
                             << " " << "[SYS] The Film \"" << availableFilms[realRef].getTitle() << " has been successfully deleted" << "\n"
                             << endl;

                        availableFilms.erase(availableFilms.begin() + realRef);

                        progStop();
                        clrscreen();

                        break;
                    }

                    else {
                        inpErr();
                    }

                }

                menuSelector = 316;
                break;
            }

            else if (usersChoice == 0) {

                clrscreen();
                menuSelector = 31;
                break;
            }

            else {

                inpErr();

            }

        }

    }

}