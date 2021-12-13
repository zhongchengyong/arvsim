#ifndef ARVSIM_SRC_SIM_SIMULATOR_H_
#define ARVSIM_SRC_SIM_SIMULATOR_H_
#include "event.h"

#include "dev/device.h"
#include "dev/mmu.h"
#include "core/kernel.h"

#include <string>

namespace arv_sim {

using TickEvent = EventWrapper<arv_core::Processor, &arv_core::Processor::Process>;
using TickEventPtr = std::unique_ptr<TickEvent>;
using ProcessorUP = std::unique_ptr<arv_core::Processor>;

class Simulator {
 public:
  Simulator();
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
};

}  // namespace arv_sim
#endif //ARVSIM_SRC_SIM_SIMULATOR_H_
