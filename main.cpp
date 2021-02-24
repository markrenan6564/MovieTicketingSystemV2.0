#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <string>

#include "Film.h"
#include "Snack.h"


using namespace std;

static vector<Film> SavedFilms;
static vector<Snack> SavedSnacks;

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

    void manageSnacks(int&);
    void addSnacks (int&, vector<Snack>&);
    void viewSnacks (int&, vector<Snack>&);


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

        system("color 0e");

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

        else if (menuSelector == 32) {
            manageSnacks (menuSelector);
        }

        else if (menuSelector == 321) {
            addSnacks (menuSelector, SavedSnacks);
        }

        else if (menuSelector == 322) {
            viewSnacks (menuSelector, SavedSnacks);
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
            cinError();
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

    system ("color 0c");

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
                cinError();
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
            cinError();
            inpErr();
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
                cinError();
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

            string username;
            string password;

            cin.clear();
            fflush(stdin);

            cout << " " << "USERNAME: ";
            getline(cin, username);
            cout << " " << "PASSWORD: ";
            getline(cin, password);

            cout << " " << "====================================================" << "\n"
                 << endl;

                if ((username == "admin") && (password == "password")) {

                    system ("color 0a");
                    cout << " " << "[SYS] Login Successful" << endl;

                    progStop();
                    clrscreen ();
                    menuSelector = 3;
                }

                else {

                    system ("color 0c");
                    cout << " " << "[ERR] Login Unsuccessful | Wrong Credentials" << endl;

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
            cinError();
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
                cinError ();
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
         << " " << "[1] Add Films                                       " << "\n"
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

        if (usersChoice == 1) {

            clrscreen();
            mainProgHeader();

            cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> ADD FILMS" << "\n";

            cout << " " << "====================================================" << "\n"
                 << " " << "                      ADD FILMS                     " << "\n"
                 << " " << "====================================================" << endl;

            while (1) {

                int desiredNum;

                cout << " " << "[INP] Specify Number of Films to Add: ";
                cin >> desiredNum;
                while (cin.fail()) {
                    cinError();
                    inpError();
                    cout << " " << "[INP] Specify Number of Films to Add: ";
                    cin >> desiredNum;
                }

                if (desiredNum > 0) {

                    cout << " " << "[INF] You want to add " << desiredNum << "\n"
                         << " " << "====================================================" << "\n"
                         << "\n"
                         << " " << "[SYS] " << desiredNum << " film(s) will be added" << "\n";

                    unsigned int accumulated = CurrentFilms.size();

                    progStop();
                    clrscreen();

                    for (int ite = 0; ite < desiredNum; ite++) {

                        int displayRef = ite + 1;

                        accumulated = accumulated + 1;

                        string title, director;
                        int year, price, seats;

                        mainProgHeader();

                        cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> ADD FILMS" << "\n";

                        cout << " " << "====================================================" << "\n"
                             << " " << "                      ADD FILMS                     " << "\n"
                             << " " << "====================================================" << "\n"
                             << "\n"
                             << " " << "[SYS] Adding films..." << "\n"
                             << " " << "      " << displayRef << " of " << desiredNum << "\n"
                             << endl;

                        if (accumulated < 9) {
                            cout << " " << "----------------------------------------------------" << "\n"
                                 << " " << "[0" << accumulated << "] Enter film data" << "\n"
                                 << " " << "----------------------------------------------------" << "\n";
                        }
                        else {
                            cout << " " << "----------------------------------------------------" << "\n"
                                 << " " << "[" << accumulated << "] Enter film data" << "\n"
                                 << " " << "----------------------------------------------------" << "\n";

                        }

                        cout << " " << "     Film Title     : ";
                        getline(cin, title);
                        cout << " " << "     Film Director  : ";
                        getline (cin, director);
                        cout << " " << "     Year Released  : ";
                        cin >> year;
                            while(cin.fail()) {
                                cinError();
                                cout << "     ";
                                inpError();
                                cout << " " << "     Year Released  : ";
                                cin >> year;
                            }
                        cout << " " << "     Ticket Price   : ";
                        cin >> price;
                            while (cin.fail()) {
                                cinError();
                                cout << "     ";
                                inpError();
                                cout << " " << "     Ticket Price   : ";
                                cin >> price;
                            }
                        cout << " " << "     Alloted Seats  : ";
                        cin >> seats;
                            while (cin.fail()) {
                                cinError();
                                cout << "     ";
                                inpError();
                                cout << " " << "     Available Seats: ";
                                cin >> seats;
                            }

                        Film films(title, director, year, price, seats);
                        CurrentFilms.push_back(films);

                        cout << " " << "----------------------------------------------------" << "\n"
                             << "\n"
                             << " " << "====================================================" << "\n"
                             << "\n"
                             << " " << "[SYS] Current entry has been successfully saved" << endl;

                             progStop();
                             clrscreen();
                    }

                    mainProgHeader();

                    cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> ADD FILMS" << "\n";

                    cout << " " << "====================================================" << "\n"
                         << " " << "                      ADD FILMS                     " << "\n"
                         << " " << "====================================================" << "\n"
                         << " " << "[INF] " << desiredNum << " film(s) has been successfully added" << "\n"
                         << " " << "[SYS] Add sequence completed successfully" << "\n"
                         << " " << "====================================================" << "\n"
                         << endl;

                    progStop();
                    break;
                }

                else if (desiredNum == 0) {
                    cout << " " << "[ERR] 0 entered" << "\n"
                         << " " << "====================================================" << "\n"
                         << "\n"
                         << " " << "[SYS] Cancelling add sequence" << endl;
                        progStop();
                        break;
                }

                else {

                    inpError();

                }

            }
            clrscreen();
            menuSelector = 311;
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
                    cinError();
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
                      << " " << "[SYS] Showing all saved films                     " << "\n"
                      << " " << "----------------------------------------------------" << "\n"
                       << endl;

                int vectorSize = addedFilms.size();

                for (int i = 0; i < vectorSize ; i++) {

                    int filmctr = i + 1;

                    cout << " " << "----------------------------------------------------" << "\n";

                    if (i < 9) {
                        cout << " " << "[0" << filmctr << "] Title         : " << addedFilms[i].getTitle() << "\n";
                    }
                    else {
                        cout << " " << "[" << filmctr << "] Title         : " << addedFilms[i].getTitle() << "\n";
                    }

                    if (addedFilms[i].getStatus()) {
                        cout << " " << "     Status        : Active" << "\n";
                    }
                    else {
                        cout << " " << "     Status        : Inactive" << "\n";
                    }

                    cout << " " << "----------------------------------------------------" << "\n"
                         << " " << "     Film Title    : " << addedFilms[i].getTitle() << "\n"
                         << " " << "     Film Director : " << addedFilms[i].getDirector() << "\n"
                         << " " << "     Year Released : " << addedFilms[i].getYear() << "\n"
                         << " " << "     Ticket Price  : " << addedFilms[i].getPrice() << "\n"
                         << " " << "     Seats Alloted : " << addedFilms[i].getSeats() << "\n"
                         << " " << "----------------------------------------------------" << "\n"
                         << endl;

                }

                cout << " " << "====================================================" << "\n"
                     << "\n"
                     << " " << "[SYS] Showed all saved films" << "\n";

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
                     << " " << "[SYS] Showing all film titles" << "\n"
                     << " " << "----------------------------------------------------" << "\n"
                     << endl;

                int vectorSize = addedFilms.size();

                for (int i = 0; i < vectorSize; i++) {

                    int filmctr = i + 1;

                    cout << " " << "----------------------------------------------------" << "\n";

                    if (i < 9) {
                        cout << " " << "[0" << filmctr << "] Title         : " << addedFilms[i].getTitle() << "\n";
                    }

                    else {
                        cout << " " << "[" << filmctr << "] Title         : " << addedFilms[i].getTitle() << "\n";
                    }

                    if (addedFilms[i].getStatus()) {
                        cout << " " << "     Status        : Active" << "\n";
                    }
                    else {
                        cout << " " << "     Status        : Inactive" << "\n";
                    }
                    cout << " " << "----------------------------------------------------" << "\n"
                         << endl;
                }

                cout << " " << "====================================================" << "\n"
                     << endl;

                while (1) {

                    int choice;
                    cout << " " << "[INP] Select Film to View: ";
                    cin >> choice;
                    while (cin.fail()) {
                        cinError();
                        inpErr();
                        cout << " " << "[INP] Select Film to View: ";
                        cin >> choice;
                    }



                    int movienum = choice - 1;

                    if ((0 < choice) && (movienum < addedFilms.size())) {

                        cout << " " << "[INF] Film number " << choice << " has been selected" << "\n"
                             << "\n"
                             << " " << "====================================================" << "\n"
                             << endl;

                        progStop();

                        clrscreen();
                        mainProgHeader();

                        cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> VIEW FILMS >> VIEW SPECIFIC" << "\n";

                        cout << " " << "====================================================" << "\n"
                             << " " << "                     VIEW FILMS                     " << "\n"
                             << " " << "====================================================" << "\n"
                             << "\n"
                             << " " << "----------------------------------------------------" << "\n"
                             << " " << "[SYS] Showing Film \"" << addedFilms[movienum].getTitle() <<  "\"" << "\n"
                             << " " << "----------------------------------------------------" << "\n"
                             << endl;

                        cout << " " << "----------------------------------------------------" << "\n";

                        if (choice < 10) {
                            cout << " " << "[0" << choice << "] Title         : " << addedFilms[movienum].getTitle() << "\n";
                        }
                        else {
                            cout << " " << "[" << choice << "] Title         : " << addedFilms[movienum].getTitle() << "\n";
                        }

                        if (addedFilms[movienum].getStatus()) {
                            cout << " " << "     Status        : Active" << "\n";
                        }
                        else {
                            cout << " " << "     Status        : Inactive" << "\n";
                        }

                        cout << " " << "----------------------------------------------------" << "\n"
                             << " " << "     Film Title    : " << addedFilms[movienum].getTitle() << "\n"
                             << " " << "     Film Director : " << addedFilms[movienum].getDirector() << "\n"
                             << " " << "     Year Released : " << addedFilms[movienum].getYear() << "\n"
                             << " " << "     Ticket Price  : " << addedFilms[movienum].getPrice() << "\n"
                             << " " << "     Seats Alloted : " << addedFilms[movienum].getSeats() << "\n"
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

            cinError();
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
                     << " " << "----------------------------------------------------" << "\n"
                     << " " << "[SYS] Showing all editable films" << "\n"
                     << " " << "----------------------------------------------------" << "\n"
                     << endl;

                int filmsNum = currentFilms.size();

                for (int i = 0; i < filmsNum; i++) {

                    int refnumber = i + 1;

                    cout << " " << "----------------------------------------------------" << "\n";

                    if (i < 9) {
                        cout << " " << "[0" << refnumber << "] Title         : " << currentFilms[i].getTitle() << "\n";
                    }
                    else {
                        cout << " " << "[" << refnumber << "] Title          : " << currentFilms[i].getTitle() << "\n";
                    }

                    if (currentFilms[i].getStatus()) {
                        cout << " " << "     Status        : Active" << "\n";
                    }

                    else {
                        cout << " " << "     Status        : Inactive" << "\n";
                    }

                    cout << " " << "----------------------------------------------------" << "\n"
                         << " " << "     Film Title    : " << currentFilms[i].getTitle() << "\n"
                         << " " << "     Film Director : " << currentFilms[i].getDirector() << "\n"
                         << " " << "     Year Released : " << currentFilms[i].getYear() << "\n"
                         << " " << "     Ticket Price  : " << currentFilms[i].getPrice() << "\n"
                         << " " << "     Seats Alloted : " << currentFilms[i].getSeats() << "\n"
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
                        cinError();
                        inpErr();
                        cout << " " << "[INP] Select film to edit: ";
                        cin >> userChoice;
                    }

                    if ((userChoice > 0) && (userChoice <= currentFilms.size())) {

                        int realref = userChoice - 1;

                        cout << " " << "[INF] You selected the film \"" << currentFilms[realref].getTitle() << "\"" << "\n"
                             << "\n"
                             << " " "====================================================" << "\n"
                             << "\n"
                             << " " << "[SYS] Editing sequence started" << "\n";

                        progStop();
                        clrscreen();

                        mainProgHeader();
                        cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> EDIT FILMS" << "\n";

                        cout << " " << "====================================================" << "\n"
                             << " " << "                     EDIT FILMS                     " << "\n"
                             << " " << "====================================================" << "\n"
                             << endl;

                        string title, director;
                        int year, price, seats;

                        cout << " " << "----------------------------------------------------" << "\n"
                             << " " << "[SYS] Editing film number " << userChoice << "\n"
                             << " " << "----------------------------------------------------" << "\n"
                             << endl;

                        cout << " " << "----------------------------------------------------" << "\n"
                             << " " << "[SYS] Showing film current details" << "\n"
                             << " " << "----------------------------------------------------" << endl;

                        if (userChoice < 10) {
                        cout << " " << "[0" << userChoice << "] Title         : " << currentFilms[realref].getTitle() << "\n";
                        }

                        else {
                        cout << " " << "[" << userChoice << "] Title         : " << currentFilms[realref].getTitle() << "\n";
                        }

                        if (currentFilms[realref].getStatus()) {
                            cout << " " << "     Status        : Active" << "\n";
                        }

                        else {
                            cout << " " << "     Status        : Inactive" << "\n";
                        }

                        cout << " " << "----------------------------------------------------" << "\n"
                             << " " << "     Film Title    : " << currentFilms[realref].getTitle() << "\n"
                             << " " << "     Film Director : " << currentFilms[realref].getDirector() << "\n"
                             << " " << "     Year Released : " << currentFilms[realref].getYear() << "\n"
                             << " " << "     Ticket Price  : " << currentFilms[realref].getPrice() << "\n"
                             << " " << "     Seats Alloted : " << currentFilms[realref].getSeats() << "\n"
                             << " " << "----------------------------------------------------" << "\n"
                             << endl;

                        cout << " " << "----------------------------------------------------" << "\n"
                             << " " << "[INP] Please enter new details " << "\n"
                             << " " << "----------------------------------------------------" << endl;

                        if (userChoice < 10) {
                            cout << " " << "[0" << userChoice << "] Title         : " << currentFilms[realref].getTitle() << "\n";
                        }

                        else {
                            cout << " " << "[" << userChoice << "] Title         : " << currentFilms[realref].getTitle() << "\n";
                        }

                        if (currentFilms[realref].getStatus()) {
                            cout << " " << "     Status        : Active" << "\n";
                        }

                        else {
                            cout << " " << "     Status        : Inactive" << "\n";
                        }

                        cout << " " << "----------------------------------------------------" << "\n";

                        cin.clear();
                        fflush(stdin);

                        cout << " " << "     Film Title    : ";
                        getline(cin, title);
                        currentFilms[realref].setTitle(title);

                        cout << " " << "     Film Director : ";
                        getline(cin, director);
                        currentFilms[realref].setDirector(director);

                        cout << " " << "     Year Released : ";
                        cin >> year;
                            while (cin.fail()) {
                                cinError();
                                cout << "     ";
                                inpError();
                                cout << " " << "     Year Released : ";
                                cin >> year;
                            }
                        currentFilms[realref].setYear(year);

                        cout << " " << "     Ticket Price  : ";
                        cin >> price;
                            while (cin.fail()) {
                                cinError();
                                cout << "     ";
                                inpError();
                                cout << " " << "     Ticket Price  : ";
                                cin >> price;
                            }
                        currentFilms[realref].setPrice(price);

                        cout << " " << "     Alloted Seats : ";
                        cin >> seats;
                            while (cin.fail()) {
                                cinError();
                                cout << "     ";
                                inpError();
                                cout << " " << "     Alloted Seats : ";
                                cin >> seats;
                            }
                        currentFilms[realref].setSeats(seats);

                        cout << " " << "----------------------------------------------------" << "\n"
                             << "\n"
                             << " " << "====================================================" << "\n"
                             << endl;

                        cout << " " << "[SYS] Changes to film  has been successfully saved" << "\n";

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
                                 << " " << "[ERR] All films are deactivated" << "\n"
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
                                 << " " << "[ERR] All films are activated" << "\n"
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

                        cout << " " << "[INF] The Film \"" << availableFilms[realRef].getTitle() << "\" has been selected" << "\n"
                             << "\n"
                             << " " << "====================================================" << "\n"
                             << "\n"
                             << " " << "[SYS] The Film \"" << availableFilms[realRef].getTitle() << "\" has been successfully deleted" << endl;

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

void manageSnacks (int& menuSelector) {

    mainProgHeader();

    cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS" << "\n";

    cout << " " << "====================================================" << "\n"
         << " " << "                   MANAGE SNACKS                    " << "\n"
         << " " << "====================================================" << "\n"
         << " " << "[1] Add Snacks                                       " << "\n"
         << " " << "[2] View Snacks                                      " << "\n"
         << " " << "[3] Edit Snacks                                      " << "\n"
         << " " << "[4] Deactivate Snacks                                " << "\n"
         << " " << "[5] Reactivate Snacks                                " << "\n"
         << " " << "[6] Delete Snacks                                    " << "\n"
         << " " << "[0] Admin Mode                                      " << "\n"
         << " " << "====================================================" << "\n"
         << endl;

    while(1) {
        int userInput;
        cout << " " << "[INP] Select Option: ";
        cin >> userInput;
            while(cin.fail()) {
                cinError ();
                inpErr ();
                cout << " " << "[INP] Select Option: ";
                cin >> userInput;
            }
        if (userInput == 1) {

            clrscreen();
            menuSelector = 321;
            break;
        }
        else if (userInput == 2) {

            clrscreen();
            menuSelector = 322;
            break;
        }
        else if (userInput == 3) {

            clrscreen();
            menuSelector = 323;
            break;
        }
        else if (userInput == 4) {

            clrscreen();
            menuSelector = 324;
            break;
        }
        else if (userInput == 5) {

            clrscreen();
            menuSelector = 325;
            break;
        }
        else if (userInput == 6) {

            clrscreen();
            menuSelector = 326;
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

void addSnacks (int& menuSelector, vector<Snack>& currentSnacks) {

    mainProgHeader();

    cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> ADD SNACKS" << "\n";

    cout << " " << "====================================================" << "\n"
         << " " << "                     ADD SNACKS                     " << "\n"
         << " " << "====================================================" << "\n"
         << " " << "[1] Add Snacks                                      " << "\n"
         << " " << "[0] Manage Snacks                                   " << "\n"
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

        if (usersChoice == 1) {

            clrscreen();
            mainProgHeader();

            cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> ADD SNACKS" << "\n";

            cout << " " << "====================================================" << "\n"
                 << " " << "                     ADD SNACKS                     " << "\n"
                 << " " << "====================================================" << endl;

            while (1) {

                int desiredNum;

                cout << " " << "[INP] Specify Number of Snacks to Add: ";
                cin >> desiredNum;
                while (cin.fail()) {
                    cinError();
                    inpError();
                    cout << " " << "[INP] Specify Number of Snacks to Add: ";
                    cin >> desiredNum;
                }

                if (desiredNum > 0) {

                    cout << " " << "[INF] You want to add " << desiredNum << "\n"
                         << " " << "====================================================" << "\n"
                         << "\n"
                         << " " << "[SYS] " << desiredNum << " snack(s) will be added" << "\n";

                    unsigned int accumulated = currentSnacks.size();

                    progStop();
                    clrscreen();

                    for (int ite = 0; ite < desiredNum; ite++) {

                        int displayRef = ite + 1;

                        accumulated = accumulated + 1;

                        string name, size;
                        int price, quantity;

                        mainProgHeader();

                        cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> ADD SNACKS" << "\n";

                        cout << " " << "====================================================" << "\n"
                             << " " << "                     ADD SNACKS                     " << "\n"
                             << " " << "====================================================" << "\n"
                             << "\n"
                             << " " << "[SYS] Adding snacks..." << "\n"
                             << " " << "      " << displayRef << " of " << desiredNum << "\n"
                             << endl;

                        if (accumulated < 9) {
                            cout << " " << "----------------------------------------------------" << "\n"
                                 << " " << "[0" << accumulated << "] Enter snack data" << "\n"
                                 << " " << "----------------------------------------------------" << "\n";
                        }
                        else {
                            cout << " " << "----------------------------------------------------" << "\n"
                                 << " " << "[" << accumulated << "] Enter snack data" << "\n"
                                 << " " << "----------------------------------------------------" << "\n";

                        }

                        cout << " " << "     Product Name   : ";
                        getline(cin, name);
                        cout << " " << "     Product Size   : ";
                        getline (cin, size);
                        cout << " " << "     Product Price  : ";
                        cin >> price;
                            while(cin.fail()) {
                                cinError();
                                cout << "     ";
                                inpError();
                                cout << " " << "     Product Price  : ";
                                cin >> price;
                            }
                        cout << " " << "     Quantity       : ";
                        cin >> quantity;
                            while (cin.fail()) {
                                cinError();
                                cout << "     ";
                                inpError();
                                cout << " " << "     Quantity       : ";
                                cin >> quantity;
                            }

                        Snack snacks(name, size, price, quantity);
                        currentSnacks.push_back(snacks);

                        cout << " " << "----------------------------------------------------" << "\n"
                             << "\n"
                             << " " << "====================================================" << "\n"
                             << "\n"
                             << " " << "[SYS] Current entry has been successfully saved" << endl;

                             progStop();
                             clrscreen();
                    }

                    mainProgHeader();

                    cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> ADD SNACKS" << "\n";

                    cout << " " << "====================================================" << "\n"
                         << " " << "                     ADD SNACKS                     " << "\n"
                         << " " << "====================================================" << "\n"
                         << " " << "[INF] " << desiredNum << " snack(s) has been successfully added" << "\n"
                         << " " << "[SYS] Add sequence completed successfully" << "\n"
                         << " " << "====================================================" << "\n"
                         << endl;

                    progStop();
                    break;
                }

                else if (desiredNum == 0) {
                    cout << " " << "[ERR] 0 entered" << "\n"
                         << " " << "====================================================" << "\n"
                         << "\n"
                         << " " << "[SYS] Cancelling add sequence" << endl;
                        progStop();
                        break;
                }

                else {

                    inpError();

                }

            }
            clrscreen();
            menuSelector = 321;
            break;
        }

        else if (usersChoice == 0) {

            clrscreen();
            menuSelector = 32;
            break;
        }

        else {

            inpErr();

        }

    }

}

void viewSnacks (int& menuSelector, vector<Snack>& storedSnacks) {

    if (storedSnacks.empty()) {

        mainProgHeader ();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> VIEW SNACKS" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                    VIEW SNACKS                     " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[ERR] No snacks to view                              " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        progStop();
        clrscreen();
        menuSelector = 32;

    }

    else {

        mainProgHeader ();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> VIEW SNACKS" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                    VIEW SNACKS                     " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[1] View All                                        " << "\n"
             << " " << "[2] View Specific                                   " << "\n"
             << " " << "[0] Manage Snacks                                   " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        while (1) {

            int userInput;
            cout << " " << "[INP] Select Option: ";
            cin >> userInput;
                while (cin.fail()) {
                    cinError();
                    inpErr();
                    cout << " " << "[INP] Select Option: ";
                    cin >> userInput;
                }

            if (userInput == 1) {

                clrscreen();
                mainProgHeader ();

                cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> VIEW SNACKS >> VIEW ALL" << "\n";

                cout << " " << "====================================================" << "\n"
                      << " " << "                    VIEW SNACKS                     " << "\n"
                      << " " << "====================================================" << "\n"
                      << "\n"
                      << " " << "----------------------------------------------------" << "\n"
                      << " " << "[SYS] Showing all saved snacks                      " << "\n"
                      << " " << "----------------------------------------------------" << "\n"
                       << endl;

                int vectorSize = storedSnacks.size();

                for (int i = 0; i < vectorSize ; i++) {

                    int prdctr = i + 1;

                    cout << " " << "----------------------------------------------------" << "\n";

                    if (i < 9) {
                        cout << " " << "[0" << prdctr << "] Product Name  : " << storedSnacks[i].getName() << "\n";
                    }
                    else {
                        cout << " " << "[" << prdctr << "] Product Name  : " << storedSnacks[i].getName() << "\n";
                    }

                    if (storedSnacks[i].getStatus()) {
                        cout << " " << "     Status        : Active" << "\n";
                    }
                    else {
                        cout << " " << "     Status        : Inactive" << "\n";
                    }

                    cout << " " << "----------------------------------------------------" << "\n"
                         << " " << "     Product Name  : " << storedSnacks[i].getName() << "\n"
                         << " " << "     Product Size  : " << storedSnacks[i].getSize() << "\n"
                         << " " << "     Prodcut Price : " << storedSnacks[i].getPrice() << "\n"
                         << " " << "     Quantity      : " << storedSnacks[i].getQuantity() << "\n"
                         << " " << "----------------------------------------------------" << "\n"
                         << endl;

                }

                cout << " " << "====================================================" << "\n"
                     << "\n"
                     << " " << "[SYS] Showed all saved snacks" << "\n";

                progStop();
                clrscreen();
                menuSelector = 322;
                break;

            }

            else if (userInput == 2) {

                clrscreen();
                mainProgHeader ();

                cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> VIEW SNACKS >> VIEW SPECIFIC" << "\n";

                cout << " " << "====================================================" << "\n"
                     << " " << "                    VIEW SNACKS                     " << "\n"
                     << " " << "====================================================" << "\n"
                     << "\n"
                     << " " << "----------------------------------------------------" << "\n"
                     << " " << "[SYS] Showing all prodcut names                     " << "\n"
                     << " " << "----------------------------------------------------" << "\n"
                     << endl;

                int vectorSize = storedSnacks.size();

                for (int i = 0; i < vectorSize; i++) {

                    int prdctr = i + 1;

                    cout << " " << "----------------------------------------------------" << "\n";

                    if (i < 9) {
                        cout << " " << "[0" << prdctr << "] Product Name  : " << storedSnacks[i].getName() << "\n";
                    }

                    else {
                        cout << " " << "[" << prdctr << "] Product Name  : " << storedSnacks[i].getName() << "\n";
                    }

                    if (storedSnacks[i].getStatus()) {
                        cout << " " << "     Status        : Active" << "\n";
                    }
                    else {
                        cout << " " << "     Status        : Inactive" << "\n";
                    }
                    cout << " " << "----------------------------------------------------" << "\n"
                         << endl;
                }

                cout << " " << "====================================================" << "\n"
                     << endl;

                while (1) {

                    int choice;
                    cout << " " << "[INP] Select a Snack to View: ";
                    cin >> choice;
                    while (cin.fail()) {
                        cinError();
                        inpErr();
                        cout << " " << "[INP] Select a Snack to View: ";
                        cin >> choice;
                    }

                    int snacknum = choice - 1;

                    if ((0 < choice) && (snacknum < storedSnacks.size())) {

                        cout << " " << "[INF] Snack number " << choice << " has been selected" << "\n"
                             << "\n"
                             << " " << "====================================================" << "\n"
                             << endl;

                        progStop();

                        clrscreen();
                        mainProgHeader();

                        cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> VIEW SNACKS >> VIEW SPECIFIC" << "\n";

                        cout << " " << "====================================================" << "\n"
                             << " " << "                    VIEW SNACKS                     " << "\n"
                             << " " << "====================================================" << "\n"
                             << "\n"
                             << " " << "----------------------------------------------------" << "\n"
                             << " " << "[SYS] Showing Snack \"" << storedSnacks[snacknum].getName() <<  "\"" << "\n"
                             << " " << "----------------------------------------------------" << "\n"
                             << endl;

                        cout << " " << "----------------------------------------------------" << "\n";

                        if (choice < 10) {
                            cout << " " << "[0" << choice << "] Product Name  : " << storedSnacks[snacknum].getName() << "\n";
                        }
                        else {
                            cout << " " << "[" << choice << "] Product Name  : " << storedSnacks[snacknum].getName() << "\n";
                        }

                        if (storedSnacks[snacknum].getStatus()) {
                            cout << " " << "     Status        : Active" << "\n";
                        }
                        else {
                            cout << " " << "     Status        : Inactive" << "\n";
                        }

                        cout << " " << "----------------------------------------------------" << "\n"
                             << " " << "     Product Name  : " << storedSnacks[snacknum].getName() << "\n"
                             << " " << "     Product Size  : " << storedSnacks[snacknum].getSize() << "\n"
                             << " " << "     Product Price : " << storedSnacks[snacknum].getPrice() << "\n"
                             << " " << "     Quantity      : " << storedSnacks[snacknum].getQuantity() << "\n"
                             << " " << "----------------------------------------------------" << "\n"
                             << "\n"
                             << " " << "====================================================" << "\n"
                             << endl;


                        progStop ();
                        menuSelector = 322;
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

                menuSelector = 32;
                clrscreen ();
                break;

            }

            else {

                inpErr();

            }

        }

    }

}