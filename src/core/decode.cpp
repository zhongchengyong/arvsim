//
// Created by zhong on 12/19/21.
//

#include "decode.hh"
#include "processor.hh"

void arv_core::Decode::Tick() {
  std::vector<uint32_t> instrs = m_processor.FromFetch().instrs;
  // Use processor::state_t to init instructions
}
