/* Template specialization */
/* 1. Full Specialization: specify a class for a specific style. */
/* 2. Partial Specialization: Specializes only some template parameters. */
/* 3. Multiple Parameter Specialization: Specializes a combination of types. */

#include <iostream>

template <typename T>
class Base {
private:
    T _data;
public:
    Base(T val) : _data(val) {}

    void showData(void) {
        std::cout << "Data is:" << _data << std::endl;
    }
};

template<>
class Base<int> {
private:
    int _data;
public:
    Base(int val) : _data(val) {}
    void showData(void) {
        std::cout << "Data integer is: " << _data << std::endl;
    }
};

class I2CMsg {
public:
    int _addr;
    int _value;
    I2CMsg(int addr, int val) : _addr(addr), _value(val) {}
    I2CMsg() {}
};

template<>
class Base<I2CMsg> {
private:
    I2CMsg _data;
public:
    Base(I2CMsg val) : _data(val) {}
    void showData(void) {
        std::cout << "I2C data is: Addr=0x" << std::hex << _data._addr << " Data=0x" << std::hex << _data._value << std::endl;
    }
};

int main(int argc, char** argv) {
    Base<int> num(5);
    I2CMsg msg(0x12, 0xff);
    Base<I2CMsg> data(msg);

    num.showData();
    data.showData();
    return 0;
}