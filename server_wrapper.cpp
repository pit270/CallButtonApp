#include "server_wrapper.h"

using namespace rapidjson;

vector<order*>* g_orderList;

Server_Wrapper::Server_Wrapper(int port = 65123)
{
    pipe_ret_t startRet = _server.start(port);
    if(!startRet.success)
    {
        throw std::runtime_error("Server did not start successfully");
    }

    std::cout << "TCP server online" << std::endl;

    _observer.incoming_packet_func = onIncomingMsg;
    // _observer.disconnected_func = 
    _observer.wantedIp = "";
    _server.subscribe(_observer);
}

void Server_Wrapper::update()
{
    Client client = _server.acceptClient(1);
    // std::cout << client.isConnected() << std::endl;
    if(client.isConnected() == 1)
    {
        std::cout << "connected: " << client.getIp() << std::endl;
        //send menu
    }
}

void onIncomingMsg(const Client& client, char * msg, size_t size)
{
    std::string msgStr = msg;
    // print the message content
    std::cout << "Observer got client msg: " << msgStr << std::endl;

    //TODO: error checking
    Document doc;
    doc.Parse(msg);
    // std::cout << "parse" << std::endl;
    if(doc.HasMember("order"))
    {
        // std::cout << "if" << std::endl;
        string seatNum = doc["seat"].GetString();
        payment payType = static_cast<payment>(doc["payment"].GetInt());
        string time = doc["time"].GetString();
        string name = doc["name"].GetString();
        // std::cout << payType << std::endl;
        const Value& orderjson = doc["order"];
        customer* custobj = new customer(seatNum, payType, name);
        order* orderobj = new order(custobj, time);
        for(auto& v : orderjson.GetArray())
        {
            // std::cout << "loop" << std::endl;
            item itobj = item(v["quantity"].GetInt(), v["name"].GetString(), v["type"].GetString());
            // std::cout << "test: " << itobj;
            orderobj->addItemToOrder(itobj);
        }
        g_orderList->push_back(orderobj);

    }

    for(size_t i = 0; i < size; i++)
    {
        msg[i] = '\0';
    }
}

