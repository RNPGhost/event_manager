#pragma once

#include "event_listener.h"

#include <vector>

class ListenerContainer
{
public:
    void AddListener(EventListener*);
    void Trigger(const void* event_info);
private:
    std::vector<EventListener*> event_listeners_;
};
