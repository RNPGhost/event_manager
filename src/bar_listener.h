#pragma once

#include "event_listener.h"
#include "event_manager.h"

class BarListener : public EventListener
{
public:
    virtual void Trigger(const void* event_info);
};
