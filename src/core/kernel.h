//
// Created by zhong on 9/20/21.
//

#ifndef ARVSIM_SRC_KERNEL_H_
#define ARVSIM_SRC_KERNEL_H_

namespace arv_core {

/**
 * @brief The base processor class.
 */
class Processor {
 public:
  virtual void Process() = 0;
};

/**
 * @brief Functional model processor
 */
class AtomicProcessor : Processor {
 public:
 private:
  void Process() override;
};
} // namespace arv_core

#endif //ARVSIM_SRC_KERNEL_H_
