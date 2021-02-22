#include "Film.h"

Film::Film(){
    StoredYear = 0;
    StoredPrice = 0.00;
}

Film::~Film(){

}

Film::Film(string newTitle, string newDirector, int newYear, double newPrice){
    StoredTitle = newTitle;
    StoredDirector = newDirector;
    StoredYear = newYear;
    StoredPrice = newPrice;
    StoredStatus = true;
}



string Film::getTitle() const{
    return StoredTitle;
}

string Film::getDirector() const{
    return StoredDirector;
}

int Film::getYear() const{
    return StoredYear;
}

double Film::getPrice() const{
    return StoredPrice;
}

bool Film::getStatus() const{
    return StoredStatus;
}




void Film::setTitle(string newTitle){
    StoredTitle = newTitle;
}

void Film::setDirector(string newDirector){
    StoredDirector = newDirector;
}

void Film::setYear(int newYear){
    StoredYear = newYear;
}

void Film::setPrice(double newPrice){
    StoredPrice = newPrice;
}

void Film::setStatus(bool newStatus){
    StoredStatus = newStatus;
}

