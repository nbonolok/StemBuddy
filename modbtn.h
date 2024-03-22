#ifndef MOD_BTN_H
#define MOD_BTN_H
#include <Arduino.h>
#include <Streaming.h>
class Btn {
private:
    byte pin;
    byte state;
    byte lastReading;
    bool  stikyKey = false;
    unsigned long lastDebounceTime = 0;
    unsigned long debounceDelay = 50;
    
 public:
       String btnname;
       bool  btnClick = false;
       int   btnClickCount = 0;   
 public:
           Btn(byte pin,String bname,boolean btnpressed); 
           void init();
           void btnUpdate();
           byte getState();
           bool isBtnPressed();
           bool getStikyKey();
           void setStikyKey(bool key);
           boolean isbuttonClicked(void);
public: 
         String getBtnname();
         void debbuger();
};
#endif
