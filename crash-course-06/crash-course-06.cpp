/*
    - Vector: the most efficient sequence containers because contiguous memory is allocalted
    - List: double linked list, use pointer so it is slower than vector
    - Map: combination container from different data type.
*/

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>

class I2CMsg
{
public:
    int _addr;
    int _value;
    I2CMsg(int addr, int val) : _addr(addr), _value(val) {}
    I2CMsg() {}
    friend std::ostream &operator<<(std::ostream &output, I2CMsg &that)
    {
        return output << "{" << std::hex << that._addr << "-" << std::hex << that._value << "}";
    }
};

class I2CBus
{
public:
    std::vector<I2CMsg> I2CMsgVector;
    std::list<I2CMsg> I2CMsgList;
    std::map<std::string, I2CMsg> I2CMsgDesc;

    I2CBus(void) {}
    void appendMsg(I2CMsg msg)
    {
        I2CMsgVector.push_back(msg);
        I2CMsgList.push_back(msg);
    }

    void appendMsg(I2CMsg msg, std::string desc)
    {
        I2CMsgDesc[desc] = msg;
    }

    void deleteMsg(int index)
    {
        if (index < 0 || index >= I2CMsgVector.size())
        {
            std::cerr << "Error: Index out of bounds\n";
            return;
        }
        if (index < 0 || index >= I2CMsgList.size())
        {
            std::cerr << "Error: Index out of bounds\n";
            return;
        }
        if (index < 0 || index >= I2CMsgDesc.size())
        {
            std::cerr << "Error: Index out of bounds\n";
            return;
        }
        auto it1 = I2CMsgVector.begin();
        std::advance(it1, index);
        I2CMsgVector.erase(it1);
        auto it2 = I2CMsgList.begin();
        std::advance(it2, index);
        I2CMsgList.erase(it2);
        auto it3 = I2CMsgDesc.begin();
        std::advance(it3, index);
        I2CMsgDesc.erase(it3);
    }

    void showMsg()
    {

        std::cout << std::endl
                  << "Vector: ";
        for (std::vector<I2CMsg>::iterator iter = I2CMsgVector.begin(); iter != I2CMsgVector.end(); ++iter)
        {
            std::cout << *iter << " ";
        }

        std::cout << std::endl
                  << "List: ";

        for (auto i : I2CMsgList)
        {
            std::cout << i << " ";
        }

        std::cout << std::endl
                  << "Map: ";

        for (auto i = I2CMsgDesc.begin(); i != I2CMsgDesc.end(); i++)
        {
            std::cout << "[" << i->first << ", " << i->second << "]  ";
        }
    }
};

int main()
{

    I2CMsg msg1(0x69, 0x20);
    I2CMsg msg2(0x12, 0x25);
    I2CMsg msg3(0x33, 0xFF);
    I2CBus bus;

    bus.appendMsg(msg1);
    bus.appendMsg(msg2);
    bus.appendMsg(msg3);
    bus.appendMsg(msg1, "first");
    bus.appendMsg(msg2, "second");
    bus.appendMsg(msg3, "third");

    bus.showMsg();

    bus.deleteMsg(2);

    bus.showMsg();

    return 0;
}
