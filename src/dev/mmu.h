#ifndef ARVSIM_SRC_DEV_MMU_H_
#define ARVSIM_SRC_DEV_MMU_H_

#include "common/sim_define.h"

/**
 * memory management unit.
 */
namespace arv_dev {
class MMU {
 public:
  void Write(arv_common::addr_t addr, size_t len, const void *bytes);

};

}

#endif //ARVSIM_SRC_DEV_MMU_H_
