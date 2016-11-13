#include "bar_listener.h"

#include <iostream>

void BarListener::Trigger(const void* event_info)
{
    EventListener::Trigger(event_info);
    const char* event_message = static_cast<const char*>(event_info);
    if (event_message != nullptr)
    {
        std::cout << event_message << std::endl;
    }
    else
    {
        // Wasn't passed any event info
        std::cout << "No message passed!\n";
    }
}
