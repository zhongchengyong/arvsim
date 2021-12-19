//
// Created by zhong on 9/20/21.
//

#ifndef ARVSIM_SRC_PROCESSOR_HH_
#define ARVSIM_SRC_PROCESSOR_HH_

#include "common/types.hh"
#include "common/logger.hh"

#include "fetch.hh"
#include "decode.hh"
#include "rename.hh"
#include "iew.hh"
#include "rename.hh"
#include "commit.hh"
#include "mmu.hh"

#include <string>

namespace arv_core {

/**
 * @brief The base processor class.
 */
class Processor {
 public:
  Processor(MMU& mmu) : m_mmu{mmu} {}
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
  MMU& m_mmu;
 private:
};

/**
 * @brief Functional model processor
 */
class AtomicProcessor : public Processor {
 public:
  explicit AtomicProcessor(MMU& mmu) : Processor(mmu) {}
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
  explicit O3Processor(MMU& mmu);
  void Process() override;
  void Tick();
  std::string Name() const override {
    return "Out-of-order";
  }
  ~O3Processor() override = default;
 private:
  Fetch m_fetch;
  Decode m_decode;
  Rename m_rename;
  IEW m_iew;
  Commit m_commit;
};
} // namespace arv_core

#endif //ARVSIM_SRC_PROCESSOR_HH_
