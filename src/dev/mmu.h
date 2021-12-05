#ifndef ARVSIM_SRC_DEV_MMU_H_
#define ARVSIM_SRC_DEV_MMU_H_

#include "device.h"
#include "common/sim_define.h"

/**
 * memory management unit.
 * No virtual address and address mapping yet.
 */
namespace arv_dev {

class MMU {
 public:
  explicit MMU(Memory& memory);
  bool Write(addr_t addr, size_t len, const uint8_t *bytes);
 private:
  Memory& m_memory;
};

}

#endif //ARVSIM_SRC_DEV_MMU_H_
