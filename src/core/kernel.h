//
// Created by zhong on 9/20/21.
//

#ifndef ARVSIM_SRC_KERNEL_H_
#define ARVSIM_SRC_KERNEL_H_

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
  ~AtomicProcessor() = default;
};
} // namespace arv_core

#endif //ARVSIM_SRC_KERNEL_H_
