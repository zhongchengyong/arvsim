//
// Created by zhong on 12/19/21.
//

#include "iew.hh"
#include "processor.hh"

#include "arch/instr.hh"
void arv_core::IEW::Tick() {
  std::deque<InstrUP> &instrs = m_processor.FromDecode().instrs;
  for (auto &instr : instrs) {
    m_processor.FromIEW().results.push_back(instr->Execute());
    instrs.pop_front();
  }
}
