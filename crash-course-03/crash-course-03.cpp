#include <iostream>

class I2CMsg {
    private:
        unsigned int _addr;
        unsigned int _data;
    
    public:
        I2CMsg(void) {};
        I2CMsg(unsigned int addr, unsigned char data) : _addr(addr), _data(data) {};
    
        I2CMsg operator+ (const I2CMsg & other)
        {
            return I2CMsg(_addr + other._addr, _data + other._data);
        }
    
        bool operator== (const I2CMsg & other)
        {
            return (_addr == other._addr);
        }
        friend std::ostream& operator<< (std::ostream&, I2CMsg &);
};

std::ostream& operator<< (std::ostream& output,
    I2CMsg & that)
{
    return output << "I2C Msg Addr=0x" << std::hex << that._addr << " Data=0x" << std::hex << that._data << std::endl;
}

int main() {
    I2CMsg msg1(0x69, 0x01);
    I2CMsg msg2(0x12, 0x02);

    I2CMsg msg3 = msg1 + msg2;
    
    std::cout << msg1 << msg2 << msg3;

    if (!(msg1 == msg2))
        std::cout << "Not equal" << std::endl;

    return 0;
}
