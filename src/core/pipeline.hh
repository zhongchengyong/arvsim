//
// Created by zhong on 12/19/21.
//

#ifndef ARVSIM_SRC_CORE_PIPELINE_H_
#define ARVSIM_SRC_CORE_PIPELINE_H_

#include <vector>
#include <cstdint>

namespace arv_core {

struct FetchStruct {
  std::vector<uint64_t> instrs;
};

struct DecodeStruct {};

struct RenameStruct {};

struct IEWStruct {};

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
