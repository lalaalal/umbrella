#include "sock_client.hpp"
#include "exceptions.hpp"

#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

using namespace umbrella;

Client::Client(const char * HOST_NAME, const int PORT_NUM) {
    servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (servSock == -1)
        throw SocketException(CREATE);

    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family      = AF_INET;
    servAddr.sin_port        = htons(PORT_NUM);
    servAddr.sin_addr.s_addr = inet_addr(HOST_NAME);

    if (connect(servSock, (sockaddr *) &servAddr, sizeof(servAddr)) == -1)
        throw SocketException(CONNECT);
}

Client::~Client() {
    close(servSock);
}

void Client::send(void * buf, size_t size) {
    write(servSock, buf, size);
}

void Client::receive(void * buf, size_t size) {
    read(servSock, buf, size);
}
