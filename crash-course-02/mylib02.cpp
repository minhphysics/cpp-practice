#include "mylib02.h"

I2CDevice::I2CDevice(void) {
    std::cout << "Warning: I2C Device not initialized" << std::endl;
}

I2CDevice::I2CDevice(I2CType type, uint16_t addr = 0x00, uint8_t data = 0x00): type(type), addr(addr), data(data) {
    std::cout << "I2C Device addr = 0x" << std::hex << addr << " data = 0x" << std::hex << data << std::endl;
}
I2CDevice::~I2CDevice(void) {
    std::cout << "Do nothing" << std::endl;
}
uint16_t I2CDevice::getAddress(void) {
    return this->addr;
}
uint16_t I2CDevice::getData(void) {
    return this->data;
}
void I2CDevice::setAddress(uint16_t addr) {
    this->addr = addr;
}
void I2CDevice::setData(uint8_t data) {
    this->data = data;
}
