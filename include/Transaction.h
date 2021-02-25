#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Transaction
{
    public:
        //default Constructor
        Transaction();

        //Overload Constructor
        Transaction(string, string, int, int, int);

        //Deconstructor
        virtual ~Transaction();

        //Accessor Functions
        string  getType() const;
        string  getName() const;
        string  getSchedule() const;
        int     getPrice() const;
        int     getQuantity() const;
        int     getEarnings() const;

        //Mutator Functions
        void    setType(string);
        void    setName(string);
        void    setSchedule (string);
        void    setPrice (int);
        void    setQuantity (int);
        void    setEarnings (int);

    private:
        string  storedType;
        string  storedName;
        string  storedSchedule;
        int     storedPrice;
        int     storedQuantity;
        int     storedEarnings;

};

#endif // TRANSACTION_H
