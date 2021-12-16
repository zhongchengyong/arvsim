//
// Created by zhong on 9/20/21.
//

#ifndef ARVSIM_SRC_PROCESSOR_HH_
#define ARVSIM_SRC_PROCESSOR_HH_

#include "common/sim_define.hh"
#include "common/logger.hh"

#include <string>

namespace arv_core {

/**
 * @brief The base processor class.
 */
class Processor {
 public:
  virtual void Process() = 0;
  virtual std::string Name() const = 0;
  virtual ~Processor() = default;

  /**
   * Statistic for processor.
   */
  struct Stat {
    /**
     * Counting processor cycle.
     */
    cycle_t m_cycle;

    /**
     * Counting retired instructions.
     */
    size_t m_inst;
  } m_stat;
 private:
};

/**
 * @brief Functional model processor
 */
class AtomicProcessor : public Processor {
 public:
  void Process() override;
  std::string Name() const override {
    return "Atomic";
  }
  ~AtomicProcessor() override = default;
};

/**
 * @brief Out-of-order CPU model.
 */
class O3Processor : public Processor {
 public:
  void Process() override;
  std::string Name() const override {
    return "Out-of-order";
  }
  ~O3Processor() override = default;
};
} // namespace arv_core

#endif //ARVSIM_SRC_PROCESSOR_HH_
