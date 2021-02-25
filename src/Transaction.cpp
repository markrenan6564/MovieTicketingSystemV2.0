#include "Transaction.h"

Transaction::Transaction() {

    storedType = "N/A";
    storedName = "N/A";
    storedSchedule = "N/A";
    storedQuantity = 0;
    storedEarnings = 0;

}

Transaction::~Transaction () {

}

Transaction::Transaction (string type, string name, string schedule,int price, int quantity, int earnings) {

    storedType = type;
    storedName = name;
    storedSchedule = schedule;
    storedPrice = price;
    storedQuantity = quantity;
    storedEarnings = earnings;

}

Transaction::Transaction (string type, string name, int price, int quantity, int earnings) {

    storedType = type;
    storedName = name;
    storedSchedule = "N/A";
    storedPrice = price;
    storedQuantity = quantity;
    storedEarnings = earnings;

}

//  Accessors

    string Transaction::getType() const {
        return storedType;
    }

    string Transaction::getName() const {
        return storedName;
    }

    string Transaction::getSchedule() const {
        return storedSchedule;
    }

    int Transaction::getPrice() const {
        return storedPrice;
    }   

    int Transaction::getQuantity() const {
        return storedQuantity;
    }

    int Transaction::getEarnings() const {
        return storedEarnings;
    }



//  Mutators

    void Transaction::setType (string type) {
        storedType = type;
    }

    void Transaction::setName (string name) {
        storedName = name;
    }

    void Transaction::setSchedule (string schedule) {
        storedSchedule = schedule;
    }

    void Transaction::setPrice (int price) {
        storedPrice = price;
    }

    void Transaction::setQuantity (int quantity) {
        storedQuantity = quantity;
    }

    void Transaction::setEarnings (int earnings) {
        storedEarnings = earnings;
    }



