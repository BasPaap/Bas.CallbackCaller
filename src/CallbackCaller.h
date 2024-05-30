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
        using instance_pointer_t = void*;
        using simple_callback_t = void(*)();
        using instance_callback_t = void(*)(instance_pointer_t);

        private:
        simple_callback_t simpleCallback;
        instance_callback_t instanceCallback;
        instance_pointer_t instance;

        public:
        void begin(simple_callback_t callback);
        void begin(instance_callback_t callback, instance_pointer_t instance);
        void call();
    };
}

#endif