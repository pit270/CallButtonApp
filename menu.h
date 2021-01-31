#ifndef MENU_H
#define MENU_H

#include "item.h"
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

class menu {
    vector<item> items;
    string menuType;
public:
    menu(string type);
    string getMenuType() const;
    void setMenuType(string type);
    void addItem(item newItem);
    void removeItem(string t);
    void displayItems();
    vector<item> getVec() const;
};

//bool operator==(const item& lhs, const item& rhs);

std::ostream& operator<<(std::ostream& o, const menu& sb);


#endif