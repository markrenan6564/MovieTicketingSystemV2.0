#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <string>

#include "Film.h"
#include "Snack.h"
#include "Transaction.h"


using namespace std;

static vector<Film> SavedFilms;
static vector<Snack> SavedSnacks;
static vector<Transaction> transactionTracker;

static vector<string> adminCredentials;

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

    void bookMovie (int&, vector<Film>&, vector<Transaction>&);
    void buySnacks (int&, vector<Snack>&, vector<Transaction>&);

    void adminLogin (int&, vector<string>&);
    void adminMenu (int&);

    void accountSettings (int&, vector<string>&);

    void manageFilms (int&);
    void addFilms (int&, vector<Film>&);
    void setSchedule (int&, vector<Film>&);
    void viewFilms (int&, vector<Film>&);
    void editFilms (int&, vector<Film>&);
    void deactivateFilms (int&, vector<Film>&);
    void reactivateFilms (int&, vector<Film>&);
    void deleteFilms (int&, vector<Film>&);
    void resetReservation (int&, vector<Film>&);

    void manageSnacks(int&);
    void addSnacks (int&, vector<Snack>&);
    void viewSnacks (int&, vector<Snack>&);
    void editSnacks (int&, vector<Snack>&);
    void deactivateSnacks (int&, vector<Snack>&);
    void reactivateSnacks (int&, vector<Snack>&);
    void deleteSnacks (int&, vector<Snack>&);

    void viewSales (int&, vector<Transaction>&);

    void accountSettings (int&, vector<string>&);


