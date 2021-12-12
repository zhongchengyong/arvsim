#ifndef ARVSIM_SRC_SIM_DEVICE_H_
#define ARVSIM_SRC_SIM_DEVICE_H_

#include "common/sim_define.h"
#include <unordered_map>
#include <array>
#include <vector>

namespace arv_dev {

constexpr const reg_t PAGE_SHFIT = 12;
constexpr const reg_t PAGE_SIZE = 1 << PAGE_SHFIT;
/**
 * External m_memory model
 */
class Memory {
 public:
  Memory() = default;
  Memory(size_t size) : m_size(size){}
  bool Write(addr_t addr, size_t len, const uint8_t *bytes);
  bool Read(addr_t addr, size_t len, std::vector<uint8_t> &data);
  bool LoadStore(addr_t addr, size_t len, std::vector<uint8_t> &bytes, bool store);

 private:
  std::unordered_map<addr_t, std::array<uint8_t, PAGE_SIZE>> m_data;
  size_t m_size;
};

}

#endif //ARVSIM_SRC_SIM_DEVICE_H_
