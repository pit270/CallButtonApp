#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <sstream>

using namespace std;

class item {
private:
    string _type;
    string _name;
    int _amount;
public:
    item();
    item(int amount, string name, string type /*, string barcode*/);
    // int getInventory() const;
    // int getPrice() const;
    string getName() const;
    // string getBarcode() const;
    string getType() const;
    int getQuantity() const;
    // void setPrice(int p);
    // void setInventory(int inv);
    void setName(string n);
    // void setBarcode(string bc);
    void setType(string t);
    void incrementItem();
    void decrementItem();
    bool operator==(const item& rhs);
};


std::ostream& operator<<(std::ostream& o, const item& sb);



#endif