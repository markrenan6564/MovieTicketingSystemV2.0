#ifndef SNACK_H
#define SNACK_H

#include <iostream>
#include <string>

using namespace std;

class Snack
{
    public:
        //default Constructor
        Snack();

        //Overload Constructor
        Snack(string, string, int, int);

        //Deconstructor
        virtual ~Snack();

        //Accessor Functions
        string  getName() const;
        string  getSize() const;
        int     getPrice() const;
        int     getQuantity() const;
        bool    getStatus() const;

        //Mutator Functions
        void    setName (string);
        void    setSize (string);
        void    setPrice (int);
        void    setQuantity (int);
        void    setStatus (bool);

    private:
        string  StoredName;
        string  StoredSize;
        int     StoredPrice;
        int     StoredQuantity;
        bool    StoredStatus;

};

#endif // SNACK_H
