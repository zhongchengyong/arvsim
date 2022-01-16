//
// Created by zhong on 1/3/22.
//

#ifndef ARVSIM_SRC_ARCH_RESULT_HH_
#define ARVSIM_SRC_ARCH_RESULT_HH_

#include "state.hh"

#include <cstdint>
#include <memory>

class Result;
using ResultUP = std::unique_ptr<Result>;

class Result {
 public:
  virtual void Do() {};
};

/**
 * @brief Record register file result.
 * TODO: latency is need here?
 */
class RfResult : public Result {
 public:
  RfResult(State &state, uint32_t rf, uint64_t value) : m_state{state}, m_rf{rf}, m_value{value} {}
  void Do() override;
 private:
  State &m_state;
  uint32_t m_rf;
  uint64_t m_value;
};

#endif //ARVSIM_SRC_ARCH_RESULT_HH_
