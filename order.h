#ifndef ORDER_H
#define ORDER_H
#include "customer.h"
#include "item.h"
#include <vector>
#include <string>

class order {
    customer* orderingCustomer;
    vector<item> orderItems;
    string orderTime;
public:
    order(customer* orderingCustomer, string time);
    void addItemToOrder(item add);
    void removeItemFromOrder(item remove);
    customer* getCustomer() const;
    string getOrderTime() const;
    vector<item> getVec() const;
};

std::ostream& operator<<(std::ostream& o, const order& sb);

#endif