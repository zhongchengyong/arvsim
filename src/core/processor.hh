//
// Created by zhong on 9/20/21.
//

#ifndef ARVSIM_SRC_PROCESSOR_HH_
#define ARVSIM_SRC_PROCESSOR_HH_

#include "fetch.hh"
#include "decode.hh"
#include "rename.hh"
#include "iew.hh"
#include "rename.hh"
#include "commit.hh"
#include "mmu.hh"

#include "common/types.hh"
#include "common/logger.hh"
#include "arch/register_file.hh"

#include <string>

namespace arv_core {

struct State {
  // XPR and FPR
  RegisterFile<uint64_t, 32, false> m_xpr;
  RegisterFile<float, 32, true> m_fpr;
};

/**
 * @brief The base processor class.
 */
class Processor {
 public:
  explicit Processor(MMU &mmu) : m_statistic{}, m_mmu{mmu}, m_state{} {}
  virtual void Process() = 0;
  virtual std::string Name() const = 0;
  virtual ~Processor() = default;

  /**
   * Statistic for processor.
   */
  struct Statistic {
    /**
     * Counting processor cycle.
     */
    cycle_t m_cycle;

    /**
     * Counting retired instructions.
     */
    size_t m_inst;
  } m_statistic;
  MMU &m_mmu;
  State m_state;
};

/**
 * @brief Functional model processor
 */
class AtomicProcessor : public Processor {
 public:
  explicit AtomicProcessor(MMU &mmu) : Processor(mmu) {}
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
  explicit O3Processor(MMU &mmu);
  void Process() override;
  void Tick();
  std::string Name() const override {
    return "Out-of-order";
  }
  ~O3Processor() override = default;
  FetchStruct &FromFetch();
  DecodeStruct &FromDecode();
  RenameStruct &FromRename();
  IEWStruct &FromIEW();
  CommitStruct &FromCommit();
 private:
  TimeBuffer m_time_buffer;
  Fetch m_fetch;
  Decode m_decode;
  Rename m_rename;
  IEW m_iew;
  Commit m_commit;
};
} // namespace arv_core

#endif //ARVSIM_SRC_PROCESSOR_HH_
