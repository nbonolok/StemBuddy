#ifndef MOD_POT_H
#define MOD_POT_H
#include <Arduino.h>
#include <Streaming.h>
class Pot {
  
  private:
    int pin;
    
  public:
    String potname;
    int minrange;
    int maxrange;
    int currentValue;
    
    public: int init();
    public: void setPotMap();
    public: int getPotMappedValue(); 
    public: int setpot(int pin,String potname,int minrange,int maxrange);
    public: void setRange(int rmin,int rmax); 
    public: void setName(String pname);
    public: void debbuger();
};
#endif
