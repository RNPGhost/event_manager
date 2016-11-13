#pragma once

class EventListener
{
public:
    virtual void Trigger(const void* event_info);
};
