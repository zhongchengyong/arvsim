#include "simulator.hh"
#include "elfloader.hh"

#include "dev/device.hh"
#include "common/types.hh"

using namespace arv_sim;

GlobalSimLoopExitEvent *simulate_limit_event = nullptr;

Simulator::Simulator() : m_memory{}, m_mmu{m_memory}, m_processor_sp(std::make_shared<arv_core::O3Processor>(m_mmu)) {
  TickEventPtr tick_event = std::make_unique<TickEvent>(m_processor_sp);
  m_event_q.Schedule(std::move(tick_event));
}

void Simulator::LoadPayload(const std::string &file_name) {
  reg_t entry;
  arv_sim::LoadElf(file_name.c_str(), &m_mmu, &entry);
}

void Simulator::Run(size_t n) {
  EventPtr event_ptr = m_event_q.DeSchedule();
  event_ptr->Process();
  m_event_q.Schedule(std::move(event_ptr));
}
