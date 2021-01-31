#include "server/include/tcp_server.h"
#include "rapidjson/document.h"
#include <vector>
#include <stdexcept>
#include <iostream>
#include "order.h"
#include "customer.h"
#include "item.h"

#ifndef SERVER_WRAPPER_H
#define SERVER_WRAPPER_H

extern vector<order*>* g_orderList;

class Server_Wrapper
{
    private:
        TcpServer _server;
        server_observer_t _observer;
        
        
        

    public:
        Server_Wrapper(int port);
        void update();
        // void onIncomingMsg(const Client& client, const char * msg, size_t size);
        void onClientDisconnected(const Client& clinet);


};

void onIncomingMsg(const Client& client, char * msg, size_t size);

#endif //SERVER_WRAPPER_H