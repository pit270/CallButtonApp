#include "customer.h"

//Constructor:
customer::customer(string seat, payment method, string name) : _name(name), _seat(seat), _payMethod(method) {}

//getters/setters:
string customer::getSeat() const {return _seat;}
int customer::getPaymentMethod() const {return (static_cast<int>(_payMethod));} 
void customer::setSeat(string customerSeat) {_seat = customerSeat;}
void customer::setPaymentMethod(int method) {_payMethod = static_cast<payment>(method);}
void customer::setName(string n) {_name = n;}
string customer::getName() const {return _name;}

std::ostream& operator<<(std::ostream& o, const customer& sb)
{
    // o << "test2" << endl;
    o << sb.getName() << ":" << sb.getSeat() << ":" << sb.getPaymentMethod();
    return o;
}