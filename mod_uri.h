#include "constants.h"
//#include "country.h"
//----------------------Lcd module----------------------------------------------------

//-----------------------GLCD module--------------------------------------------------
#include "modglcd.h"
GLcd display_helper;
    

//------------------Quiz module--------------------------------------------------------
#include "modquiz.h"
Quiz quiz_helper = Quiz(Qlevel,Qtopic,Qtotal,Qscore,Qduration);

//-----------------------Potentiometer module------------------------------------------
#include "modpot.h"
Pot knob = Pot();
//------------------------Button module-----------------------------------------------
#include "modbtn.h"
//----------------------Led module--------------------------------------------------------------
#include "modLed.h"
Led  led_red = Led(RED_LED,"RED LED");
Led  led_green = Led(GREEN_LED,"GREEN LED");
//---------------------------shuffler module---------------------------------------------------
#include "modshuffler.h"
Shuffler shuffler = Shuffler(1,5);
//----------------------------------------------------------------------------------------------
#include "modtimer.h"
//----------------------------------------------------------------------------------------------
void   btn_debugger(){
     Serial.println("Testing Buttons...");
     Btn btn_a  = Btn(9,"A",false);
     Btn btn_b  = Btn(8,"B",false);  
     Btn btn_c =  Btn(7,"C",false); 
     Btn btn_d =  Btn(6,"D",false);
   
    while(true){
    if(btn_a.isbuttonClicked() && btn_a.btnClick == true){
               btn_a.debbuger();
            }     
    if(btn_b.isbuttonClicked() && btn_b.btnClick == true){
               btn_b.debbuger();
            }     
    if(btn_c.isbuttonClicked() && btn_c.btnClick == true){
              btn_c.debbuger();
            }
    if(btn_d.isbuttonClicked() && btn_d.btnClick == true){
               btn_d.debbuger();
      }
      delay(20);               
    }
  
  }
void lcd_debugger(){
      Serial.println("Testing G LCD");
      while(true){
          display_helper.developerWindow();
        }
      
  }
void knob_debugger(){
    Serial.println("Testing Knob......");
    int knob_test = knob.setpot(potPin,"Knob",1,20);
    while(true){
         knob.debbuger();
         
      }
  }   
void debugger(){
    
     switch(DEBUG_TARGET){
        case 0:
            lcd_debugger();
            break;
        case 1:
            btn_debugger();
            break;
        case 2:
           knob_debugger();
           break;        
      }
  }
