#include "modLed.h"
Led::Led(byte pin,String ledname){
   this->pin = pin;
   this->ledname = ledname;
   init();
}

void Led::init() {
  pinMode(pin, OUTPUT);
  this->state = LOW;
  this->off();
}
void Led::on(){
   this->state = HIGH;
   digitalWrite(pin, HIGH);
   this->debug_msg =String(__func__) +":"+this->state;
}
void Led::off() {
  this->state = LOW;
  digitalWrite(pin, LOW);
  this->debug_msg =String(__func__) +":"+this->state;
}
byte Led::getState(){
    return this->state;
  }

void Led::debbuger(){
    this->on();
    Serial<< "LED module:"<<this->ledname<<"->"<<this->debug_msg<<endl;
    delay(1000);
    this->off();
     Serial<< "LED module:"<<this->ledname<<"->"<<this->debug_msg<<endl;
    delay(1000);
}
