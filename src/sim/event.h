//
// Created by zhong on 12/12/21.
//

#ifndef ARVSIM_SRC_SIM_EVENT_H_
#define ARVSIM_SRC_SIM_EVENT_H_

#include <deque>
#include <memory>
#include <string>
#include <any>

namespace arv_sim {

class Event;
using EventPtr = std::unique_ptr<Event>;

/**
 * @brief The event-based model, processor simulation and interrupts are modeled by a event.
 */
class Event {
 public:
  virtual void Process() = 0;
  virtual std::string Name() const = 0;
};

/**
 * @brief The exit simulation event.
 */
class GlobalSimLoopExitEvent : public Event {
 public:
  void Process() override {}

  std::string Name() const override {
    return "Global_sim.exit_event";
  }
};

/**
 * Event wrapper for arbitrary function.
 */
template <typename T, void (T::* F)()>
class EventWrapper : public Event {
 public:
  explicit EventWrapper(std::unique_ptr<T> obj_ptr) : m_obj_ptr{std::move(obj_ptr)} {}
  void Process() override {
    return (m_obj_ptr.get()->*F)();
  }

  std::string Name() const override {
    return m_obj_ptr->Name() + ".wrap_event";
  }
 private:
  std::unique_ptr<T> m_obj_ptr;
};


/**
 * @brief Use queue to store event.
 */
class EventQueue {
 public:
  void Push(EventPtr event_ptr);
  EventPtr Pop();
 private:
  std::deque<EventPtr> m_event_q;
};
}  // namespace arv_sim
#endif //ARVSIM_SRC_SIM_EVENT_H_
