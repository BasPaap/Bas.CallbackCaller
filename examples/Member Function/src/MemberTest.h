#ifndef TEST_h
#define TEST_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include <CallbackCaller.h>

class MemberTest
{
    Bas::CallbackCaller callbackCaller;

    public:
    void actualMemberCallback();
    static void staticCallback(MemberTest instance);

    void begin();
    void raiseCallback();
};

#endif