int main() {

/*

    INDEX for Menu Selector
    A comprehensive guide by Mark Renan

        Program Terminator = -2

        ParentMenu = -1
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
                        Reset Reservation = 317

                    Manage Snacks = 32
                        Add Snacks = 321
                        View Snacks = 322
                        Edit Snacks = 323
                        Deactivate Snacks = 324
                        Reactivate Snacks = 325
                        Delete Snacks = 326

                    View Sales = 33

                    Account Settings = 34

*/

    int menuSelector;

    while (1) {

        system("color 0e");

        if (menuSelector == -2) {
            programTerminator (menuSelector);
        }

        else if (menuSelector == -1) {
            parentMenu (menuSelector);
        }

        else if (menuSelector == 1) {
            mainMenu (menuSelector);
        }

        else if (menuSelector == 2) {
            adminLogin (menuSelector, adminCredentials);
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

        else if (menuSelector == 317) {
            resetReservation (menuSelector, SavedFilms);
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

        else if (menuSelector == 323) {
            editSnacks (menuSelector, SavedSnacks);
        }

        else if (menuSelector == 324 ) {
            deactivateSnacks (menuSelector, SavedSnacks);
        }

        else if (menuSelector == 325) {
            reactivateSnacks (menuSelector, SavedSnacks);
        }

        else if (menuSelector == 326) {
            deleteSnacks (menuSelector, SavedSnacks);
        }

        else if (menuSelector == 33) {
            viewSales (menuSelector, transactionTracker);
        }

        else if (menuSelector == 34) {
            accountSettings (menuSelector, adminCredentials);
        }

        else if (menuSelector == 11) {
            bookMovie (menuSelector, SavedFilms, transactionTracker);
        }

        else if (menuSelector == 12) {
            buySnacks (menuSelector, SavedSnacks, transactionTracker);
        }

        else {

            adminCredentials.push_back("admin");
            adminCredentials.push_back("password");

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
            menuSelector = -2;
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
            menuSelector = -1;
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
         << " " << "[1] Book Movie                                      " << "\n"
         << " " << "[2] Buy Movie Snacks                                " << "\n"
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
            menuSelector = -1;
            break;

        }

        else if (userInput == 1) {

            clrscreen();
            menuSelector = 11;
            break;

        }

        else if (userInput == 2) {

            clrscreen();
            menuSelector = 12;
            break;

        }

        else {

            inpErr();

        }
    }
}

void adminLogin (int& menuSelector, vector<string>& adminCredentials) {

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

            cout << " " << "USERNAME : ";
            getline(cin, username);
            cout << " " << "PASSWORD : ";
            getline(cin, password);

            cout << " " << "====================================================" << "\n"
                 << endl;

                if ((username == adminCredentials[0]) && (password == adminCredentials[1])) {

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
            menuSelector = -1;
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
         << " " << "[3] Manage Sales                                    " << "\n"
         << " " << "[4] Account Settings                                " << "\n"
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

        else if (userInput == 4) {

            clrscreen();
            menuSelector = 34;
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
         << " " << "[7] Reset Reservation                               " << "\n"
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

        else if (userInput == 7) {

            clrscreen();
            menuSelector = 317;
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

                        if (accumulated < 10) {
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
                        cout << " " << "     Ticket Price   : Php ";
                        cin >> price;
                            while (cin.fail()) {
                                cinError();
                                cout << "     ";
                                inpError();
                                cout << " " << "     Ticket Price   : Php ";
                                cin >> price;
                            }
                        cout << " " << "     Alloted Seats  : ";
                        cin >> seats;
                            while (cin.fail() || (seats <=  0) || (seats > 300)) {
                                cinError();
                                cout << "     ";
                                inpError();
                                cout << "      [INF] 300 is the maximum alloted seats" << "\n";
                                cout << " " << "     Alloted Seats  : ";
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
                         << " " << "====================================================" << "\n"
                         << "\n"
                         << " " << "[SYS] Add sequence completed successfully" << endl;

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
                         << " " << "     Ticket Price  : Php " << addedFilms[i].getPrice() << "\n"
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
                             << " " << "     Ticket Price  : Php " << addedFilms[movienum].getPrice() << "\n"
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
                         << " " << "     Ticket Price  : Php " << currentFilms[i].getPrice() << "\n"
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
                             << " " << "     Ticket Price  : Php " << currentFilms[realref].getPrice() << "\n"
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

                        cout << " " << "     Ticket Price  : Php ";
                        cin >> price;
                            while (cin.fail()) {
                                cinError();
                                cout << "     ";
                                inpError();
                                cout << " " << "     Ticket Price  : Php ";
                                cin >> price;
                            }
                        currentFilms[realref].setPrice(price);

                        cout << " " << "     Alloted Seats : ";
                        cin >> seats;
                            while (cin.fail() || (seats <=  0) || (seats > 300)) {
                                cinError();
                                cout << "     ";
                                inpError();
                                cout << "      [INF] 300 is the maximum alloted seats" << "\n";
                                cout << " " << "     Alloted Seats  : ";
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
                                << " " << "     Ticket Price  : Php " << activeFilms[realRef].getPrice() << "\n"
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
                                    << " " << "     Ticket Price  : Php " << activeFilms[realRef].getPrice() << "\n"
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
                                 << " " << "[ERR] All films are activated                       " << "\n"
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
                                     << " " << "     Ticket Price  : Php " << inactiveFilms[realRef].getPrice() << "\n"
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
                                     << " " << "     Ticket Price  : Php " << inactiveFilms[realRef].getPrice() << "\n"
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
                inpErr();
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
                             << " " << "     Ticket Price  : Php " << availableFilms[realRef].getPrice() << "\n"
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
                             << " " << "     Ticket Price  : Php " << availableFilms[realRef].getPrice() << "\n"
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

void resetReservation (int& menuSelector, vector<Film>& savedFilms) {

    if (savedFilms.empty()) {

        mainProgHeader ();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> RESET RESERVATION" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                  RESET RESERVATION                 " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[ERR] Unable to reset. No films are added yet                            " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        progStop();
        clrscreen();
        menuSelector = 31;

    }

    else {

        mainProgHeader ();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> RESET RESERVATION" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                  RESET RESERVATION                 " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[1] Reset Reservation                               " << "\n"
             << " " << "[0] Manage Films                                    " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        while (1) {

            int usersMenu;

            cout << " " << "[INP] Select Option: ";
            cin >> usersMenu;
            while (cin.fail()) {
                cinError();
                inpErr();
                cout << " " << "[INP] Select Option: ";
                cin >> usersMenu;
            }

            if (usersMenu == 1) {

                clrscreen();

                cout << " " << "HOME >> ADMIN MODE >> MANAGE FILMS >> RESET RESERVATION" << "\n";

                cout << " " << "====================================================" << "\n"
                     << " " << "                  RESET RESERVATION                 " << "\n"
                     << " " << "====================================================" << "\n"
                     << endl;

                cout << " " << "----------------------------------------------------" << "\n"
                     << " " << "[SYS] Showing all films available for reset         " << "\n"
                     << " " << "----------------------------------------------------" << "\n"
                     << endl;

                int numFilms = savedFilms.size();
                int displayRef = 0;

                for (int realRef = 0; realRef < numFilms ; realRef++) {

                    displayRef++;

                    cout << " " << "----------------------------------------------------" << "\n";

                    if (realRef < 9) {
                        cout << " " << "[0" << displayRef << "] Title         : " << savedFilms[realRef].getTitle() << "\n";
                    }
                    else {
                        cout << " " << "[" << displayRef << "] Title         : " << savedFilms[realRef].getTitle() << "\n";
                    }

                    if (savedFilms[realRef].getStatus()) {
                        cout << " " << "     Status        : Active" << "\n";
                    }
                    else {
                        cout << " " << "     Status        : Inactive" << "\n";
                    }

                    cout << " " << "----------------------------------------------------" << "\n"
                         << " " << "     Film Title    : " << savedFilms[realRef].getTitle() << "\n"
                         << " " << "     Film Director : " << savedFilms[realRef].getDirector() << "\n"
                         << " " << "     Year Released : " << savedFilms[realRef].getYear() << "\n"
                         << " " << "     Ticket Price  : Php " << savedFilms[realRef].getPrice() << "\n"
                         << " " << "     Seats Alloted : " << savedFilms[realRef].getSeats() << "\n"
                         << " " << "----------------------------------------------------" << "\n"
                         << endl;

                }

                cout << " " << "====================================================" << "\n"
                     << endl;

                while (1) {

                    int chosenFilm;
                    cout << " " << "[INP] Select Film: ";
                    cin >> chosenFilm;
                    while (cin.fail()) {
                        cinError();
                        inpErr();
                        cout << " " << "[INP] Select Film: ";
                        cin >> chosenFilm;
                    }

                    if ((chosenFilm > 0) && (chosenFilm <= savedFilms.size())) {

                        int realRef = chosenFilm -1;

                        cout << " " << "[INF] You selected " << savedFilms[realRef].getTitle() << "\n"
                             << "\n"
                             << " " << "====================================================" << "\n"
                             << endl;

                        savedFilms[realRef].setSeats(savedFilms[realRef].getSeats());

                        cout << " " << "[SYS] Reset Successful" << endl;

                        progStop();
                        clrscreen();
                        break;

                    }

                    else {

                        inpErr();

                    }

                }

                break;
            }

            else if (usersMenu == 0) {

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

                        if (accumulated < 10) {
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
                        cout << " " << "     Product Price  : Php ";
                        cin >> price;
                            while(cin.fail()) {
                                cinError();
                                cout << "     ";
                                inpError();
                                cout << " " << "     Product Price  : Php ";
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
                        cout << " " << "[0" << prdctr << "] Snack         : " << storedSnacks[i].getName() << " - " << storedSnacks[i].getSize() << "\n";
                    }
                    else {
                        cout << " " << "[" << prdctr << "] Snack         : " << storedSnacks[i].getName() << " - " << storedSnacks[i].getSize() << "\n";
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
                         << " " << "     Prodcut Price : Php " << storedSnacks[i].getPrice() << "\n"
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
                        cout << " " << "[0" << prdctr << "] Snack         : " << storedSnacks[i].getName() << " - " << storedSnacks[i].getSize() << "\n";
                    }

                    else {
                        cout << " " << "[" << prdctr << "] Snack         : " << storedSnacks[i].getName() << " - " << storedSnacks[i].getSize() << "\n";
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
                             << " " << "[SYS] Showing Snack \"" << storedSnacks[snacknum].getName() << " - " << storedSnacks[snacknum].getSize() <<  "\"" << "\n"
                             << " " << "----------------------------------------------------" << "\n"
                             << endl;

                        cout << " " << "----------------------------------------------------" << "\n";

                        if (choice < 10) {
                            cout << " " << "[0" << choice << "] Snack         : " << storedSnacks[snacknum].getName() << " - " << storedSnacks[snacknum].getSize() << "\n";
                        }
                        else {
                            cout << " " << "[" << choice << "] Snack         : " << storedSnacks[snacknum].getName() << " - " << storedSnacks[snacknum].getSize() << "\n";
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
                             << " " << "     Product Price : Php " << storedSnacks[snacknum].getPrice() << "\n"
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

void editSnacks (int& menuSelector, vector<Snack>& savedSnacks) {

    if (savedSnacks.empty()) {

        mainProgHeader ();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> EDIT SNACKS" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                     EDIT SNACKS                    " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[ERR] No snacks to edit                             " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        progStop();
        clrscreen();
        menuSelector = 32;

    } // 1st if  closing parethesis

    else {

        mainProgHeader ();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> EDIT SNACKS" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                    EDIT SNACKS                     " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[1] Edit Snack Details                              " << "\n"
             << " " << "[0] Manage Snacks                                   " << "\n"
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

                cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> EDIT SNACKS" << "\n";

                cout << " " << "====================================================" << "\n"
                     << " " << "                     EDIT SNACKS                     " << "\n"
                     << " " << "====================================================" << "\n"
                     << "\n"
                     << " " << "----------------------------------------------------" << "\n"
                     << " " << "[SYS] Showing all editable snacks" << "\n"
                     << " " << "----------------------------------------------------" << "\n"
                     << endl;

                int snacksNum = savedSnacks.size();

                for (int i = 0; i < snacksNum; i++) {

                    int refnumber = i + 1;

                    cout << " " << "----------------------------------------------------" << "\n";

                    if (i < 9) {
                        cout << " " << "[0" << refnumber << "] Snack         : " << savedSnacks[i].getName() << " - " << savedSnacks[i].getSize() << "\n";
                    }
                    else {
                        cout << " " << "[" << refnumber << "] Snack         : " << savedSnacks[i].getName() << " - " << savedSnacks[i].getSize() << "\n";
                    }

                    if (savedSnacks[i].getStatus()) {
                        cout << " " << "     Status        : Active" << "\n";
                    }

                    else {
                        cout << " " << "     Status        : Inactive" << "\n";
                    }

                    cout << " " << "----------------------------------------------------" << "\n"
                         << " " << "     Product Name  : " << savedSnacks[i].getName() << "\n"
                         << " " << "     Product Size  : " << savedSnacks[i].getSize() << "\n"
                         << " " << "     Product Price : Php " << savedSnacks[i].getPrice() << "\n"
                         << " " << "     Quantity      : " << savedSnacks[i].getQuantity() << "\n"
                         << " " << "----------------------------------------------------" << "\n"
                         << endl;

                } // For showing all films

                cout << " " << "====================================================" << "\n"
                     << endl;

                while (1) {

                    int userChoice;

                    cout << " " << "[INP] Select snack to edit: ";
                    cin >> userChoice;

                    while (cin.fail()) {
                        cinError();
                        inpErr();
                        cout << " " << "[INP] Select snack to edit: ";
                        cin >> userChoice;
                    }

                    if ((userChoice > 0) && (userChoice <= savedSnacks.size())) {

                        int realref = userChoice - 1;

                        cout << " " << "[INF] You selected snack \"" << savedSnacks[realref].getName() << " - " << savedSnacks[realref].getSize() << "\"" << "\n"
                             << "\n"
                             << " " "====================================================" << "\n"
                             << "\n"
                             << " " << "[SYS] Editing sequence started" << "\n";

                        progStop();
                        clrscreen();

                        mainProgHeader();
                        cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> EDIT SNACKS" << "\n";

                        cout << " " << "====================================================" << "\n"
                             << " " << "                    EDIT SNACKS                     " << "\n"
                             << " " << "====================================================" << "\n"
                             << endl;

                        string name, size;
                        int price, quantity;

                        cout << " " << "----------------------------------------------------" << "\n"
                             << " " << "[SYS] Editing snack number " << userChoice << "\n"
                             << " " << "----------------------------------------------------" << "\n"
                             << endl;

                        cout << " " << "----------------------------------------------------" << "\n"
                             << " " << "[SYS] Showing snack current details" << "\n"
                             << " " << "----------------------------------------------------" << endl;

                        if (userChoice < 10) {
                        cout << " " << "[0" << userChoice << "] Snack         : " << savedSnacks[realref].getName() << " - " << savedSnacks[realref].getSize() << "\n";
                        }

                        else {
                        cout << " " << "[" << userChoice << "] Snack         : " << savedSnacks[realref].getName() << " - " << savedSnacks[realref].getSize() << "\n";
                        }

                        if (savedSnacks[realref].getStatus()) {
                            cout << " " << "     Status        : Active" << "\n";
                        }

                        else {
                            cout << " " << "     Status        : Inactive" << "\n";
                        }

                        cout << " " << "----------------------------------------------------" << "\n"
                             << " " << "     Product Name  : " << savedSnacks[realref].getName() << "\n"
                             << " " << "     Product Size  : " << savedSnacks[realref].getSize() << "\n"
                             << " " << "     Product Price : Php " << savedSnacks[realref].getPrice() << "\n"
                             << " " << "     Quantity      : " << savedSnacks[realref].getQuantity() << "\n"
                             << " " << "----------------------------------------------------" << "\n"
                             << endl;

                        cout << " " << "----------------------------------------------------" << "\n"
                             << " " << "[INP] Please enter new details " << "\n"
                             << " " << "----------------------------------------------------" << endl;

                        if (userChoice < 10) {
                            cout << " " << "[0" << userChoice << "] Snack         : " << savedSnacks[realref].getName() << " - " << savedSnacks[realref].getSize() << "\n";
                        }

                        else {
                            cout << " " << "[" << userChoice << "] Snack         : " << savedSnacks[realref].getName() << " - " << savedSnacks[realref].getSize() << "\n";
                        }

                        if (savedSnacks[realref].getStatus()) {
                            cout << " " << "     Status        : Active" << "\n";
                        }

                        else {
                            cout << " " << "     Status        : Inactive" << "\n";
                        }

                        cout << " " << "----------------------------------------------------" << "\n";

                        cin.clear();
                        fflush(stdin);

                        cout << " " << "     Product Name  : ";
                        getline(cin, name);
                        savedSnacks[realref].setName(name);

                        cout << " " << "     Product Size  : ";
                        getline(cin, size);
                        savedSnacks[realref].setSize(size);

                        cout << " " << "     Product Price : Php ";
                        cin >> price;
                            while (cin.fail()) {
                                cinError();
                                cout << "     ";
                                inpError();
                                cout << " " << "     Product Price : Php ";
                                cin >> price;
                            }
                        savedSnacks[realref].setPrice(price);

                        cout << " " << "     Quantity      : ";
                        cin >> quantity;
                            while (cin.fail()) {
                                cinError();
                                cout << "     ";
                                inpError();
                                cout << " " << "     Quantity      : ";
                                cin >> quantity;
                            }
                        savedSnacks[realref].setQuantity(quantity);

                        cout << " " << "----------------------------------------------------" << "\n"
                             << "\n"
                             << " " << "====================================================" << "\n"
                             << endl;

                        cout << " " << "[SYS] Changes to snack  has been successfully saved" << "\n";

                        progStop();
                        break;

                    }

                    else {
                        inpErr();
                    }

                } // While loop for verifying choice from ref

                clrscreen();
                menuSelector = 323;
                break;

            } // For Editing Film Details | needs break

            else if (userChoice == 0) {

                clrscreen();
                menuSelector = 32;
                break;

            } // For going back to menu | needs break

            else {

                inpErr();

            } // When user enter a wrong input, this condition will ask it again

        } // while loop for menu selection

    } // If there is already instance of film existing

}

void deactivateSnacks (int& menuSelector, vector<Snack>& savedSnacks) {

    if (savedSnacks.empty()) {

        mainProgHeader ();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> DEACTIVATE SNACKS" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                 DEACTIVATE SNACKS                  " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[ERR] No snacks to deactivate                        " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        progStop();
        clrscreen();
        menuSelector = 32;

    }

    else {

        mainProgHeader ();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> DEACTIVATE SNACKS" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                 DEACTIVATE SNACKS                  " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[1] Deactivate Snack                                 " << "\n"
             << " " << "[0] Manage Snacks                                    " << "\n"
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

                for (unsigned int i = 0; i < savedSnacks.size(); i++) {

                    if (savedSnacks[i].getStatus()){
                        numAct++;
                    }

                }

                if (numAct == 0) {

                            clrscreen();
                            mainProgHeader();

                            cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> DEACTIVATE SNACKS" << "\n";

                            cout << " " << "====================================================" << "\n"
                                 << " " << "                 DEACTIVATE SNACKS                  " << "\n"
                                 << " " << "====================================================" << "\n"
                                 << " " << "[ERR] All snacks are deactivated" << "\n"
                                 << " " << "====================================================" << "\n"
                                 << endl;

                            progStop();
                            clrscreen();
                            menuSelector = 324;
                            break;

                }

                else {

                    clrscreen();

                    mainProgHeader ();

                    cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> DEACTIVATE SNACKS" << "\n";

                    cout << " " << "====================================================" << "\n"
                         << " " << "                  DEACTIVATE SNACKS                  " << "\n"
                         << " " << "====================================================" << "\n"
                         << endl;

                    cout << " " << "----------------------------------------------------" << "\n"
                         << " " << "[SYS] Showing all active snacks" << "\n"
                         << " " << "----------------------------------------------------" << "\n"
                         << endl;

                    int numFilms = savedSnacks.size();

                    for (int realRef = 0; realRef < numFilms; realRef++) {

                        int filmRef = realRef + 1;

                        if (!savedSnacks[realRef].getStatus()) {
                            continue;
                        }

                        else {

                            cout << " " << "----------------------------------------------------" << "\n";

                            if (realRef < 9) {
                                cout << " " << "[0" << filmRef << "] Snack         : " << savedSnacks[realRef].getName() << " - " << savedSnacks[realRef].getSize() << "\n";
                            }
                            else {
                                cout << " " << "[" << filmRef << "]  Snack         : " << savedSnacks[realRef].getName() << " - " << savedSnacks[realRef].getSize() << "\n";
                            }

                            cout << " " << "     Status        : Active                         " << "\n"
                                 << " " << "----------------------------------------------------" << "\n"
                                 << " " << "     Product Name  : " << savedSnacks[realRef].getName() << "\n"
                                 << " " << "     Product Size  : " << savedSnacks[realRef].getSize() << "\n"
                                 << " " << "     Product Price : Php " << savedSnacks[realRef].getPrice() << "\n"
                                 << " " << "     Quantity      : " << savedSnacks[realRef].getQuantity() << "\n"
                                 << " " << "----------------------------------------------------" << "\n"
                                 << endl;

                        }

                    }

                    cout << " " << "====================================================" << "\n"
                         << endl;

                    while (1) {

                        int userChoice;

                        cout << " " << "[INP] Select a Snack for Deactivation: ";
                        cin >> usersChoice;
                        while (cin.fail()) {
                            cinError();
                            inpErr();
                            cout << " " << "[INP] Select a Snack for Deactivation: ";
                            cin >> usersChoice;
                        }

                        int realRef = usersChoice - 1;

                        if ((usersChoice > 0) && (usersChoice <= savedSnacks.size()) && (savedSnacks[realRef].getStatus())) {

                            cout << " " << "[INF] The Snack \"" << savedSnacks[realRef].getName() << " - " << savedSnacks[realRef].getSize() << "\" has been selected" << "\n"
                                 << "\n"
                                 << " " << "====================================================" << "\n"
                                 << endl;

                            savedSnacks[realRef].setStatus(false);

                            cout << " " << "[SYS] The Snack \"" << savedSnacks[realRef].getName() << " - " << savedSnacks[realRef].getSize() << "\" has been deactivated" << "\n";

                            progStop();
                            clrscreen();
                            break;

                        }

                        else {

                            inpErr();

                        }

                    }

                    menuSelector = 324;
                    break;

                }

            }

            else if (usersChoice == 0) {

                clrscreen();
                menuSelector = 32;
                break;

            }

            else {

                inpErr();

            }

        } // while statement

    } // else statement

}

void reactivateSnacks (int& menuSelector, vector<Snack>& savedSnacks) {

    if (savedSnacks.empty()) {

        mainProgHeader ();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> REACTIVATE SNACKS" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                 REACTIVATE SNACKS                  " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[ERR] No snacks to reactivate                        " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        progStop();
        clrscreen();
        menuSelector = 32;

    }

    else {

        mainProgHeader ();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> REACTIVATE SNACKS" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                 REACTIVATE SNACKS                  " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[1] Reactivate Snack                                 " << "\n"
             << " " << "[0] Manage Snacks                                    " << "\n"
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

                for (unsigned int i = 0; i < savedSnacks.size(); i++) {

                    if (!savedSnacks[i].getStatus()){
                        numAct++;
                    }

                }

                if (numAct == 0) {

                            clrscreen();
                            mainProgHeader();

                            cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> REACTIVATE SNACKS" << "\n";

                            cout << " " << "====================================================" << "\n"
                                 << " " << "                 REACTIVATE SNACKS                  " << "\n"
                                 << " " << "====================================================" << "\n"
                                 << " " << "[ERR] All snacks are activated" << "\n"
                                 << " " << "====================================================" << "\n"
                                 << endl;

                            progStop();
                            clrscreen();
                            menuSelector = 325;
                            break;

                }

                else {

                    clrscreen();

                    mainProgHeader ();

                    cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> REACTIVATE SNACKS" << "\n";

                    cout << " " << "====================================================" << "\n"
                         << " " << "                  REACTIVATE SNACKS                  " << "\n"
                         << " " << "====================================================" << "\n"
                         << endl;

                    cout << " " << "----------------------------------------------------" << "\n"
                         << " " << "[SYS] Showing all inactive snacks" << "\n"
                         << " " << "----------------------------------------------------" << "\n"
                         << endl;

                    int numFilms = savedSnacks.size();

                    for (int realRef = 0; realRef < numFilms; realRef++) {

                        int filmRef = realRef + 1;

                        if (savedSnacks[realRef].getStatus()) {
                            continue;
                        }

                        else {

                            cout << " " << "----------------------------------------------------" << "\n";

                            if (realRef < 9) {
                                cout << " " << "[0" << filmRef << "] Snack         : " << savedSnacks[realRef].getName() << " - " << savedSnacks[realRef].getSize() << "\n";
                            }
                            else {
                                cout << " " << "[" << filmRef << "]  Snack         : " << savedSnacks[realRef].getName() << " - " << savedSnacks[realRef].getSize() << "\n";
                            }

                            cout << " " << "     Status        : Inactive                       " << "\n"
                                 << " " << "----------------------------------------------------" << "\n"
                                 << " " << "     Product Name  : " << savedSnacks[realRef].getName() << "\n"
                                 << " " << "     Product Size  : " << savedSnacks[realRef].getSize() << "\n"
                                 << " " << "     Product Price : Php " << savedSnacks[realRef].getPrice() << "\n"
                                 << " " << "     Quantity      : " << savedSnacks[realRef].getQuantity() << "\n"
                                 << " " << "----------------------------------------------------" << "\n"
                                 << endl;

                        }

                    }

                    cout << " " << "====================================================" << "\n"
                         << endl;

                    while (1) {

                        int userChoice;

                        cout << " " << "[INP] Select a Snack for Reactivation: ";
                        cin >> usersChoice;
                        while (cin.fail()) {
                            cinError();
                            inpErr();
                            cout << " " << "[INP] Select a Snack for Reactivation: ";
                            cin >> usersChoice;
                        }

                        int realRef = usersChoice - 1;

                        if ((usersChoice > 0) && (usersChoice <= savedSnacks.size()) && (!savedSnacks[realRef].getStatus())) {

                            cout << " " << "[INF] The Snack \"" << savedSnacks[realRef].getName() << " - " << savedSnacks[realRef].getSize() << "\" has been selected" << "\n"
                                 << "\n"
                                 << " " << "====================================================" << "\n"
                                 << endl;

                            savedSnacks[realRef].setStatus(true);

                            cout << " " << "[SYS] The Snack \"" << savedSnacks[realRef].getName() << " - " << savedSnacks[realRef].getSize() << "\" has been reactivated" << "\n";

                            progStop();
                            clrscreen();
                            break;

                        }

                        else {

                            inpErr();

                        }

                    }

                    menuSelector = 325;
                    break;

                }

            }

            else if (usersChoice == 0) {

                clrscreen();
                menuSelector = 32;
                break;

            }

            else {

                inpErr();

            }

        } // while statement

    } // else statement

}

void deleteSnacks (int& menuSelector, vector<Snack>& savedSnacks) {


    if (savedSnacks.empty()) {

        mainProgHeader ();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> DELETE SNACKS" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                   DELETE SNACKS                    " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[ERR] No snacks to delete                            " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        progStop();
        clrscreen();
        menuSelector = 32;

    }

    else {

        mainProgHeader();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> DELETE SNACKS" << "\n";

        cout << " " << "====================================================" << "\n"
             << " " << "                   DELETE SNACKS                    " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[1] Delete Snack                                    " << "\n"
             << " " << "[0] Manage Snacks                                   " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        while (1) {

            int usersChoice;

            cout << " " << "[INP] Select Option: ";
            cin >> usersChoice;
            while (cin.fail()){
                cinError();
                inpErr();
                cout << " " << "[INP] Select Option: ";
                cin >> usersChoice;
            }

            if (usersChoice == 1) {

                clrscreen();

                mainProgHeader();

                cout << " " << "HOME >> ADMIN MODE >> MANAGE SNACKS >> DELETE SNACKS" << "\n";

                cout << " " << "====================================================" << "\n"
                     << " " << "                   DELETE SNACKS                    " << "\n"
                     << " " << "====================================================" << "\n"
                     << endl;

                cout << " " << "----------------------------------------------------" << "\n"
                     << " " << "[SYS] Showing all snacks available for deletion      " << "\n"
                     << " " << "----------------------------------------------------" << "\n"
                     << endl;

                int numSnacks = savedSnacks.size();

                for (int realRef = 0; realRef < numSnacks; realRef++) {

                    int snacksRef = realRef + 1;

                    cout << " " << "----------------------------------------------------" << "\n";

                    if (realRef < 9) {
                        cout << " " << "[0" << snacksRef << "] Snack         : " << savedSnacks[realRef].getName() << " - " << savedSnacks[realRef].getSize() << "\n";
                    }
                    else {
                        cout << " " << "[" << snacksRef << "] Snack         : " << savedSnacks[realRef].getName() << " - " << savedSnacks[realRef].getSize() << "\n";
                    }

                    if (savedSnacks[realRef].getStatus()) {
                        cout << " " << "     Status        : Active" <<"\n";
                    }
                    else {
                        cout << " " << "     Status        : Inactive" <<"\n";
                    }
                        cout << " " << "----------------------------------------------------" << "\n"
                             << " " << "     Product Name  : " << savedSnacks[realRef].getName() << "\n"
                             << " " << "     Product Size  : " << savedSnacks[realRef].getSize() << "\n"
                             << " " << "     Product Price : Php " << savedSnacks[realRef].getPrice() << "\n"
                             << " " << "     Quantity      : " << savedSnacks[realRef].getQuantity() << "\n"
                             << " " << "----------------------------------------------------" << "\n"
                             << endl;

                }

                cout << " " << "====================================================" << "\n"
                     << endl;

                while (1) {

                    int usersChoice;

                    cout << " " << "[INP] Select a Snack for Deletion: ";
                    cin >> usersChoice;
                    while (cin.fail()) {
                        cinError();
                        inpErr();
                        cout << " " << "[INP] Select a Snack for Deletion: ";
                        cin >> usersChoice;
                    }

                    int realRef = usersChoice - 1;

                    if ((usersChoice > 0) && (usersChoice <= savedSnacks.size())) {

                        cout << " " << "[INF] The Snack \"" << savedSnacks[realRef].getName() << " - " << savedSnacks[realRef].getSize() << "\" has been selected" << "\n"
                             << "\n"
                             << " " << "====================================================" << "\n"
                             << "\n"
                             << " " << "[SYS] The Snack \"" << savedSnacks[realRef].getName() << " - " << savedSnacks[realRef].getSize() <<  "\" has been successfully deleted" << endl;

                        savedSnacks.erase(savedSnacks.begin() + realRef);

                        progStop();
                        clrscreen();

                        break;
                    }

                    else {
                        inpErr();
                    }

                }

                menuSelector = 326;
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

}

void viewSales (int& menuSelector, vector<Transaction>& transactionTracker) {

    if (transactionTracker.empty()) {

        mainProgHeader();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE SALES" << "\n";
        cout << " " << "====================================================" << "\n"
             << " " << "                    MANAGE SALES                    " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[ERR] No recent transactions recorded               " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        progStop();
        menuSelector = 3;
        clrscreen();

    }

    else {

        mainProgHeader();

        cout << " " << "HOME >> ADMIN MODE >> MANAGE SALES" << "\n";
        cout << " " << "====================================================" << "\n"
             << " " << "                    MANAGE SALES                    " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[1] View Sales                                      " << "\n"
             << " " << "[2] View All Transactions                           " << "\n"
             << " " << "[0] Admin Mode                                      " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        while (1) {

            int usersMenu;
            cout << " " << "[INP] Select Option: ";
            cin >> usersMenu;
            while (cin.fail()) {
                cinError();
                inpErr();
                cout << " " << "[INP] Select Option: ";
                cin >> usersMenu;
            }

            if (usersMenu == 1) {

                clrscreen();

                unsigned int transactions = transactionTracker.size();

                int totalSales;

                for (unsigned int realRef = 0; realRef < transactions; realRef++) {

                    totalSales = totalSales + transactionTracker[realRef].getEarnings();

                }

                mainProgHeader();

                cout << " " << "HOME >> ADMIN MODE >> MANAGE SALES >> VIEW SALES" << "\n";

                cout << " " << "====================================================" << "\n"
                     << " " << "                     VIEW SALES                     " << "\n"
                     << " " << "====================================================" << "\n"
                     << " " << "Transaction(s) : " << transactionTracker.size() << "\n"
                     << " " << "Total Sales    : Php " << totalSales << "\n"
                     << " " << "====================================================" << "\n"
                     << "\n"
                     << " " << "[SYS] Showing Sales Statistics" << "\n";

                progStop();
                clrscreen();
                menuSelector = 33;
                break;

            }

            else if (usersMenu == 2) {

                clrscreen();

                mainProgHeader();

                cout << " " << "HOME >> ADMIN MODE >> MANAGE SALES >> VIEW SALES" << "\n";

                cout << " " << "====================================================" << "\n"
                     << " " << "                  VIEW TRANSACTIONS                 " << "\n"
                     << " " << "====================================================" << "\n"
                     << "\n"
                     << " " << "----------------------------------------------------" << "\n"
                     << " " << "[SYS] Showing all transactions                      " << "\n"
                     << " " << "----------------------------------------------------" << "\n"
                     << endl;

                unsigned int transactions = transactionTracker.size();
                int displayRef = 0;

                for (unsigned int realRef = 0; realRef < transactions; realRef++) {

                    displayRef = displayRef + 1;

                    cout << " " << "----------------------------------------------------" << "\n"
                         << " " << "[INF] Transaction No.  : " << displayRef << "\n"
                         << " " << "----------------------------------------------------" << "\n"
                         << " " << "      Transaction Type : " << transactionTracker[realRef].getType() << "\n"
                         << " " << "      Transaction Name : " << transactionTracker[realRef].getName() << "\n"
                         << " " << "      Price            : Php " << transactionTracker[realRef].getPrice() << "\n"
                         << " " << "      Quantity         : " << transactionTracker[realRef].getQuantity() << "\n"
                         << " " << "      Earnings         : Php " << transactionTracker[realRef].getEarnings() << "\n"
                         << " " << "----------------------------------------------------" << "\n"
                         << endl;

                }


                int totalSales;

                for (unsigned int realRef = 0; realRef < transactions; realRef++) {

                    totalSales = totalSales + transactionTracker[realRef].getEarnings();

                }

                cout << " " << "====================================================" << "\n"
                     << " " << "Transaction(s) : " << transactionTracker.size() << "\n"
                     << " " << "Total Sales    : Php " << totalSales << "\n"
                     << " " << "====================================================" << "\n"
                     << "\n"
                     << " " << "[SYS] Showing Sales Statistics" << "\n";

                progStop();
                clrscreen();
                menuSelector = 33;
                break;

            }

            else if (usersMenu ==0) {

                clrscreen();
                menuSelector = 3;
                break;

            }

            else {

                inpErr();

            }

        }

    }

}

void accountSettings (int& menuSelector, vector<string>& adminCredentials) {

    mainProgHeader();

    cout << " " << "HOME >> ADMIN MODE >> ACCOUNT SETTINGS" << "\n"
         << " " << "====================================================" << "\n" 
         << " " << "                  ACCOUNT SETTINGS                  " << "\n"
         << " " << "====================================================" << endl;

    string user, pass;

    cin.clear();
    fflush(stdin);

    cout << " " << "USERNAME : ";
    getline (cin, user);

    cout << " " << "PASSWORD : ";
    getline (cin, pass);

    if ((user == adminCredentials[0]) && (pass == adminCredentials[1])) {

        system ("color 0a");
        cout << " " << "====================================================" << "\n"
             << "\n"
             << " " << "[SYS] Login Successful" << endl;

        progStop();

        clrscreen();
        system("color 0e");

        mainProgHeader();
        cout << " " << "HOME >> ADMIN MODE >> ACCOUNT SETTINGS" << "\n"
             << " " << "====================================================" << "\n" 
             << " " << "                  ACCOUNT SETTINGS                  " << "\n"
             << " " << "====================================================" << "\n" 
             << " " << "[1] Change Username                                 " << "\n"
             << " " << "[2] Change Password                                 " << "\n"
             << " " << "[0] Admin Mode                                      " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        while (1) {

            int usersChoice;

            cout << " " << "Select Option: ";
            cin >> usersChoice;
            while (cin.fail()) {
                cinError();
                inpErr();
                cout << " " << "Select Option: ";
                cin >> usersChoice;
            }

            if (usersChoice == 1) {

                clrscreen();

                mainProgHeader();

                cout << " " << "HOME >> ADMIN MODE >> ACCOUNT SETTINGS >> CHANGE USERNAME" << "\n"
                     << " " << "====================================================" << "\n" 
                     << " " << "                  ACCOUNT SETTINGS                  " << "\n"
                     << " " << "====================================================" << "\n";

                string newUser, repnewUser;

                cin.clear();
                fflush(stdin);

                cout << " " << "[INP] New Username     : ";
                getline (cin, newUser);

                cout << " " << "[INP] Confirm Username : ";
                getline (cin, repnewUser);

                if (newUser == repnewUser) {

                    cout << " " << "====================================================" << "\n"
                         << endl;

                    cout << " " << "[SYS] Username successfully changed" << endl;

                    adminCredentials[0] = newUser;

                }

                else {

                    cout << " " << "====================================================" << "\n"
                         << endl;

                    cout << " " << "[ERR] Process unsuccessful" << endl;

                }

                progStop();
                clrscreen();

                menuSelector = 3;

                break;
            }

            else if (usersChoice == 2) {

                clrscreen();

                mainProgHeader();

                cout << " " << "HOME >> ADMIN MODE >> ACCOUNT SETTINGS >> CHANGE PASSWORD" << "\n"
                     << " " << "====================================================" << "\n" 
                     << " " << "                  ACCOUNT SETTINGS                  " << "\n"
                     << " " << "====================================================" << "\n"; 

                string newPass, repnewPass;

                cin.clear();
                fflush(stdin);

                cout << " " << "[INP] New Password     : ";
                getline (cin, newPass);

                cout << " " << "[INP] Confirm Password : ";
                getline (cin, repnewPass);

                if (newPass == repnewPass) {

                    cout << " " << "====================================================" << "\n"
                         << endl;

                    cout << " " << "[SYS] Password successfully changed" << endl;

                    adminCredentials[1] = newPass;

                }

                else {

                    cout << " " << "====================================================" << "\n"
                         << endl;

                    cout << " " << "[ERR] Process unsuccessful" << endl;

                }

                progStop();
                clrscreen();

                menuSelector = 3;

                break;

            }

            else if (usersChoice == 0) {

                clrscreen();
                menuSelector = 3;
                break;

            }

            else {

                inpErr();

            }

        }

    }

    else {

        system ("color 0c");
        cout << " " << "====================================================" << "\n"
             << "\n"
             << " " << "[ERR] Login Unsuccessful | Wrong Credentials" << endl;

        progStop();
        clrscreen();
        menuSelector = 3;

    }

}

void bookMovie (int& menuSelector, vector<Film>& savedFilms, vector<Transaction>& salesCounter)  {

    if (savedFilms.empty()) {

        mainProgHeader();

        cout << " " << "HOME >> MAIN MODE >> BOOK MOVIE" << "\n"
             << " " << "====================================================" << "\n"
             << " " << "                     BOOK MOVIE                     " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[ERR] No movies available                       " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        progStop();
        clrscreen();
        menuSelector = 1;

    }

    else {

        mainProgHeader();

        cout << " " << "HOME >> MAIN MODE >> BOOK MOVIE" << "\n"
             << " " << "====================================================" << "\n"
             << " " << "                     BOOK MOVIE                     " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[1] Book Movie                                      " << "\n"
             << " " << "[0] Main Mode                                       " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        while (1) {

            int usersMenu;

            cout << " " << "[INP] Select Option: ";
            cin >> usersMenu;
            while (cin.fail()) {
                cinError();
                inpErr();
                cout << " " << "[INP] Select Option: ";
                cin >> usersMenu;
            }

            if (usersMenu == 1) {

                int numFilms = savedFilms.size();
                int verifier = 0;
                int displayRef = 1;

                for (int i = 0; i < numFilms; i++) {

                    if ((savedFilms[i].getStatus()) && (!savedFilms[i].availableSeats.empty())) {
                        verifier = verifier + 1;
                    }

                }

                if (verifier == 0) {

                    clrscreen();

                    mainProgHeader();

                    cout << " " << "HOME >> MAIN MODE >> BOOK MOVIE" << "\n"
                        << " " << "====================================================" << "\n"
                        << " " << "                     BOOK MOVIE                     " << "\n"
                        << " " << "====================================================" << "\n"
                        << " " << "[ERR] No movies are available                       " << "\n"
                        << " " << "====================================================" << "\n"
                        << endl;

                        progStop();

                }

                else {

                    clrscreen();

                    mainProgHeader();

                    cout << " " << "HOME >> MAIN MODE >> BOOK MOVIE" << "\n"
                         << " " << "====================================================" << "\n"
                         << " " << "                     BOOK MOVIE                     " << "\n"
                         << " " << "====================================================" << "\n"
                         << "\n"
                         << " " << "----------------------------------------------------" << "\n"
                         << " " << "[SYS] Showing all available movies                  " << "\n"
                         << " " << "----------------------------------------------------" << "\n"
                         << endl;

                    displayRef = 0;

                    for (int i = 0; i < numFilms; i++) {

                        displayRef = displayRef + 1;


                        if (!savedFilms[i].getStatus()) {
                            cout << " " << "----------------------------------------------------" << "\n";
                            if (displayRef < 10) {
                            cout << " " << "[0" << displayRef << "] Movie         : " << savedFilms[i].getTitle() << " (" << savedFilms[i].getYear() << ")" << "\n";
                            }
                            else {
                            cout << " " << "[" <<  displayRef << "] Movie         : " << savedFilms[i].getTitle() << " (" << savedFilms[i].getYear() << ")" << "\n";
                            }
                            cout << " " << "     Status        : Currently Not Showing          " << "\n";
                            cout << " " << "----------------------------------------------------" << "\n";
                            cout << endl;
                        }

                        else if (savedFilms[i].availableSeats.empty()) {
                            cout << " " << "----------------------------------------------------" << "\n";
                            if (displayRef < 10) {
                            cout << " " << "[0" << displayRef << "] Movie         : " << savedFilms[i].getTitle() << " (" << savedFilms[i].getYear() << ")" << "\n";
                            }
                            else {
                            cout << " " << "[" <<  displayRef << "] Movie         : " << savedFilms[i].getTitle() << " (" << savedFilms[i].getYear() << ")" << "\n";
                            }                                       
                            cout << " " << "     Status        : Fully Booked                   " << "\n";
                            cout << " " << "----------------------------------------------------" << "\n";
                            cout << endl;
                        }

                        else {

                           cout << " " << "----------------------------------------------------" << "\n";
                            if (displayRef < 10) {
                            cout << " " << "[0" << displayRef << "] Movie         : " << savedFilms[i].getTitle() << " (" << savedFilms[i].getYear() << ")" << "\n";
                            }
                            else {
                            cout << " " << "[" <<  displayRef << "] Product       : " << savedFilms[i].getTitle() << " (" << savedFilms[i].getYear() << ")" << "\n";
                            }
                            cout << " " << "     Status        : " << savedFilms[i].availableSeats.size() << " seat(s) Available" << "\n";
                            cout << " " << "----------------------------------------------------" << "\n";
                            cout << " " << "     Film Title    : " << savedFilms[i].getTitle() << "\n"
                                 << " " << "     Film Director : " << savedFilms[i].getDirector() << "\n"
                                 << " " << "     Released Date : " << savedFilms[i].getYear() << "\n"
                                 << " " << "     Ticket Price  : Php " << savedFilms[i].getPrice() << "\n"
                                 << " " << "----------------------------------------------------" << "\n"
                                 << endl;

                        }

                    }
            
                    
                    while (1) {

                        int chosenFilm;

                        cout << " " << "[INP] Choose Movie: ";
                        cin >> chosenFilm;
                        while (cin.fail()){
                            cinError();
                            inpErr();
                            cout << " " << "[INP] Choose Movie: ";
                            cin >> chosenFilm;                            
                        }

                        int realRef = chosenFilm - 1;

                        if ((savedFilms[realRef].getStatus()) && (!savedFilms[realRef].availableSeats.empty())) {

                            cout << " " << "[INF] You selected " << savedFilms[realRef].getTitle() << " (" << savedFilms[realRef].getYear() << ")" << "\n"
                                 << "\n"
                                 << " " << "====================================================" << "\n"
                                 << "\n"
                                 << " " << "[SYS] Book sequence initiated" << endl;
                            
                            progStop();

                            clrscreen();

                            mainProgHeader();

                            cout << " " << "HOME >> MAIN MODE >> BOOK MOVIE" << "\n"
                                << " " << "=======================================================================================================" << "\n"
                                << " " << "                                              BOOK MOVIE                                               " << "\n"
                                << " " << "=======================================================================================================" << "\n"
                                << "\n"
                                << " " << "-------------------------------------------------------------------------------------------------------" << "\n"
                                << " " << "[SYS] Generating Seats Visual" << "\n"
                                << " " << "-------------------------------------------------------------------------------------------------------" << "\n"
                                << endl;

                            int availableSeats = savedFilms[realRef].availableSeats.size();

                            int vectorite = 0;

                            for (int Seats = 1; Seats <= savedFilms[realRef].getSeats(); Seats++) {
                                
                                

                                if (Seats < 10) {

                                    if (Seats == 1) {
                                        cout << " ";
                                    }
                                
                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[00" << Seats << "]";
                                        vectorite++;
                                    }

                                }
                                    
                                else if (Seats == 10) {

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[0" << Seats << "]";
                                        vectorite++;
                                    }

                                    cout << "   ";
                                }

                                else if (Seats >= 11 && Seats <= 20) {

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[0" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 20) {
                                        cout << endl;
                                    }
                                    
                                }

                                else if (Seats >= 21 && Seats <= 30) {

                                    if (Seats == 21) {
                                        cout << " ";
                                    }


                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[0" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 30) {
                                        cout << "   ";
                                    }
                                    
                                }

                                else if (Seats >= 31 && Seats <= 40) {


                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[0" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 40) {
                                        cout << endl;
                                    }
                                    
                                }

                                else if (Seats >= 41 && Seats <= 50) {

                                    if (Seats == 41) {
                                        cout << " ";
                                    }


                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[0" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 50) {
                                        cout << "   ";
                                    }
                                    
                                }

                                else if (Seats >= 51 && Seats <= 60) {

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[0" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 60) {
                                        cout << endl;
                                    }
                                    
                                }

                                else if (Seats >= 61 && Seats <= 70) {

                                    if (Seats == 61) {
                                        cout << " ";
                                    }


                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[0" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 70) {
                                        cout << "   ";
                                    }
                                    
                                }

                                else if (Seats >= 71 && Seats <= 80) {

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[0" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 80) {
                                        cout << endl;
                                    }
                                    
                                }

                                else if (Seats >= 81 && Seats <= 90) {


                                    if (Seats == 81) {
                                        cout << " ";
                                    }


                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[0" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 90) {
                                        cout << "   ";
                                    }
                                    
                                }

                                else if (Seats >= 91 && Seats <= 99) {


                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[0" << Seats << "]";
                                        vectorite++;
                                    }
                                    
                                }

                                else if (Seats == 100) {

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[" << Seats << "]";
                                        vectorite++;
                                    }

                                    cout << endl << endl;

                                }

                                else if (Seats >= 101 && Seats <= 110) {

                                    if (Seats == 101) {
                                        cout << " ";
                                    }

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 110) {
                                        cout << "   ";
                                    }
                                    
                                }

                                else if (Seats >= 111 && Seats <= 120) {

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 120) {
                                        cout << endl;
                                    }
                                    
                                }

                                else if (Seats >= 121 && Seats <= 130) {

                                    if (Seats == 121) {
                                        cout << " ";
                                    }

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 130) {
                                        cout << "   ";
                                    }
                                    
                                }

                                else if (Seats >= 131 && Seats <= 140) {

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 140) {
                                        cout << endl;
                                    }
                                    
                                }

                                else if (Seats >= 141 && Seats <= 150) {

                                    if (Seats == 141) {
                                        cout << " ";
                                    }

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 150) {
                                        cout << "   ";
                                    }
                                    
                                }

                                else if (Seats >= 151 && Seats <= 160) {

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 160) {
                                        cout << endl;
                                    }
                                    
                                }

                                else if (Seats >= 161 && Seats <= 170) {

                                    if (Seats == 161) {
                                        cout << " ";
                                    }

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 170) {
                                        cout << "   ";
                                    }
                                    
                                }

                                else if (Seats >= 171 && Seats <= 180) {

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 180) {
                                        cout << endl;
                                    }
                                    
                                }

                                else if (Seats >= 181 && Seats <= 190) {

                                    if (Seats == 181) {
                                        cout << " ";
                                    }

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 190) {
                                        cout << "   ";
                                    }
                                    
                                }

                                else if (Seats >= 191 && Seats <= 200) {

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 200) {
                                        cout << endl << endl;
                                    }
                                    
                                }

                                else if (Seats >= 201 && Seats <= 210) {

                                    if (Seats == 201) {
                                        cout << " ";
                                    }

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 210) {
                                        cout << "   ";
                                    }
                                    
                                }

                                else if (Seats >= 211 && Seats <= 220) {

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 220) {
                                        cout << endl;
                                    }
                                    
                                }

                                else if (Seats >= 221 && Seats <= 230) {

                                    if (Seats == 221) {
                                        cout << " ";
                                    }

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 230) {
                                        cout << "   ";
                                    }
                                    
                                }

                                else if (Seats >= 231 && Seats <= 240) {

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 240) {
                                        cout << endl;
                                    }
                                    
                                }

                                else if (Seats >= 241 && Seats <= 250) {

                                    if (Seats == 241) {
                                        cout << " ";
                                    }

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 250) {
                                        cout << "   ";
                                    }
                                    
                                }

                                else if (Seats >= 251 && Seats <= 260) {

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 260) {
                                        cout << endl;
                                    }
                                    
                                }

                                else if (Seats >= 261 && Seats <= 270) {

                                    if (Seats == 261) {
                                        cout << " ";
                                    }

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 270) {
                                        cout << "   ";
                                    }
                                    
                                }

                                else if (Seats >= 271 && Seats <= 280) {

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 280) {
                                        cout << endl;
                                    }
                                    
                                }

                                else if (Seats >= 281 && Seats <= 290) {

                                    if (Seats == 281) {
                                        cout << " ";
                                    }

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[" << Seats << "]";
                                        vectorite++;
                                    }

                                    if (Seats == 290) {
                                        cout << "   ";
                                    }
                                    
                                }

                                else if (Seats >= 291 && Seats <= 300) {

                                    if (Seats != savedFilms[realRef].availableSeats[vectorite]) {
                                        cout << "[***]";
                                    }
                                    else {
                                        cout << "[" << Seats << "]";
                                        vectorite++;
                                    }

                                    
                                }

                            }


                            cout << endl << endl;
                            cout << " " << "-------------------------------------------------------------------------------------------------------" << "\n"
                                 << endl;

                            while (10) {

                                int chosenSeat;

                                cout << " " << "[INP] Select Seat : ";
                                cin >> chosenSeat;
                                while(cin.fail()) {
                                    cinError();
                                    inpErr();
                                cout << " " << "[INP] Select Seat : ";
                                cin >> chosenSeat;
                                }

                                int verification = 0;

                                for (int i = 0; i < savedFilms[realRef].availableSeats.size(); i++) {

                                    if (savedFilms[realRef].availableSeats[i] == chosenSeat) {
                                        verification = verification + 1;
                                    }

                                }

                                if (verification == 1) {

                                    cout << " " << "[INF] You selected seat number " << chosenSeat << "\n"
                                         << "\n"
                                         << " " << "-------------------------------------------------------------------------------------------------------" << "\n"
                                         << " " << "[SYS] Generating Receipt" << "\n"
                                         << " " << "-------------------------------------------------------------------------------------------------------" << "\n"
                                         << " " << "      Film Title    : " << savedFilms[realRef].getTitle() << "\n"
                                         << " " << "      Film Director : " << savedFilms[realRef].getDirector() << "\n"
                                         << " " << "      Year Released : " << savedFilms[realRef].getYear() << "\n"
                                         << " " << "      Ticket Price  : Php " << savedFilms[realRef].getYear() << "\n"
                                         << " " << "      Quantity      : 1" << "\n"
                                         << " " << "      Total         : Php " << savedFilms[realRef].getPrice() << "\n"
                                         << " " << "-------------------------------------------------------------------------------------------------------" << "\n"
                                         << "\n"
                                         << " " << "=======================================================================================================" << "\n"
                                         << "\n"
                                         << " " << "[SYS] Purchasing... " << "\n"
                                         << " " << "[SYS] Purchased Successful" << "\n";


                                    Transaction transaction("Movie", savedFilms[realRef].getTitle(), savedFilms[realRef].getPrice(), 1, savedFilms[realRef].getPrice());
                                    transactionTracker.push_back(transaction);


                                    for (int i = 0; i < savedFilms[realRef].availableSeats.size(); i++) {

                                        if (savedFilms[realRef].availableSeats[i] == chosenSeat) {
                                            savedFilms[realRef].availableSeats.erase(savedFilms[realRef].availableSeats.begin() + i);
                                        }

                                    }

                                    progStop();
                                    break;

                                }

                                else {

                                    inpErr();

                                }

                            }


                            break;

                        }

                        else {

                            inpErr();

                        }

                    }
                    
                }

                clrscreen();
                menuSelector = 11;
                break;

            }

            else if (usersMenu == 0) {

                clrscreen();
                menuSelector = 1;
                break;

            }

        }

    }

}



