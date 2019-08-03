#include "sock_client.hpp"
#include "exceptions.hpp"

#include "data_form.h"

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

// TODO :
void Client::send(void * buf, size_t size) const {
    if (write(servSock, buf, size) == -1)
        throw SocketException(WRITE);
}

void Client::receive(void * buf, size_t size) const {
    if (read(servSock, buf, size) == -1)
        throw SocketException(READ);
}

void Client::exit() const {
    RequestData  request;
    ResponseData response;

    request.command = REQUEST_EXIT;
    send(&request, sizeof(request));
    shutdown(servSock, SHUT_WR);

    receive(&response, sizeof(response));

    if (response.command != RESPONSE_EXIT)
        throw SocketException(EXIT_FAILED);
}
