#include "umbrella_handler.hpp"
#include "exceptions.hpp"

#include "sql_info.h"

#include <iostream>

using namespace umbrella;

UmbrellaHandler::UmbrellaHandler() : mysql(SQL_HOST_NAME, DATABASE_NAME) { }

UmbrellaHandler::~UmbrellaHandler() { }

void UmbrellaHandler::findBook(int bookNum) {
    std::string arduinoIP = getServerHost(bookNum);

    client = new Client(arduinoIP, PORT_NUM);
    DataFrom response = command(REQUEST_EXIST);

    if (response % RESPONSE_DONE) {
        // data : true
        response = command(REQUEST_LED);
        if (response % RESPONSE_DONE)
            std::cout << "LED ON" << std::endl;
    } else {
        // data : false
        std::cout << "BOOK NOT EXIST" << std::endl;
    }
    command(REQUEST_EXIT);

    delete client;
    client = NULL;
}

std::string UmbrellaHandler::getServerHost(int bookNum) {
    sql::ResultSet * resultset;
    resultset = mysql.query(QUERY_FIND_ARDUINO_IP);
    if (!resultset->next())
        throw Exception(WRONG_RESULT);

    // TODO : check format
    return resultset->getString(ARDUINO_IP_COL_NAME);
}

DataFrom UmbrellaHandler::command(DataFrom COMMAND) {
    if (client == NULL)
        throw SocketException(NO_CONNECTION);

    DataFrom buf = 0;

    client->send(&COMMAND, sizeof(DataFrom));
    client->receive(&buf, sizeof(DataFrom));

    if (buf ^ RESPONSE_DONE)
        throw SocketException(WRONG_DATA);

    return buf;
}
