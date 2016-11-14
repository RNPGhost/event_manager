#pragma once

#include <iostream>
#include <vector>

enum EventType
{
    FOO,
    BAR,
    BAZ
};

// Event listener that returns event info of type T on Trigger
template<typename T = void>
class EventListener {
  public:
    virtual void Trigger(T event_info) {
      std::cout << "Event Triggered\n";
    }
};
// Event listener that does not return any event info on Trigger
template<>
class EventListener<void> {
  public:
    virtual void Trigger() {
      std::cout << "Event Triggered\n";
    }
};

// Event manager that passes event info of type EventInfoType on Trigger
template<EventType event_type, typename EventInfoType = void>
class EventManager {
  public:
    void AddListener(EventListener<EventInfoType>* event_listener) {
      event_listeners_.push_back(event_listener);
      std::cout << "Event Listener Added\n";
    }

    void Trigger(EventInfoType event_info) {
      for (unsigned int i = 0; i < event_listeners_.size(); i++) {
        event_listeners_[i]->Trigger(event_info);
      }
    }
  private:
    std::vector<EventListener<EventInfoType>*> event_listeners_;
};
// Event manager that does not pass event info on Trigger
template<EventType event_type>
class EventManager<event_type, void> {
  public:
    void AddListener(EventListener<>* event_listener) {
      event_listeners_.push_back(event_listener);
      std::cout << "Event Listener Added\n";
    }

    void Trigger() {
      for (unsigned int i = 0; i < event_listeners_.size(); i++) {
        event_listeners_[i]->Trigger();
      }
    }
  private:
    std::vector<EventListener<>*> event_listeners_;
};

