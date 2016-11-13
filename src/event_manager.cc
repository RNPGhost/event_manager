#include "event_manager.h"

#include <iostream>


void EventManager::AddListener(EventType event_type, EventListener* event_listener)
{
    if (event_listeners_[event_type] == nullptr)
    {
        event_listeners_[event_type] = std::make_unique<ListenerContainer>();
    }

    event_listeners_[event_type]->AddListener(event_listener);
    std::cout << "Event Listener Added\n";
}

void EventManager::Trigger(EventType event_type, const void* event_info)
{
    event_listeners_[event_type]->Trigger(event_info);
}
