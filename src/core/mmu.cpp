#include "mmu.hh"

using namespace arv_core;
using namespace arv_dev;

MMU::MMU(Memory &memory) : m_memory(memory) {}

bool MMU::Write(addr_t addr, size_t len, const uint8_t *bytes) {
  return m_memory.Write(addr, len, bytes);
}

void MMU::Read(addr_t addr, size_t len, std::vector<uint8_t>& data) {
  m_memory.Read(addr, len, data);
}

