//
// Created by zhong on 1/3/22.
//

#ifndef ARVSIM_SRC_ARCH_STATE_HH_
#define ARVSIM_SRC_ARCH_STATE_HH_

#include "register_file.hh"

struct State {
  // XPR and FPR
  RegisterFile<uint64_t, 32, false> m_xpr;
  RegisterFile<float, 32, true> m_fpr;
};


#endif //ARVSIM_SRC_ARCH_STATE_HH_
