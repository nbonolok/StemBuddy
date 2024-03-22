#include "modpot.h"
int Pot::setpot(int pin,String potname,int minrange =0,int maxrange= 10){
  
  this->pin = pin;
  this->potname = potname;
  this->minrange = minrange;
  this->maxrange = maxrange;
  this->currentValue = 0;
  init();
   }

    int Pot::init(){
       
       return getPotMappedValue();
    }

    void Pot::setPotMap(){
      this->currentValue = analogRead(this->pin);               
      this->currentValue = map(this->currentValue,0,1024,minrange,maxrange);
    }

    int Pot::getPotMappedValue(){
       this->setPotMap();
       return  this->currentValue;
     }
   void Pot::setRange(int rmin,int rmax){
          this->minrange =  rmin;
          this->maxrange =  rmax;
    } 
   void Pot::setName(String pname){
       this->potname = pname;
    } 
   void Pot::debbuger(){
        int value = getPotMappedValue();
        String pot_name = potname;
        String strvalue = String(value);
        Serial<<"POT module:"<< pot_name << ": "<<strvalue << endl;
        String str_range;
        if(value == this->minrange){
            str_range = "at Min";
          }
        if(value == (this->maxrange -1)){
            str_range = "at Max";
          }
         if(value != this->minrange && value != (this->maxrange -1)){
            str_range = "within range";
          }  
        Serial<<"Pot is "<<str_range<<"\n\n"<<endl;
        delay(500);     
    }
