#ifndef __EXCEPTIONS__
#define __EXCEPTIONS__

#include <string>

namespace umbrella {
    enum GENARAL_EXCEPTION {
        WRONG_ARGS   = 0x00,
        WRONG_RESULT = 0x01,
        NOT_INITIALIZED =  0x02
    };

    enum SOCKET_EXCEPTION {
        SOCKET_EXCEPTION = 0x10,

        CREATE  = 0x00,
        BIND    = 0x01,
        CONNECT = 0x02,

        WRITE   = 0x03,
        READ    = 0x04,

        WRONG_DATA    = 0x05,
        NO_CONNECTION = 0x06,
    };

    class Exception {
    protected:
        int errCode;
    public:
        Exception(int err);
        virtual void print() const;
    };

    class SocketException : public Exception {
    public:
        SocketException(int err);
        void print() const override;
    };
}

#endif
