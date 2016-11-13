#include "listener_container.h"

#include <iostream>

void ListenerContainer::AddListener(EventListener* event_listener)
{
    event_listeners_.push_back(event_listener);
}

void ListenerContainer::Trigger(const void* event_info)
{
    for (unsigned int i = 0; i < event_listeners_.size(); i++)
    {
        event_listeners_[i]->Trigger(event_info);
    }
}