void buySnacks (int& menuSelector, vector<Snack>& savedSnacks , vector<Transaction>& salesCounter) {

    if (savedSnacks.empty()) {

        mainProgHeader();

        cout << " " << "HOME >> MAIN MODE >> BUY MOVIE SNACKS" << "\n"
             << " " << "====================================================" << "\n"
             << " " << "                    MOVIE SNACKS                    " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[ERR] No snacks available                       " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        progStop();
        clrscreen();
        menuSelector = 1;

    }

    else {

        mainProgHeader();

        cout << " " << "HOME >> MAIN MODE >> BUY MOVIE SNACKS" << "\n"
             << " " << "====================================================" << "\n"
             << " " << "                    MOVIE SNACKS                    " << "\n"
             << " " << "====================================================" << "\n"
             << " " << "[1] Buy Snacks                                      " << "\n"
             << " " << "[0] Main Mode                                       " << "\n"
             << " " << "====================================================" << "\n"
             << endl;

        while (1) {

            int menuChoice;

            cout << " " << "[INP] Select Option: ";
            cin >> menuChoice;
            while (cin.fail()) {
                cinError();
                inpErr();
                cout << " " << "[INP] Select Option: ";
                cin >> menuChoice;
            }

            if (menuChoice == 1) {

                int numSnacks = savedSnacks.size();
                int verifier = 0;
                int displayRef = 1;

                for (int i = 0; i < numSnacks; i++) {

                    if ((savedSnacks[i].getStatus()) && (savedSnacks[i].getQuantity() > 0)) {
                        verifier = verifier + 1;
                    }

                }

                if (verifier == 0) {

                    clrscreen();

                    mainProgHeader();

                    cout << " " << "HOME >> MAIN MODE >> BUY MOVIE SNACKS" << "\n"
                        << " " << "====================================================" << "\n"
                        << " " << "                    MOVIE SNACKS                    " << "\n"
                        << " " << "====================================================" << "\n"
                        << " " << "[ERR] No snacks are available                       " << "\n"
                        << " " << "====================================================" << "\n"
                        << endl;

                        progStop();

                }

                else {

                    clrscreen();

                    mainProgHeader();

                    cout << " " << "HOME >> MAIN MODE >> BUY MOVIE SNACKS" << "\n"
                         << " " << "====================================================" << "\n"
                         << " " << "                    MOVIE SNACKS                    " << "\n"
                         << " " << "====================================================" << "\n"
                         << "\n"
                         << " " << "----------------------------------------------------" << "\n"
                         << " " << "[SYS] Showing all available snacks                  " << "\n"
                         << " " << "----------------------------------------------------" << "\n"
                         << endl;

                    displayRef = 0;

                    for (int i = 0; i < numSnacks; i++) {

                        displayRef = displayRef + 1;


                        if (!savedSnacks[i].getStatus()) {
                            cout << " " << "----------------------------------------------------" << "\n";
                            if (displayRef < 10) {
                            cout << " " << "[0" << displayRef << "] Product       : " << savedSnacks[i].getProduct() << "\n";
                            }
                            else {
                            cout << " " << "[" <<  displayRef << "] Product       : " << savedSnacks[i].getProduct() << "\n";
                            }
                            cout << " " << "     Status        : Not Available                  " << "\n";
                            cout << " " << "----------------------------------------------------" << "\n";
                            cout << endl;
                        }

                        else if (savedSnacks[i].getQuantity() <= 0) {
                            cout << " " << "----------------------------------------------------" << "\n";
                            if (displayRef < 10) {
                            cout << " " << "[0" << displayRef << "] Product       : " << savedSnacks[i].getProduct() << "\n";
                            }
                            else {
                            cout << " " << "[" <<  displayRef << "] Product       : " << savedSnacks[i].getProduct() << "\n";
                            }
                            cout << " " << "     Status        : Out of Stock                   " << "\n";
                            cout << " " << "----------------------------------------------------" << "\n";
                            cout << endl;
                        }

                        else {

                           cout << " " << "----------------------------------------------------" << "\n";
                            if (displayRef < 10) {
                            cout << " " << "[0" << displayRef << "] Product       : " << savedSnacks[i].getProduct() << "\n";
                            }
                            else {
                            cout << " " << "[" <<  displayRef << "] Product       : " << savedSnacks[i].getProduct() << "\n";
                            }
                            cout << " " << "     Status        : Available                      " << "\n";
                            cout << " " << "----------------------------------------------------" << "\n";
                            cout << " " << "     Product Name  : " << savedSnacks[i].getName() << "\n"
                                 << " " << "     Product Size  : " << savedSnacks[i].getSize() << "\n"
                                 << " " << "     Product Price : Php " << savedSnacks[i].getPrice() << "\n"
                                 << " " << "     Quantity      : " << savedSnacks[i].getQuantity() << "\n"
                                 << " " << "----------------------------------------------------" << "\n"
                                 << endl;

                        }

                    }

                    cout << " " << "====================================================" << "\n"
                         << endl;

                    while (1) {

                        int usersChosen;
                        cout << " " << "[INP] Select a Snack: ";
                        cin >> usersChosen;
                        while (cin.fail()){
                            cinError();
                            inpErr();
                            cout << " " << "[INP] Select a Snack: ";
                            cin >> usersChosen;
                        }

                        int realRef = usersChosen - 1;

                        if ((savedSnacks[realRef].getStatus()) && (savedSnacks[realRef].getQuantity() > 0)) {

                            cout << " " << "[INF] You selected " << savedSnacks[realRef].getProduct() << "\n"
                                 << "\n"
                                 << " " << "====================================================" << "\n"
                                 << "\n"
                                 << " " << "[SYS] Buying sequence initialized" << "\n";

                                progStop();
                                clrscreen();
                                mainProgHeader();

                                cout << " " << "HOME >> MAIN MODE >> BUY MOVIE SNACKS" << "\n"
                                     << " " << "====================================================" << "\n"
                                     << " " << "                    MOVIE SNACKS                    " << "\n"
                                     << " " << "====================================================" << "\n"
                                     << "\n"
                                     << " " << "[SYS] Buying Product " << savedSnacks[realRef].getProduct() << "\n"
                                     << endl;

                                cout << " " << "----------------------------------------------------" << "\n";
                                    if (displayRef < 10) {
                                    cout << " " << "[0" << displayRef << "] Product       : " << savedSnacks[realRef].getProduct() << "\n";
                                    }
                                    else {
                                    cout << " " << "[" <<  displayRef << "] Product       : " << savedSnacks[realRef].getProduct() << "\n";
                                    }
                                cout << " " << "     Status        : Available                      " << "\n";
                                cout << " " << "----------------------------------------------------" << "\n";
                                cout << " " << "     Product Name  : " << savedSnacks[realRef].getName() << "\n"
                                     << " " << "     Product Size  : " << savedSnacks[realRef].getSize() << "\n"
                                     << " " << "     Product Price : Php " << savedSnacks[realRef].getPrice() << "\n"
                                     << " " << "     Quantity      : " << savedSnacks[realRef].getQuantity() << "\n"
                                     << " " << "----------------------------------------------------" << "\n"
                                     << "\n"
                                     << " " << "====================================================" << "\n"
                                     << endl;

                                     while (1) {

                                        int quantity;

                                        cout << " " << "[INP] Enter quantity of " << savedSnacks[realRef].getProduct() << " you want to Buy: ";
                                        cin >> quantity;
                                        while (cin.fail()) {
                                            cinError();
                                            inpErr();
                                        cout << " " << "[INP] Enter quantity of " << savedSnacks[realRef].getProduct() << " you want to Buy: ";
                                        cin >> quantity;
                                        }

                                        if ((quantity <= savedSnacks[realRef].getQuantity()) && (quantity >=0)) {


                                            cout << " " << "[INF] You want to buy " << quantity << " " << savedSnacks[realRef].getProduct() << "\n"
                                                 << "\n"
                                                 << " " << "====================================================" << "\n"
                                                 << "\n"
                                                 << " " << "[SYS] Buying..." << "\n"
                                                 << " " << "[INF] Purchase complete " << "\n"
                                                << "\n"
                                                 << " " << "====================================================" << "\n"
                                                 << endl;

                                            int total = savedSnacks[realRef].getPrice() * quantity;

                                            cout << " " << "----------------------------------------------------" << "\n"
                                                 << " " << "[SYS] Transaction Receipt" << "\n"
                                                 << " " << "----------------------------------------------------" << "\n"
                                                 << " " << "      Product      : " << savedSnacks[realRef].getProduct() << "\n"
                                                 << " " << "      Price        : Php " << savedSnacks[realRef].getPrice() << "\n"
                                                 << " " << "      Quantity     : " << quantity << "\n"
                                                 << " " << "      Total Amount : Php " << total << "\n"
                                                 << " " << "----------------------------------------------------" << "\n"
                                                 << "\n"
                                                 << " " << "====================================================" << "\n"
                                                 << "\n"
                                                 << " " << "[SYS] Buy Sequence Completed " << endl;

                                            savedSnacks[realRef].setQuantity(savedSnacks[realRef].getQuantity() - quantity);

                                            Transaction transaction("Snack", savedSnacks[realRef].getProduct(), savedSnacks[realRef].getPrice(), quantity, total);
                                            transactionTracker.push_back(transaction);

                                            progStop();

                                            break;

                                        }

                                        else {

                                            inpErr();

                                        }

                                    }

                            break;
                        }

                        else {

                            inpErr();

                        }

                    }

                }

                clrscreen();
                menuSelector = 12;
                break;

            }

            else if (menuChoice == 0) {

                clrscreen();
                menuSelector = 1;
                break;

            }

            else {

                inpErr();

            }

        }

    }

}