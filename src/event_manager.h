#pragma once

#include "event_listener.h"
#include "listener_container.h"

#include <unordered_map>
#include <memory>

enum EventType
{
    FOO,
    BAR,
    BAZ,

    Noof
};

class EventManager
{
public:
    void AddListener(EventType event_type, EventListener* event_listener);
    void Trigger(EventType event_type, const void* event_info = nullptr);
private:
    std::unordered_map<EventType, std::unique_ptr<ListenerContainer>>event_listeners_;
};
