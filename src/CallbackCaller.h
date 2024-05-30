#ifndef CALLBACKCALLER_h
#define CALLBACKCALLER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

namespace Bas
{
    class CallbackCaller
    {
        public:
        using simple_callback_t = void(*)();
        using instance_pointer_t = void*;
        using instance_callback_t = void(*)(instance_pointer_t);

        private:
        simple_callback_t simpleCallback;       // Pointer to a global callback function or lambda
        instance_callback_t instanceCallback; // Pointer to a static callback funciton that will also receive a pointer to the class instance so that it can call a member function.
        instance_pointer_t instance; // Pointer to the instance of the class the required callback is a member of.

        public:
        void begin(simple_callback_t callback); // Overload for attaching a simple global callback function or lambda.
        void begin(instance_callback_t callback, instance_pointer_t instance);  // Overload for attaching a static function that will receive an instance of the class that has the callback as a member function.
        void call(); // Call the attached callbacks
    };
}

#endif