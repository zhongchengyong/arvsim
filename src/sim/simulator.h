#ifndef ARVSIM_SRC_SIM_SIMULATOR_H_
#define ARVSIM_SRC_SIM_SIMULATOR_H_
#include "event.h"

#include "dev/device.h"
#include "dev/mmu.h"
#include "core/kernel.h"

#include <string>

namespace arv_sim {

using ProcessorUP = std::unique_ptr<arv_core::Processor>;
GlobalSimLoopExitEvent *simulate_limit_event = nullptr;

class Simulator {
 public:
  Simulator(ProcessorUP processor_up);
  /**
   * @brief Load program.
   */
  void LoadPayload(const std::string& file_name);

  /**
   * @brief Step n cycles.
   */
  void Run(size_t n);



 private:
  arv_dev::Memory m_memory;
  arv_dev::MMU m_mmu;
  EventQueue m_event_q;
  ProcessorUP m_processor_ptr;
};

}  // namespace arv_sim
#endif //ARVSIM_SRC_SIM_SIMULATOR_H_
