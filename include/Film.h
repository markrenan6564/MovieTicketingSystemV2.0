#ifndef FILM_H
#define FILM_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <string>

using namespace std;

class Film
{
    public:
        //default Constructor
        Film();

        //Overload Constructor
        Film(string, string, int, double);

        //Deconstructor
        virtual ~Film();

        //Accessor Functions
        string  getTitle() const;
        string  getDirector() const;
        int     getYear() const;
        double  getPrice() const;
        bool    getStatus() const;

        //Mutator Functions
        void    setTitle(string);
        void    setDirector(string);
        void    setYear (int);
        void    setPrice (double);
        void    setStatus (bool);

    private:
        string  StoredTitle;
        string  StoredDirector;
        int     StoredYear;
        double  StoredPrice;
        bool    StoredStatus;
};

#endif // FILM_H
