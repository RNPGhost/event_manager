#include "event_listener.h"

#include <iostream>

void EventListener::Trigger(const void* event_info)
{
    std::cout << "Event Triggered\n";
}
