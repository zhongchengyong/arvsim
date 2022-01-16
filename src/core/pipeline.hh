//
// Created by zhong on 12/19/21.
//

#ifndef ARVSIM_SRC_CORE_PIPELINE_H_
#define ARVSIM_SRC_CORE_PIPELINE_H_

#include "arch/instr.hh"

#include <deque>
#include <cstdint>

namespace arv_core {

struct FetchStruct {
  std::deque<uint32_t> opcodes;
};

struct DecodeStruct {
  std::deque<InstrUP> instrs;
};

struct RenameStruct {};

struct IEWStruct {
  std::deque<ResultUP> results;
};

struct CommitStruct {};

struct TimeBuffer {
  FetchStruct m_fetch;
  DecodeStruct m_decode;
  RenameStruct m_rename;
  IEWStruct m_iew;
  CommitStruct m_commit;
};
}

#endif //ARVSIM_SRC_CORE_PIPELINE_H_
