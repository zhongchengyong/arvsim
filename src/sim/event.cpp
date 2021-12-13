//
// Created by zhong on 12/12/21.
//

#include "event.h"

using namespace arv_sim;

void EventQueue::Push(EventPtr event_ptr) {
  m_event_q.push_back(std::move(event_ptr));
}

EventPtr EventQueue::Pop() {
  EventPtr event_ptr = std::move(m_event_q.front());
  m_event_q.pop_front();
  return std::move(event_ptr);
}
