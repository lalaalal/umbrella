#include "umbrella_handler.hpp"
#include "exceptions.hpp"
#include "util.hpp"

#include "sql_info.h"

#include <iostream>
#include <string>

using namespace umbrella;

UmbrellaHandler::UmbrellaHandler() : mysql(SQL_HOST_NAME, DATABASE_NAME) {
    printf("UMBRELLA v%d.%d\n", MAJOR_VERSION, MINOR_VERSION);
    printf("\n");
}

UmbrellaHandler::~UmbrellaHandler() { }

void UmbrellaHandler::addBook(std::string title, std::string author, int arduinoID) {
    std::string query = QUERY_ADD_BOOK;
    replacePattern(query, "[TITLE]", title);
    replacePattern(query, "[AUTHOR]", author);
    replacePattern(query, "[ARDUINO_ID]", std::to_string(arduinoID));
    // mysql.query(query);
#ifdef DEBUG
    std::cout << query << std::endl;
#endif
}

void UmbrellaHandler::addArduino(std::string ip, int x, int y, int z) {
    std::string query = QUERY_ADD_ARDUINO;
    replacePattern(query, "[IP]", ip);
    replacePattern(query, "[X]", std::to_string(x));
    replacePattern(query, "[Y]", std::to_string(y));
    replacePattern(query, "[Z]", std::to_string(z));
    // mysql.query(query);
#ifdef DEBUG
    std::cout << query << std::endl;
#endif
}

void UmbrellaHandler::searchBook() {

}

void UmbrellaHandler::findBook(int bookNum) {
    std::string arduinoIP = getArduinoIP(bookNum);

    client = new Client(arduinoIP.c_str(), PORT_NUM);

    RequestData  request ;
    ResponseData response;

    request.command = REQUEST_EXIST;
    request.data    = bookNum      ;

    response = command(request);

    if (response.command == RESPONSE_EXIST) {
        request.command = REQUEST_LED;
        response = command(request);
        std::cout << "BOOK EXISTS" << std::endl;
        if (response.command == RESPONSE_DONE)
            std::cout << "LED ON" << std::endl;
    } else {
        std::cout << "BOOK DOESN'T EXIST" << std::endl;
    }

    delete client;
    client = NULL;
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
    printf("[DEBUG] RequestData.command  : 0x%02X\n", request.command);
    printf("[DEBUG] ResponseData.command : 0x%02X\n", response.command);
#endif

    return response;
}
