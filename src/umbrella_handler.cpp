#include "umbrella_handler.hpp"
#include "exceptions.hpp"

#include "sql_info.h"

#include <iostream>

using namespace umbrella;

UmbrellaHandler::UmbrellaHandler() : mysql(SQL_HOST_NAME, DATABASE_NAME) {
    printf("UMBRELLA v%d.%d\n", MAJOR_VERSION, MINOR_VERSION);
    printf("\n");
}

UmbrellaHandler::~UmbrellaHandler() { }

void UmbrellaHandler::findBook(int bookNum) {
    std::string arduinoIP = getArduinoIP(bookNum);

    client = new Client(arduinoIP.c_str(), PORT_NUM);

    RequestData  request ;
    ResponseData response;

    request.command = REQUEST_EXIST;
    request.data    = bookNum      ;

    response = command(request);

    if (response.command == RESPONSE_EXIST) {
        // data : true
        request.command = REQUEST_LED;
        response = command(request);
        std::cout << "BOOK EXISTS" << std::endl;
        if (response.command == RESPONSE_DONE)
            std::cout << "LED ON" << std::endl;
    } else {
        // data : false
        std::cout << "BOOK DOESN'T EXIST" << std::endl;
    }
    request.command = REQUEST_EXIT;
    command(request);

    delete client;
    client = NULL;
}

void UmbrellaHandler::searchBook() {
    
}

std::string UmbrellaHandler::getArduinoIP(int bookNum) {
    sql::ResultSet * resultset;
    resultset = mysql.query(QUERY_FIND_ARDUINO_IP);
    if (!resultset->next())
        throw Exception(WRONG_RESULT);

    // TODO : check format
    return resultset->getString(ARDUINO_IP_COL_NAME);
}

ResponseData UmbrellaHandler::command(RequestData & request) {
    if (client == NULL)
        throw SocketException(NO_CONNECTION);

    ResponseData response;

    client->send(&request, sizeof(request));
    client->receive(&response, sizeof(response));

#ifdef DEBUG
    printf("ResponseData.command : 0x%02X\n", response.command);
#endif

    return response;
}
