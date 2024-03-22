#include "mod_uri.h"
Btn btn_a = Btn(8,"Select",false);    
boolean game_flag = false;
int prepareQuiz();
void settingHandler(int option);
void  GoodMelody();
void BadMelody();

void ModeTypeScreen(){
     boolean  screen_flag = true;
     Btn btn_a = Btn(9,"A",false);
     Btn btn_b = Btn(8,"B",false);
     Btn btn_c = Btn(7,"C",false);
     Btn btn_d = Btn(6,"D",false);
     int index = -1;
    
     while(screen_flag){
        display_helper.ModeTypeMenu(index);
          
        if(btn_a.isbuttonClicked() && btn_a.btnClick == true){
              index = 1;
             
            }
        
         if(btn_b.isbuttonClicked() && btn_b.btnClick == true){
            index = 2; 
            }
          if(btn_c.isbuttonClicked() && btn_c.btnClick == true){
            index = 3; 
            }
          if(btn_d.isbuttonClicked() && btn_d.btnClick == true){
             MODE_TYPE = index;
             screen_flag = false;
             break; 
            }  
         delay(50);    
        }
  }

void catergoryScreen(){
     boolean  screen_flag = true;
     Btn btn_a = Btn(9,"Select",false);
     Btn btn_b = Btn(8,"Back",false);
     int knob_level;
     int temp = knob.setpot(potPin,"Topics",0,4);
     display_helper.categoryMenu(temp);
     while(screen_flag){
        knob_level = knob.getPotMappedValue();
        display_helper.categoryMenu(knob_level);
          
        if(btn_a.isbuttonClicked() && btn_a.btnClick == true){
             screen_flag = false;
             quiz_helper.settopic(knob_level);
             return;
           }
        
         if(btn_b.isbuttonClicked() && btn_b.btnClick == true){
              screen_flag = false;
              return;
          }
         delay(250);    
        }
  }

void levelScreen(){
     boolean  screen_flag = true;
     Btn btn_a = Btn(9,"Select",false);
     Btn btn_b = Btn(8,"Back",false);
     int knob_level;
     int temp = knob.setpot(potPin,"Level",1,11);
     //display_helper.levelMenu(temp);
   while(screen_flag){
         knob_level = knob.getPotMappedValue();
         String new_level = String(knob_level);
         String old_level =  String(quiz_helper.getLevel());
         display_helper.levelMenu(new_level,old_level);
         
         if(btn_a.isbuttonClicked() && btn_a.btnClick == true){
                screen_flag = false;
                quiz_helper.setLevel(knob_level);
              return;
             }
            
         if(btn_b.isbuttonClicked() && btn_b.btnClick == true){
               screen_flag = false;
                 
            return;
                }
            delay(250); 
       }
 
 }
void questionSetupScreen(){
     boolean  screen_flag = true;
     Btn btn_a = Btn(9,"Select",false);
     Btn btn_b = Btn(8,"Back",false);
      int knob_level;
     int temp = knob.setpot(potPin,"QuestionSetup",1,51);
     
     while(screen_flag){
          knob_level = knob.getPotMappedValue();
          String new_total = String(knob_level);
          String old_Total = String(quiz_helper.getTotalQuestions());
          display_helper.questionSetupMenu(new_total,old_Total);
         
          if(btn_a.isbuttonClicked() && btn_a.btnClick == true){
                  screen_flag = false;
                  quiz_helper.setTotalQuestions(knob_level);
              return;
            }
           

         if(btn_b.isbuttonClicked() && btn_b.btnClick == true){
                  screen_flag = false;
                  game_flag = true;
           return;
           }
          delay(20);  
      } 
}  
void settingHandler(int option){
    switch(option){
       case 1:
           catergoryScreen();
           break;
       case 2:
           levelScreen();
           break;
       case 3:
           questionSetupScreen();
          break;
       //case 4:
        //  preQuizMenu();
         // break;        
      }
  } 

