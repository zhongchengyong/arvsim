//
// Created by zhong on 12/19/21.
//

#ifndef ARVSIM_SRC_CORE_IEW_H_
#define ARVSIM_SRC_CORE_IEW_H_

#include <memory>

namespace arv_core {

class O3Processor;
/**
 * Rename stage.
 */
class IEW{
 public:
  explicit IEW(O3Processor& processor) : m_processor{processor} {}
  void Tick();

 private:
  O3Processor&  m_processor;
};

}  // namespace arv_core

#endif //ARVSIM_SRC_CORE_IEW_H_
