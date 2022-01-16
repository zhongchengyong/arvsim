//
// Created by zhong on 12/19/21.
//

#include "fetch.hh"
#include "processor.hh"

#include "pipeline.hh"

using namespace arv_core;

void Fetch::Tick() {
  std::vector<uint8_t> data;
//  m_processor.m_mmu.Read(m_pc, 4, data);
  uint64_t instr = m_processor.m_mmu.FetchInstr(0x80000000, 4);
  m_fetch_struct.opcodes.push_back(instr);
}

Fetch::Fetch(arv_core::O3Processor &processor, addr_t pc) : m_processor{processor},
                                                            m_pc{pc},
                                                            m_fetch_struct(processor.FromFetch()) {}