int preQuizMenu(){
     int selected_option;
     boolean  screen_flag = true;
     Btn btn_a = Btn(9,"Start",false);
     Btn btn_b = Btn(8,"Change",false);
     String topic = quiz_helper.getTopicName(quiz_helper.gettopic());
     int level =    quiz_helper.getLevel();
     int total =    quiz_helper.getTotalQuestions();
      int knob_duration = knob.setpot(potPin,"Duration",1,TIME_LIMIT); 
     while(screen_flag){
        knob_duration = knob.getPotMappedValue();
        display_helper.preQuizSetupMenu(topic,level,total,knob_duration);
        if(btn_a.isbuttonClicked() && btn_a.btnClick == true){
              //set duration in quiz class TODO 
              screen_flag = false;
              game_flag =   true;
              selected_option = 1;
              quiz_helper.setDuration(knob_duration); 
          }
          if(btn_b.isbuttonClicked() && btn_b.btnClick == true){
              screen_flag = false;
              game_flag = false;
              selected_option = 0;
          }  
       delay(50);
      }
      return selected_option;
  }    
int prepareQuiz(){
    boolean  screen_flag = true;
    int knob_level;
    Btn btn_a = Btn(9,"A",false);
    Btn btn_b = Btn(8,"Back",false);
    int temp = knob.setpot(potPin,"Settings",1,4);
    display_helper.SettingMenu(temp);
    while(screen_flag){
        knob_level = knob.getPotMappedValue();
        display_helper.SettingMenu(knob_level);
                
         if(btn_a.isbuttonClicked() && btn_a.btnClick == true){
               screen_flag = false;
               return knob_level;
                }
          if(btn_b.isbuttonClicked() && btn_b.btnClick == true){
               return 4;
            }     
             delay(10); 
       }
    }

                  


String getUserAnswer(String topic,String TotalQuestions,String q_number,String qa,String qb,String symbol,String answer,
                     String a , String b ,String c ,String d){
     Btn btn_a  = Btn(9,a,false);
     Btn btn_b  = Btn(8,b,false);  
     Btn btn_c =  Btn(7,c,false); 
     Btn btn_d =  Btn(6,d,false);
   
    String keyname = "-1";
    boolean  wait_key = true;
    int Current_Duration = quiz_helper.getDuration();
    createTimer(); 
    while(wait_key){
       controll.run();
       String s = String(seconds);
       String m = String(minutes);
       String h = String(hours);
      
       int remTime = Current_Duration - seconds;
      // Serial.println(Current_Duration);
      if(seconds >= Current_Duration){
          stopTimer();
          wait_key = false;
          return "XX";
       }
       display_helper.questionWindow(topic,TotalQuestions,q_number,qa,qb,symbol,answer,a,b,c,d,String(remTime)); 
         if(btn_a.isbuttonClicked() && btn_a.btnClick == true){
              wait_key = false;
              keyname = btn_a.btnname;
             
              
          }
         if(btn_b.isbuttonClicked() && btn_b.btnClick == true){
               wait_key = false;
                keyname = btn_b.btnname;
             
          }
        if(btn_c.isbuttonClicked() && btn_c.btnClick == true){
              wait_key = false;
               keyname = btn_c.btnname;
              
          }
       if(btn_d.isbuttonClicked() && btn_d.btnClick == true){
              wait_key = false;
               keyname = btn_d.btnname;
               
            
          }
        delay(10);        
      }
    return keyname;
  } 
  String processFeedback(String feedback,int qanswer){
       int fnumber = feedback.toInt();
       if(fnumber == qanswer){
          int updatedScore = quiz_helper.getScore()+1;
          quiz_helper.setScore(updatedScore);
           led_green.on();
          return String("Correct: "+feedback );        
          }
        else{
         led_red.on(); 
         String qstr = String(qanswer);
          return String("Correction: "+qstr);
        }
        
  } 
 void showFinalResults(){
     Btn btn_a  =  Btn(9,"A",false);
     Btn btn_b  =  Btn(8,"B",false);  
     Btn btn_c  =  Btn(7,"C",false); 
     Btn btn_d  =  Btn(6,"D",false);
     boolean  wait_key = true;
     int total  =  quiz_helper.getScore();
     int grandTotal  =  quiz_helper.getTotalQuestions();
     String topic = quiz_helper.getTopicName(quiz_helper.gettopic());
     int percentage = (total * 100) / grandTotal;
     display_helper.quizFeedback(total,grandTotal,percentage,topic); 
     if(percentage >= 50){
         led_green.on(); 
         GoodMelody();
      }else{
         led_red.on();
         BadMelody();
        }
      
     while(wait_key){
         if((btn_a.isbuttonClicked() && btn_a.btnClick == true) || (btn_b.isbuttonClicked() && btn_b.btnClick == true)
             || (btn_c.isbuttonClicked() && btn_c.btnClick == true) || (btn_d.isbuttonClicked() && btn_d.btnClick == true)){
              wait_key = false;
           }
       }
     led_green.off();
     led_red.off();  
   }      
