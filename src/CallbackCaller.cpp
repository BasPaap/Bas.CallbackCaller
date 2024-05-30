#include "CallbackCaller.h"

void Bas::CallbackCaller::begin(simple_callback_t callback)
{
    // Store the function pointer for later use.
    this->simpleCallback = callback;
}

void Bas::CallbackCaller::begin(instance_callback_t callback, instance_pointer_t instance)
{
    // Store the function pointer and a pointer to the class instance for later use.
    this->instanceCallback = callback;
    this->instance = instance;
}

void Bas::CallbackCaller::call()
{
    // If the simple function pointer is set, call it.
    if (this->simpleCallback)
    {
        this->simpleCallback();
    }

    // If the pointer to the instance callback and the pointer to the instance are set,
    // call the callback and pass it the pointer to the instance.
    if (this->instanceCallback && this->instance)
    {
        this->instanceCallback(this->instance);
    }
}
