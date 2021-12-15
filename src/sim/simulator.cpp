#include "simulator.hh"
#include "elfloader.hh"

#include "dev/device.hh"
#include "common/sim_define.hh"

using namespace arv_sim;

GlobalSimLoopExitEvent *simulate_limit_event = nullptr;

Simulator::Simulator() : m_memory{}, m_mmu{m_memory} {
  TickEventPtr tick_event = std::make_unique<TickEvent>(std::make_unique<arv_core::AtomicProcessor>());
  m_event_q.Schedule(std::move(tick_event), 0);
}

void Simulator::LoadPayload(const std::string &file_name) {
  reg_t entry;
  arv_sim::LoadElf(file_name.c_str(), &m_mmu, &entry);
}

void Simulator::Run(size_t n) {
  EventPtr event_ptr = m_event_q.DeSchedule();
  event_ptr->Process();
  m_event_q.Schedule(std::move(event_ptr), event_ptr->GetWhen() + 1);
}
