#ifndef ARVSIM_SRC_SIM_SIMULATOR_HH_
#define ARVSIM_SRC_SIM_SIMULATOR_HH_
#include "event.hh"

#include "dev/device.hh"
#include "core/mmu.hh"
#include "core/processor.hh"

#include <string>

namespace arv_sim {

using TickEvent = EventWrapper<arv_core::Processor, &arv_core::Processor::Process>;
using TickEventPtr = std::unique_ptr<TickEvent>;
using ProcessorSP = std::shared_ptr<arv_core::Processor>;

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
  arv_core::MMU m_mmu;
  ProcessorSP m_processor_sp;
  EventQueue m_event_q;
};

}  // namespace arv_sim
#endif //ARVSIM_SRC_SIM_SIMULATOR_HH_
