#include <iostream>
#include "library.h"

int main() {
    std::cout << "Calling C function from C++:" << std::endl;
    struct i2c_msg msg;
    int ret;

    msg.addr = 0x12;
    msg.data = 0xFF;
    ret = i2c_send(&msg);
    return ret;
}
