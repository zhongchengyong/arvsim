//
// Created by zhong on 12/19/21.
//

#include "fetch.hh"
#include "processor.hh"

using namespace arv_core;

void Fetch::Tick() {
  std::vector<uint8_t> data;
//  m_processor.m_mmu.Read(m_pc, 4, data);
  m_processor.m_mmu.Read(0x80000000, 4, data);
  for (const auto v : data) {
    std::cout << (int)v << std::endl;
  }
}

Fetch::Fetch(arv_core::Processor &processor, addr_t pc) : m_processor{processor}, m_pc{pc} {}

