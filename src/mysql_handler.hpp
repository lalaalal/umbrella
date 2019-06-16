#ifndef __MYSQL_HANDLER__
#define __MYSQL_HANDLER__

#include <mysql_connection.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include <string>

class MysqlHandler {
private:
    sql::Driver     * driver    ;
    sql::Connection * connection;
    sql::Statement  * statement ;
public:
    MysqlHandler(std::string hostName, std::string dbName);
    ~MysqlHandler();
    sql::ResultSet * query(std::string);
};

#endif
