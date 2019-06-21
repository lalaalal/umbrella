#ifndef __UMBRELLA_HANDLER__
#define __UMBRELLA_HANDLER__

#include "mysql_handler.hpp"
#include "sock_client.hpp"

#include "data_form.h"

#include <string>

#define MAJOR_VERSION 0
#define MINOR_VERSION 1

#define PORT_NUM 9814

class UmbrellaHandler {
private:
    MysqlHandler     mysql ;
    sql::ResultSet * result;

    Client * client;
public:
    UmbrellaHandler();
    ~UmbrellaHandler();
    void searchBook();
    void findBook(int bookNum);
    std::string getArduinoIP(int bookNum);
    ResponseData command(RequestData & requestData);
};

#endif
