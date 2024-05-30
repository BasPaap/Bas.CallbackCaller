#include <CallbackCaller.h>
#include "src/MemberTest.h"

void setup()
{
    Serial.begin(9600);
    while (!Serial);  // wait for serial port to connect. Needed for native USB port only

    MemberTest test;
    test.begin();
    test.raiseCallback();    
}

void loop()
{
}