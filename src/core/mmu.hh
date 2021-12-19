#ifndef ARVSIM_SRC_DEV_MMU_HH_
#define ARVSIM_SRC_DEV_MMU_HH_

#include "dev/device.hh"
#include "common/types.hh"

/**
 * m_memory management unit.
 * No virtual address and address mapping yet.
 */
namespace arv_core {

class MMU {
 public:
  explicit MMU(arv_dev::Memory& memory);
  bool Write(addr_t addr, size_t len, const uint8_t *bytes);
  void Read(addr_t addr, size_t len, std::vector<uint8_t>& data);
 private:
  arv_dev::Memory& m_memory;
};

}

#endif //ARVSIM_SRC_DEV_MMU_HH_
