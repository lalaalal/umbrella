#ifndef __EXCEPTIONS__
#define __EXCEPTIONS__

#include <string>

namespace umbrella {
    enum GENARAL_EXCEPTION {
        WRONG_ARGS  = 0x00,
    };

    class Exception {
    protected:
        int errCode;
    public:
        Exception(int err);
        virtual void print() const;
    };
}

#endif
