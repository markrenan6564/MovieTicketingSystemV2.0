#include "Film.h"

Film::Film(){
    StoredYear = 0;
    StoredPrice = 0;
}

Film::~Film(){

}

Film::Film(string newTitle, string newDirector, int newYear, int newPrice, int newSeats){
    StoredTitle = newTitle;
    StoredDirector = newDirector;
    StoredYear = newYear;
    StoredPrice = newPrice;
    StoredSeats = newSeats;
    StoredStatus = true;
    mainSeats = newSeats;
    initialReservation (StoredSeats);
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

int Film::getPrice() const{
    return StoredPrice;
}

bool Film::getStatus() const{
    return StoredStatus;
}

int Film::getSeats() const{
    return StoredSeats;
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

void Film::setPrice(int newPrice){
    StoredPrice = newPrice;
}

void Film::setStatus(bool newStatus){
    StoredStatus = newStatus;
}

void Film::setSeats(int newSeats){
    StoredSeats = newSeats;
    availableSeats.clear();
    initialReservation (newSeats);
}



void Film::initialReservation (int seats) {

    for (int seatRef = 1; seatRef <= seats; seatRef++) {
        availableSeats.push_back(seatRef);
    }

}

