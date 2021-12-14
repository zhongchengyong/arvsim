//
// Created by zhong on 12/12/21.
//

#include "event.hh"

using namespace arv_sim;

void EventQueue::Schedule(EventPtr event_ptr, cycle_t when) {
  event_ptr->SetWhen(when);
  m_event_q.push_back(std::move(event_ptr));
}

EventPtr EventQueue::DeSchedule() {
  EventPtr event_ptr = std::move(m_event_q.front());
  m_event_q.pop_front();
  return std::move(event_ptr);
}
