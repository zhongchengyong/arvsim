//
// Created by zhong on 12/12/21.
//

#ifndef ARVSIM_SRC_SIM_EVENT_HH_
#define ARVSIM_SRC_SIM_EVENT_HH_

#include "common/types.hh"

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
  Event() : m_when{0}{}
  virtual void Process() = 0;
  virtual std::string Name() const = 0;
  virtual void SetWhen(cycle_t cycle) noexcept {
    m_when = cycle;
  }
  virtual cycle_t GetWhen() const noexcept {
    return m_when;
  }
  virtual ~Event() = default;
 private:
  /**
   * The Processing cycle.
   */
  cycle_t m_when;
};

/**
 * @brief The exit simulation event.
 */
class GlobalSimLoopExitEvent : public Event {
 public:
  GlobalSimLoopExitEvent() : Event() {}
  void Process() override {}

  std::string Name() const override {
    return "Global_sim.exit_event";
  }
};

/**
 * Event wrapper for arbitrary function.
 */
template<typename T, void (T::* F)()>
class EventWrapper : public Event {
 public:
  EventWrapper() : Event() {}
  explicit EventWrapper(std::shared_ptr<T> obj_ptr) : m_obj_ptr{std::move(obj_ptr)} {}
  void Process() override {
    return (m_obj_ptr.get()->*F)();
  }

  std::string Name() const override {
    return m_obj_ptr->Name() + ".wrap_event";
  }
 private:
  std::shared_ptr<T> m_obj_ptr;
};

/**
 * @brief Use queue to store event.
 */
class EventQueue {
 public:
  void Schedule(EventPtr event_ptr, cycle_t delay = 1);
  EventPtr DeSchedule();
 private:
  std::deque<EventPtr> m_event_q;
};
}  // namespace arv_sim
#endif //ARVSIM_SRC_SIM_EVENT_HH_
