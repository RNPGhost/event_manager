#include "bar_listener.h"
#include "event_manager.h"

#include <iostream>

int main() {
  BarListener bar_listener;
  EventManager event_manager;

  const char* message = "bar message";

  event_manager.AddListener(BAR, &bar_listener);
  event_manager.Trigger(BAR, message);
  std::cin.get();
}
