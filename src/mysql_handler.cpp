#include "mysql_handler.hpp"
#include "sql_usr_info.h"
// MySQL user name, password

#include <cppconn/resultset.h>

#include <iostream>
#include <string>

MysqlHandler::MysqlHandler(std::string hostName, std::string dbName) {
    driver = get_driver_instance();

    connection = driver->connect(hostName, SQL_USER, SQL_PASSWD);
    connection->setSchema(dbName);

    statement = connection->createStatement();
}

MysqlHandler::~MysqlHandler() {
    delete connection;
    delete statement ;
}

sql::ResultSet * MysqlHandler::query(std::string query) {
    return statement->executeQuery(query);
}
