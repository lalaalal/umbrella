#ifndef __UMBRELLA_HANDLER__
#define __UMBRELLA_HANDLER__

#include "mysql_handler.hpp"
#include "sock_client.hpp"

#include <string>

#define PORT_NUM 9814

typedef char DataFrom;

enum COMMAND_NUMBER {
    REQUEST_LED   = 0x00,
    REQUEST_EXIST = 0x01,
    REQUEST_EXIT  = 0x0F,

    RESPONSE_DONE = 0x10,
};

class UmbrellaHandler {
private:
    MysqlHandler mysql ;
    Client     * client;
public:
    UmbrellaHandler();
    ~UmbrellaHandler();
    void findBook(int bookNum);
    std::string getServerHost(int bookNum);
    DataFrom command(DataFrom COMMAND);
};

#endif
