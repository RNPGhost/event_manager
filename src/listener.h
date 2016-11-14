#pragma once

#include "event_manager.h"
#include <iostream>

template <typename T>
class Listener : public EventListener<T>
{
public:
  virtual void Trigger(T event_info) 
  {
    EventListener<T>::Trigger(event_info);
    std::cout << event_info << "\n";
  }
};
