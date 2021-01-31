#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>

using namespace std;

enum class payment {CASH, CARD}; //CASH = 0, CARD = 1

class customer {
    string _name;
    string _seat;
    payment _payMethod;
public:
    customer(string seat, payment payMethod, string name);
    string getSeat() const;
    int getPaymentMethod() const;
    void setSeat(string customerSeat);
    void setPaymentMethod(int method);
    void setName(string n);
    string getName() const;
};

std::ostream& operator<<(std::ostream& o, const customer& sb);

#endif