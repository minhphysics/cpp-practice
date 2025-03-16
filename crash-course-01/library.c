#include "library.h"

int i2c_send(struct i2c_msg *msg) {
    printf("sending i2c address 0x%x data 0x%x", msg->addr, msg->data);
    return 0;
}