#include "menu.h"
using namespace std;

//Constructor:
menu::menu(string type) : menuType(type) {}

//Getters/Setters:
string menu::getMenuType() const {return menuType;}
void menu::setMenuType(string type) {menuType = type;}
vector<item> menu::getVec() const {return items;}

//Public functions
void menu::addItem(item newItem) {items.push_back(newItem);}

void menu::removeItem(string t) {
    if (isdigit(t.at(0))) { //By Barcode
        // bool found = false;
        // for (size_t i = 0; i < items.size(); ++i) {
        //     if (items.at(i).getBarcode() == t) {
        //         items.erase(items.begin()+i); 
        //         found = true;
        //         break;
        //     }
        // }
        // if (!found) {throw invalid_argument("[ERROR]: Item is not present on selected menu." );} //[TODO]: ADD TRY/CATCH

    } else { //By name
        bool found = false;
        for (size_t i = 0; i < items.size(); ++i) {
            if (items.at(i).getName() == t) {
                items.erase(items.begin()+i); 
                found = true;
                break;
            }
        }
        if (!found) {throw invalid_argument("[ERROR]: Item is not present on selected menu." );} //[TODO]: ADD TRY/CATCH
    }
}

// void menu::displayItems() {
//     for (size_t i = 0; i < items.size(); ++i) {
//         cout << items.at(i);
//     }
// }

std::ostream& operator<<(std::ostream& o, const menu& sb)
{
    for(item i : sb.getVec())
    {
        o << i;
    }
}