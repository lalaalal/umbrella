#ifndef __DATA_FORM__
#define __DATA_FORM__

typedef int CommandData;

struct RequestData {
    CommandData command;
    int data;
};

struct ResponseData {
    CommandData command;
};

enum COMMAND_NUMBER {
    REQUEST_LED   = 0x00,
    REQUEST_EXIST = 0x01,
    REQUEST_EXIT  = 0x0F,

    RESPONSE_DONE  = 0x10,
    RESPONSE_EXIST = 0x11,
    RESPONSE_ERR   = 0x1E,
    RESPONSE_EXIT  = 0x1F,
};

#endif