void examSessionHandler(){
  int current_topic = quiz_helper.gettopic();
  String topic = quiz_helper.getTopicName(current_topic);
          int TotalQuestions = quiz_helper.getTotalQuestions();
          int myquestions  = TotalQuestions;
          int q_number = 1;
          quiz_helper.setScore(0);
          while(myquestions > 0){
          struct qTemplate question;
           question.a = 0;
           question.b = 0;
           question.answer = 0;
           while((question.a <=  question.b) ){
                    quiz_helper.genNumbers();
                    question.a = quiz_helper.getfnumber();
                    question.b = quiz_helper.getlnumber();
            }
            
            if(current_topic == 3){
                 int numberfactor = quiz_helper.findNumberFactors(question.a);
                 question.b = numberfactor;
                 quiz_helper.setlnumber(numberfactor);
                 //Serial<<"Elements size:"<<numberfactor<<endl;
                }
            
            
            question.answer = quiz_helper.operationHandler(current_topic, question.a,question.b); 
            question.remainder = (quiz_helper.remainder > 0) ? quiz_helper.remainder: 0;
            shuffler.createShuffleOrder();
            int *array_order   =    shuffler.getOrder();
            int *array_options =    quiz_helper.genOptions();
            int qanswer     =       question.answer;
            int a  = array_order[0] - 1;
            question.optionA = array_options[a];
            int b  = array_order[1] - 1;
            question.optionB = array_options[b];
             int c  = array_order[2] - 1;
            question.optionC = array_options[c];
             int d  = array_order[3] - 1;
            question.optionD = array_options[d];
           
            display_helper.questionWindow(topic,String(TotalQuestions),String(q_number),String(question.a),String(question.b),quiz_helper.getTopicSymbol(),String(question.answer),
                  String(question.optionA),String(question.optionB),String(question.optionC),String(question.optionD),"0"); 
             
             String feedback = getUserAnswer(topic,String(TotalQuestions),String(q_number),String(question.a),String(question.b),quiz_helper.getTopicSymbol(),String(question.answer),
                  String(question.optionA),String(question.optionB),String(question.optionC),String(question.optionD));
          
           String user_msg = processFeedback(feedback,qanswer);
           display_helper.questionWindowFeedback(topic,String(TotalQuestions),String(q_number),String(question.a),String(question.b),
                                         quiz_helper.getTopicSymbol(),String(question.answer),feedback,user_msg);
                                         
       
                                         
           myquestions = myquestions - 1;
           q_number = q_number + 1;    
           delay(4000);
           led_green.off();
           led_red.off();
         }
         showFinalResults();
         game_flag = false;
        
}

void  GoodMelody(){
  int melody[] = {NOTE_E6, NOTE_D6, NOTE_FS6, NOTE_GS6, NOTE_C6, NOTE_B5, NOTE_D5, NOTE_E5, NOTE_B5, NOTE_A5, NOTE_AS5, NOTE_E5, NOTE_A5};
  int noteDurations[] = {16,16,8,8,16,16,8,8,16,16,8,8,2};
  int SIZE_ARRAY = (sizeof(melody)/sizeof(melody[0]));
  for(int thisNote = 0; thisNote < SIZE_ARRAY; thisNote++) {
         int noteDuration = 1000 / noteDurations[thisNote];
         tone(TONE_PIN, melody[thisNote], noteDuration);
         int pauseBetweenNotes = noteDuration * 2.00;
         delay(pauseBetweenNotes);
         noTone(TONE_PIN);
     }
  
}
void BadMelody(){
  int melody[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
  int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};
  int SIZE_ARRAY = (sizeof(melody)/sizeof(melody[0]));
  for(int thisNote = 0; thisNote < SIZE_ARRAY; thisNote++) {
         int noteDuration = 1000 / noteDurations[thisNote];
         tone(TONE_PIN, melody[thisNote], noteDuration);
         int pauseBetweenNotes = noteDuration * 2.00;
         delay(pauseBetweenNotes);
         noTone(TONE_PIN);
     }
}    
 
