//
// Created by zhong on 12/19/21.
//

#ifndef ARVSIM_SRC_CORE_FETCH_HH_
#define ARVSIM_SRC_CORE_FETCH_HH_

#include "pipeline.hh"

#include "common/types.hh"

#include <memory>

namespace arv_core {

class O3Processor;
/**
 * Fetch stage.
 */
class Fetch {
 public:
  explicit Fetch(O3Processor& processor, addr_t pc);
  void Tick();

 private:
  O3Processor& m_processor;
  addr_t m_pc;
  FetchStruct& m_fetch_struct;
};

}  // namespace arv_core

#endif //ARVSIM_SRC_CORE_FETCH_HH_
