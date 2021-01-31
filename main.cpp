#include "console.h"
#include "order.h"
#include "item.h"
#include "customer.h"
#include "server_wrapper.h"
#include <iostream>

using namespace std;


int main() {
    cout << "Server Startup!" << endl;
    g_orderList = new vector<order*>;

    Server_Wrapper s(65123);

    //update loop
    while(true)
    {
        s.update();
        for(size_t i = 0; i < g_orderList->size(); i++)
        {
            // cout << "test" << endl;
            cout << *(g_orderList->at(i)) << endl;
        }
        cout << "+++++++++++++++++++" << endl;
        usleep(1);
    }

}