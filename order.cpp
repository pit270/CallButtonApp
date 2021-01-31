#include "order.h"

//Constructor:
order::order(customer* orderingCustomer, string time) : orderingCustomer(orderingCustomer), orderTime(time) {}

//Getters:
customer* order::getCustomer() const {return orderingCustomer;}
string order::getOrderTime() const {return orderTime;}
vector<item> order::getVec() const {return orderItems;}

//Functions:
void order::addItemToOrder(item add) { //[FIXME]
    bool exists = false;
    for (size_t i = 0; i < orderItems.size(); i++) {
        if (orderItems.at(i) == add) {orderItems.at(i).incrementItem(); exists = true;}
    }
    if (!exists) {
        orderItems.push_back(add);
        add.incrementItem();
    }
}

void order::removeItemFromOrder(item remove) {
    for (size_t i = 0; i < orderItems.size(); ++i) {
        if (orderItems.at(i) == remove) {
            orderItems.erase(orderItems.begin()+i); 
            orderItems.at(i).decrementItem();
            break;
        }
    }
}

std::ostream& operator<<(std::ostream& o, const order& sb)
{
    // o << "test1" << endl;
    o << *(sb.getCustomer()) << "\t" << sb.getOrderTime() << endl;
    
    for(item i : sb.getVec())
    {
        o << i;
    }
    o << "___________________";
    return o;
}