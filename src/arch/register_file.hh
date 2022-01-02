//
// Created by zhong on 1/2/22.
//

#ifndef ARVSIM_SRC_ARCH_REGISTER_FILE_HH_
#define ARVSIM_SRC_ARCH_REGISTER_FILE_HH_

#include <cstdint>
#include <array>

/**
 * @brief Register file definition.
 */
template<typename T, int N, bool is_fp>
class RegisterFile {
 public:
  void Write(uint32_t idx, T value) {
    if constexpr(!is_fp) {
      if (idx == 0) return;
    }
    data[idx] = value;
  }

  const T &operator[](uint32_t idx) const {
    return data[idx];
  }

  /**
   * @brief Reset register_file value.
   */
  void Reset() {
    data.fill(0);
  }
 private:
  std::array<T, N> data;
};

#endif //ARVSIM_SRC_ARCH_REGISTER_FILE_HH_
