#include "mylib02.h"

int main(int argc, char **argv)
{
  I2CDevice device (I2CType::MOTION_SENSOR, 0x69, 0xFF);
  std::cout << "Address = 0x" << std::hex << device.getAddress() << " data = 0x" << std::hex << device.getData() << std::endl;
  return 0;
}