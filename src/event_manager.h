#pragma once

#include <iostream>
#include <memory>
#include <vector>

enum EventType
{
    FOO,
    BAR,
    BAZ
};

template<typename T>
class EventListener {
public:
  virtual void Trigger(T event_info) {
    std::cout << "Event Triggered\n";
  }
};

template<EventType event_type, typename EventInfoType>
class EventManager {
public:
    void AddListener(EventListener<EventInfoType>* event_listener)
    {
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
