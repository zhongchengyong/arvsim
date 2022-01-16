//
// Created by zhong on 12/19/21.
//

#include "decode.hh"
#include "processor.hh"

using namespace arv_core;

void Decode::Tick() {
  std::deque<uint32_t> &instrs = m_processor.FromFetch().opcodes;
  for (const uint32_t &opcode : instrs) {
    m_processor.FromDecode().instrs.push_back(DoDecode(opcode));
    instrs.pop_front();
  }
}

InstrUP Decode::DoDecode(uint32_t opcode) {
  return std::make_unique<AddInstruction>(m_processor.m_state);
}
