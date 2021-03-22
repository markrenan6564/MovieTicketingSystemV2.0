#ifndef FILM_H
#define FILM_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Film
{
    public:
        //default Constructor
        Film();

        //Overload Constructor
        Film(string, string, int, int, int);

        //Deconstructor
        virtual ~Film();

        //Accessor Functions
        string  getTitle() const;
        string  getDirector() const;
        int     getYear() const;
        int     getPrice() const;
        bool    getStatus() const;
        int     getSeats() const;
        int     getmainSeats() const;

        //Mutator Functions
        void    setTitle(string);
        void    setDirector(string);
        void    setYear (int);
        void    setPrice (int);
        void    setStatus (bool);
        void    setSeats (int);
        void    setmainSeats(int);

        vector<int> availableSeats;

        void    initialReservation (int);

    private:
        string  StoredTitle;
        string  StoredDirector;
        int     StoredYear;
        int     StoredPrice;
        bool    StoredStatus;
        int     StoredSeats;
        int     mainSeats;

};

#endif // FILM_H
