/* Abstract class will have only pure virtual method */
/* Non-virtual method will be resolved statically (compile time), 
   meanwhile virtual method will be resolved dynamically (runtime) */

#include <iostream>

class I2CDevice {
protected:
    unsigned int _addr;
    unsigned int _data;
    static int count;
public:
    I2CDevice(void) {}
    virtual ~I2CDevice() {}
    virtual void initializeDevice(unsigned int , unsigned int) = 0;
    virtual void writeData(unsigned int) = 0;
    virtual unsigned int readData() = 0;
};

class MotionSensor : public I2CDevice {
private:
    int type = 1;
public:
    MotionSensor() {};

    void initializeDevice(unsigned int addr, unsigned int data) {
        _data = data;
        _addr = addr;
        std::cout << "Motion sensor created addr=0x" << std::hex << _addr << " data=0x" << std::hex << _data << std::endl;
    }

    void writeData(unsigned int data) {
        _data = data;
        std::cout << "Write data=0x" << std::hex << _data << std::endl;
    }

    unsigned int readData() {
        unsigned int data = 0xff;
        _data = data;
        std::cout << "Read data=0x" << std::hex << _data << std::endl;
        return data;
    }
};

int main(int argc, char** argv) {
    I2CDevice* ptr;
    MotionSensor sensor;
    ptr = &sensor;
    ptr->initializeDevice(0x69, 0x12);
    
    ptr->writeData(0x34);
    int data = ptr->readData();

    return 0;
}