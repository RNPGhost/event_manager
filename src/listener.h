#pragma once

#include "event_listener.h"
#include "event_manager.h"
#include <iostream>

template <typename T>
class Listener : public EventListener
{
public:
    virtual void Trigger(const void* event_info) {
      EventListener::Trigger(event_info);
      const T* info = static_cast<const T*>(event_info);
      if (info != nullptr)
      {
        std::cout << *info << "\n";
      }
      else
      {
        std::cout << "Baz\n";
      }
    }
};
