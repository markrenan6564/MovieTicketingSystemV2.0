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
        Transaction(string, string, string, int, int);
        Transaction(string, string, int, int);

        //Deconstructor
        virtual ~Transaction();

        //Accessor Functions
        string  getType() const;
        string  getName() const;
        string  getSchedule() const;
        int     getQuantity() const;
        int     getEarnings() const;

        //Mutator Functions
        void    setType(string);
        void    setName(string);
        void    setSchedule (string);
        void    setQuantity (int);
        void    setEarnings (int);

    private:
        string  storedType;
        string  storedName;
        string  storedSchedule;
        int     storedQuantity;
        int     storedEarnings;

};

#endif // TRANSACTION_H
