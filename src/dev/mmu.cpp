#include "mmu.h"

#include <iostream>

using namespace arv_dev;

void MMU::Write(arv_common::addr_t addr, size_t len, const void *bytes) {
  std::cout << "Do MMU Write..." << std::endl;
}
