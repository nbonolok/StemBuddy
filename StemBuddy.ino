  
#include "__framework.h"
void setup() {
   Serial.begin(9600);
   randomSeed(analogRead(A1));
   display_helper.begin();
   display_helper.drawlogo();
   delay(2000);
   int x = 7;
   int r = 7;
   int z = x/r;
    Serial<<z<<endl;
}

void loop() {
  
  if(!DEBUG){
   // ModeTypeScreen();
   // Serial<< MODE_TYPE<<endl;
     int mode = preQuizMenu();
     if(!game_flag){
          settingHandler(prepareQuiz()); 
       }if(game_flag){
           examSessionHandler(); 
       }
   }
   if(DEBUG){
        Serial.println("Entering debug mode....");
        debugger();
      }
   } 
