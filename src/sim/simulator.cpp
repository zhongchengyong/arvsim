#include "simulator.h"
#include "elfloader.h"

#include "dev/device.h"
#include "common/sim_define.h"

using namespace arv_sim;



GlobalSimLoopExitEvent *simulate_limit_event = nullptr;

Simulator::Simulator() : m_memory{}, m_mmu{m_memory} {
  TickEventPtr tick_event = std::make_unique<TickEvent>(std::make_unique<arv_core::AtomicProcessor>());
  m_event_q.Push(std::move(tick_event));
}

void Simulator::LoadPayload(const std::string &file_name) {
  reg_t entry;
  arv_sim::LoadElf(file_name.c_str(), &m_mmu, &entry);
}

void Simulator::Run(size_t n) {
  EventPtr event_ptr = m_event_q.Pop();
  event_ptr->Process();
  m_event_q.Push(std::move(event_ptr));
}
