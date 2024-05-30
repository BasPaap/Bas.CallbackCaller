#include "CallbackCaller.h"

void Bas::CallbackCaller::begin(simple_callback_t callback)
{
    this->simpleCallback = callback;
}

void Bas::CallbackCaller::begin(instance_callback_t callback, instance_pointer_t instance)
{
    this->instanceCallback = callback;
    this->instance = instance;
}

void Bas::CallbackCaller::call()
{
    if (this->simpleCallback)
    {
        this->simpleCallback();
    }

    if (this->instanceCallback && this->instance)
    {
        this->instanceCallback(this->instance);
    }
}
