#include "listener.h"
#include "event_manager.h"
#include <iostream>

int main() {
  Listener<int> foo_listener;
  Listener<const char*> bar_listener;
  Listener<> baz_listener;
  
  EventManager<FOO, int> foo_event_manager;
  EventManager<BAR, const char*> bar_event_manager;
  EventManager<BAZ> baz_event_manager;

  foo_event_manager.AddListener(&foo_listener);
  bar_event_manager.AddListener(&bar_listener);
  baz_event_manager.AddListener(&baz_listener);

  foo_event_manager.Trigger(43); 
  bar_event_manager.Trigger("Event message");
  baz_event_manager.Trigger();
}
