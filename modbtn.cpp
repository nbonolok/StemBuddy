#include "modbtn.h"
 Btn::Btn(byte pin,String bname,boolean btnpressed){
     this->pin = pin;
     this->btnname = bname;
     this->stikyKey = btnpressed;
     lastReading = LOW;
     
     init();
     }
   
     void Btn::init(){
       pinMode(pin,INPUT_PULLUP);
       btnUpdate();
      }
     void Btn::btnUpdate()
      {
       
        byte newReading = digitalRead(this->pin);
        
          if(newReading != lastReading){
                 lastDebounceTime =millis();
            }
          if((millis() - lastDebounceTime) > debounceDelay){
                  state = newReading;
            }
       lastReading = newReading;
      
     }
     byte Btn::getState(){
        btnUpdate();
        return state;
     }
     bool Btn::getStikyKey(){
      return this->stikyKey; 
     }
     void Btn::setStikyKey(bool key){
       this->stikyKey = key;  
     }
     bool Btn::isBtnPressed(){
       return (getState() == HIGH);
        
     }
     String Btn::getBtnname(){
      return this->btnname;
    
    }
     boolean Btn::isbuttonClicked(void){
          if(this->isBtnPressed() && (this->getStikyKey() == false)){
               this->setStikyKey(true); 
                this->btnClick = false;
               return false;
              } 
         if(!this->isBtnPressed() && (this->getStikyKey() == true)){
              if(this->getStikyKey() == true){
                  this->btnClick = true;
                  this->btnClickCount += 1 ;
                  
                }
             this->setStikyKey(false); 
             return true;
            }
         return false;    
     }
   void Btn::debbuger(){
        bool sbtn  = getState();
        String btnstate = String(sbtn ? "Pressed":"Released");
        Serial<<"Button module\n"<<"Name:"<< btnname<<endl;
        Serial<<"Status:"<<btnstate<<"\nValue:"<<sbtn<<endl;
        Serial<<"Stiky key:"<<getStikyKey()<<endl;
        Serial<<"Click Action:"<<this->btnClick<<endl;
        Serial<<"Total Clicks:"<<this->btnClickCount<<"\n\n"<<endl;
        
        }
