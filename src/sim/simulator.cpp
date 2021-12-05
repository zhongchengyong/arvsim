#include "simulator.h"
#include "elfloader.h"
#include "dev/device.h"

#include <iostream>

void Simulator::LoadPayload(const std::string &file_name) {

}

constexpr const char* file_name = "/home/zhong/riscv/riscv-tests/isa/rv64ui-p-addi";

int main() {
  Simulator sim;
  arv_dev::Memory memory;
  arv_dev::MMU mmu(memory);
  reg_t entry;
  arv_sim::LoadElf(file_name, &mmu, &entry);
  std::cout << "main in simulator" << std::endl;
  std::vector<uint8_t> data;
  memory.Read(2147483648, 1148, data);
  for(auto v : data) {
    std::cout << (int)v << std::endl;
  }
}
