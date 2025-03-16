#ifndef LIBRARY_H
#define LIBRARY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

struct i2c_msg {
    unsigned int addr;
    unsigned char data;
};

int i2c_send(struct i2c_msg *);

#ifdef __cplusplus
}
#endif

#endif // LIBRARY_H