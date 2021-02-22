#include "movie.h"

film::film(){
    StoredYear = 0;
    StoredPrice = 0.00;
}

film::~film(){

}

film::film(string newTitle, string newDirector, int newYear, double newPrice){
    StoredTitle = newTitle;
    StoredDirector = newDirector;
    StoredYear = newYear;
    StoredPrice = newPrice;
    StoredStatus = true;
}



string film::getTitle() const{
    return StoredTitle;
}

string film::getDirector() const{
    return StoredDirector;
}

int film::getYear() const{
    return StoredYear;
}

double film::getPrice() const{
    return StoredPrice;
}

bool film::getStatus() const{
    return StoredStatus;
}




void film::setTitle(string newTitle){
    StoredTitle = newTitle;
}

void film::setDirector(string newDirector){
    StoredDirector = newDirector;
}

void film::setYear(int newYear){
    StoredYear = newYear;
}

void film::setPrice(double newPrice){
    StoredPrice = newPrice;
}

void film::setStatus(bool newStatus){
    StoredStatus = newStatus;
}

