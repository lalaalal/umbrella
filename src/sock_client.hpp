#ifndef __SOCK_CLIENT__
#define __SOCK_CLIENT__

#include <arpa/inet.h>
#include <sys/socket.h>

class Client {
private:
    int         servSock;
    sockaddr_in servAddr;
public:
    Client(const char * HOST_NAME, const int PORT_NUM);
    ~Client();
    void send(void * buf, size_t size);
    void receive(void * buf, size_t size);
};

#endif
