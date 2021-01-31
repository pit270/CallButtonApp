#include "item.h"

//Constructors:
item::item(int amount=0, string name="NO NAME", string type="NO TYPE") 
        : _amount(amount), _name(name), _type(type) {} 
        
//Barcode is used in other functions in "order.cpp"

/*
item::item() : numberInOrder(0), price(0), inventory(0), name("NO NAME"), barcode("NO BARCODE") {}
item::item(int amount=0, int price=0, int inventory=0, string name="NO NAME", string barcode="NO BARCODE") 
        : numberInOrder(amount), price(price), inventory(inventory), name(name), barcode(barcode) {}
*/

//Getters:
// int item::getInventory() const {return inventory;}
// int item::getPrice() const {return price;}
string item::getName() const {return _name;}
// string item::getBarcode() const {return barcode;}
string item::getType() const {return _type;}
int item::getQuantity() const {return _amount;}
//int item::getNumInOrder() const {return numberInOrder;}

//Setters:
// void item::setPrice(int p) {price = p;}
// void item::setInventory(int inv) {inventory = inv;}
void item::setName(string n) {_name = n;}
// void item::setBarcode(string bc) {barcode = bc;}
void item::setType(string t) {_type = t;}
//void item::setNumInOrder(int n) {numberInOrder = n;}

//Operators:
std::ostream& operator<<(std::ostream& o, const item& sb) {
//     string p, inv;
//     stringstream ss; 
    
//     ss << sb.getInventory();
//     inv = ss.str();
//     stringstream ss2;
//     ss2 << sb.getPrice();
//     p = ss2.str();

//     o << sb.getName() << ": " << inv << " available, " << "$" << p << "each, " << sb.getBarcode() << endl;
    o << sb.getName() << "\t" << sb.getType() << "\t" << sb.getQuantity() << endl;
    return o;
}

bool item::operator==(const item& rhs) {
    if (_name == rhs.getName()) {return true;} 
        else {return false;}
}

//Functions:
void item::incrementItem() {_amount += 1;}
void item::decrementItem() {if (_amount > 0) {_amount -= 1;}}