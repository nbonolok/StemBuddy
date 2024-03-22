#ifndef MOD_LED_H
#define MOD_LED_H
#include <Arduino.h>
#include <Streaming.h>
class Led {
private:
    byte pin;
    String debug_msg;
    void init();
public:
     String ledname;
     byte state;
        
public:
    Led(byte pin,String ledname);
    void on();
    void off();
    void debbuger();
    byte getState();
};

#endif
