#include "MemberTest.h"

void MemberTest::actualMemberCallback()
{
    Serial.println("Member callback called!");
}

void MemberTest::staticCallback(MemberTest instance)
{
    instance.actualMemberCallback();
}

void MemberTest::begin()
{
    Serial.println("Attaching callback.");
    this->callbackCaller.begin((Bas::CallbackCaller::instance_callback_t)staticCallback, (Bas::CallbackCaller::instance_pointer_t)this);    
}

void MemberTest::raiseCallback()
{
    Serial.println("Raising callback.");
    this->callbackCaller.call();
}
