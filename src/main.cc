#include "listener.h"
#include "event_manager.h"

#include <iostream>

int main() {
  Listener<int> int_listener;
  Listener<const char*> string_listener;
  Listener<int> null_listener;
  EventManager event_manager;

  const char* message = "Event Message";
  int number = 43;

  event_manager.AddListener(FOO, &int_listener);
  event_manager.AddListener(BAR, &string_listener);
  event_manager.AddListener(BAZ, &null_listener);

  event_manager.Trigger(FOO, &number); 
  event_manager.Trigger(BAR, &message);
  event_manager.Trigger(BAZ);
}
