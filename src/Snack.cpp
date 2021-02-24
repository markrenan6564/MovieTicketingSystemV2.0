#include "Snack.h"

Snack::Snack(){
    StoredPrice = 0;
    StoredQuantity = 0;
}

Snack::~Snack(){

}

Snack::Snack(string newName, string newSize, int newPrice, int newQuantity){
    StoredName = newName;
    StoredSize = newSize;
    StoredPrice = newPrice;
    StoredQuantity = newQuantity;
    StoredStatus = true;
}

string Snack::getProduct () const {
    return StoredName + " - " + StoredSize;
}

string Snack::getName() const{
    return StoredName;
}

string Snack::getSize() const{
    return StoredSize;
}

int Snack::getPrice() const{
    return StoredPrice;
}

int Snack::getQuantity() const{
    return StoredQuantity;
}

bool Snack::getStatus() const{
    return StoredStatus;
}


void Snack::setName(string newName){
    StoredName = newName;
}

void Snack::setSize(string newSize){
    StoredSize = newSize;
}

void Snack::setPrice(int newPrice){
    StoredPrice = newPrice;
}

void Snack::setQuantity(int newQuantity){
    StoredQuantity = newQuantity;
}

void Snack::setStatus(bool newStatus){
    StoredStatus = newStatus;
}
