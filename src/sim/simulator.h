#ifndef ARVSIM_SRC_SIM_SIMULATOR_H_
#define ARVSIM_SRC_SIM_SIMULATOR_H_
#include "dev/device.h"
#include "dev/mmu.h"

#include <string>

class Simulator {
 public:
  Simulator() : memory{}, mmu(memory) {}
  /**
   * @brief Load program.
   */
  void LoadPayload(const std::string& file_name);

  /**
   * @brief Step n cycles.
   */
  void Run(size_t n);

 private:
  arv_dev::Memory memory;
  arv_dev::MMU mmu;
};

#endif //ARVSIM_SRC_SIM_SIMULATOR_H_
