#ifndef MYLIB02_H
#define MYLIB02_H

#include <iostream>
#include <cstdint>

enum I2CType {
    TEMP_SENSOR,
    ACC_SENSOR,
    MOTION_SENSOR,
    UNASSIGNED,
};

class I2CDevice {
private:
    uint16_t addr;
    uint8_t data;
    I2CType type = I2CType::UNASSIGNED;
public:
    I2CDevice(void);
    I2CDevice(I2CType type, uint16_t addr, uint8_t data);
    ~I2CDevice(void);
    uint16_t getAddress(void);
    uint16_t getData(void);
    void setAddress(uint16_t addr);
    void setData(uint8_t data);
};

#endif
