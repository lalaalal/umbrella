#ifndef __SOCK_CLIENT__
#define __SOCK_CLIENT__

#include <string>

#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include "data_form.h"

class Client {
private:
    int         servSock;
    sockaddr_in servAddr;
public:
    Client(const char * SQL_HOST_NAME, const int PORT_NUM);
    ~Client();
    void send(void * buf, size_t size) const;
    void receive(void * buf, size_t size) const;
};

#endif
