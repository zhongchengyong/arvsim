#include "mmu.hh"

#include <iostream>

using namespace arv_dev;

MMU::MMU(Memory &memory) : m_memory(memory) {}

bool MMU::Write(addr_t addr, size_t len, const uint8_t *bytes) {
  return m_memory.Write(addr, len, bytes);
}

