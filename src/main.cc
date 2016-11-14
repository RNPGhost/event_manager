#include "listener.h"
#include "event_manager.h"
#include <iostream>

int main() {
  Listener<int> int_listener;
  Listener<const char*> string_listener;
  Listener<int> null_listener;
  EventManager<FOO, int> foo_event_manager;
  EventManager<BAR, const char*> bar_event_manager;

  foo_event_manager.AddListener(&int_listener);
  bar_event_manager.AddListener(&string_listener);

  foo_event_manager.Trigger(43); 
  bar_event_manager.Trigger("Event message");
}
