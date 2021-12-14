#ifndef ARVSIM_SRC_DEV_MMU_HH_
#define ARVSIM_SRC_DEV_MMU_HH_

#include "device.hh"
#include "common/sim_define.hh"

/**
 * m_memory management unit.
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

#endif //ARVSIM_SRC_DEV_MMU_HH_
