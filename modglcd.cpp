#include "modglcd.h"
GLcd::GLcd() : u8g2(U8G2_R0,13,11, 10,8){
  
  }
void GLcd::begin(){
   u8g2.begin();
  
 } 
 void  GLcd::ModeTypeMenu(int index){
    u8g2_uint_t Selected_menu [2] = {U8G2_BTN_BW0,U8G2_BTN_INV}; 
    int selected    = 1;
    int notselected = 0;
    u8g2.firstPage();
  do
  {   
      u8g2.setFont(u8g2_font_ncenB08_tr);
      u8g2.drawStr(0,8,"Question Types");
      u8g2.setFont(u8g2_font_ncenR08_tr);
      if(index == 1){
          u8g2.drawButtonUTF8(4,20,Selected_menu[selected], u8g2.getDisplayWidth()-5*2,  5,  2, "[A] Multiple Choice" );
      }if(index != 1){
          u8g2.drawButtonUTF8(4,20,Selected_menu[notselected], u8g2.getDisplayWidth()-5*2,  5,  2, "[A] Multiple Choice" );
        }
      if(index == 2){  
        u8g2.drawButtonUTF8(4,34,Selected_menu[selected], u8g2.getDisplayWidth()-5*2,  5,  2, "[B] Short Answers" );
       }   
      if(index != 2){  
        u8g2.drawButtonUTF8(4,34,Selected_menu[notselected], u8g2.getDisplayWidth()-5*2,  5,  2, "[B] Short Answers" );
       }
       if(index == 3){  
          u8g2.drawButtonUTF8(4,48,Selected_menu[selected], u8g2.getDisplayWidth()-5*2,  5,  2, "[C] Word to number");
       }
       if(index != 3){  
         u8g2.drawButtonUTF8(4,48,Selected_menu[notselected], u8g2.getDisplayWidth()-5*2,  5,  2, "[C] Word to number");
       }
       u8g2.drawStr(4,62,"[D] Confirm");
        //u8g2.drawStr(64,62,"[B] Back");
        //u8g2.drawFrame(0,0,128,64);
     }while(u8g2.nextPage());
      
  }
 
 void GLcd::SettingMenu(int index){
    u8g2_uint_t Selected_menu [2] = {U8G2_BTN_BW0,U8G2_BTN_INV}; 
    int selected    = 1;
    int notselected = 0;
    u8g2.firstPage();
  do
  {   
      u8g2.setFont(u8g2_font_ncenB08_tr);
      u8g2.drawStr(0,8,"GAME SETTINGS");
      u8g2.setFont(u8g2_font_ncenR08_tr);
      if(index == 1){
          u8g2.drawButtonUTF8(4,20,Selected_menu[selected], u8g2.getDisplayWidth()-5*2,  5,  2, "Category" );
      }if(index != 1){
          u8g2.drawButtonUTF8(4,20,Selected_menu[notselected], u8g2.getDisplayWidth()-5*2,  5,  2, "Category" );
        }
      if(index == 2){  
        u8g2.drawButtonUTF8(4,34,Selected_menu[selected], u8g2.getDisplayWidth()-5*2,  5,  2, "Level" );
       }   
      if(index != 2){  
        u8g2.drawButtonUTF8(4,34,Selected_menu[notselected], u8g2.getDisplayWidth()-5*2,  5,  2, "Level" );
       }
       if(index == 3){  
          u8g2.drawButtonUTF8(4,48,Selected_menu[selected], u8g2.getDisplayWidth()-5*2,  5,  2, "Question SetUp");
       }
       if(index != 3){  
         u8g2.drawButtonUTF8(4,48,Selected_menu[notselected], u8g2.getDisplayWidth()-5*2,  5,  2, "Question SetUp");
       }
       u8g2.drawStr(4,62,"[A] Select");
        u8g2.drawStr(64,62,"[B] Back");
        //u8g2.drawFrame(0,0,128,64);
     }while(u8g2.nextPage());
  }

  void GLcd::categoryMenu(int index){
    u8g2_uint_t Selected_menu [2] = {U8G2_BTN_BW0,U8G2_BTN_INV};
    String label[4] ={"Addition","Subtraction","Multiplication","Division"}; 
    int selected    = 1;
    int notselected = 0;
   u8g2.firstPage();
  do
  {   
   u8g2.setFont(u8g2_font_ncenB08_tr);
   u8g2.drawStr(0,8,"Select Category");
   u8g2.setFont(u8g2_font_ncenR08_tr); 
   if(index == 0){
          u8g2.drawButtonUTF8(4,20,Selected_menu[selected], u8g2.getDisplayWidth()-5*2,  5,  2, "[+] Addition");
      }if(index != 0){
          u8g2.drawButtonUTF8(4,20,Selected_menu[notselected], u8g2.getDisplayWidth()-5*2,  5,  2, "[+] Addition");
        }
      if(index == 1){
        u8g2.drawButtonUTF8(4,34,Selected_menu[selected], u8g2.getDisplayWidth()-5*2,  5,  2, "[-] Subtraction");
       }   
      if(index != 1){  
        u8g2.drawButtonUTF8(4,34,Selected_menu[notselected], u8g2.getDisplayWidth()-5*2,  5,  2, "[-] Subtraction");
       }
       if(index == 2){  
          u8g2.drawButtonUTF8(4,48,Selected_menu[selected], u8g2.getDisplayWidth()-5*2,  5,  2, "[x] Multiplication");
       }
       if(index != 2){  
         u8g2.drawButtonUTF8(4,48,Selected_menu[notselected], u8g2.getDisplayWidth()-5*2,  5,  2, "[x] Multiplication");
       }
       if(index == 3){  
          u8g2.drawButtonUTF8(4,60,Selected_menu[selected], u8g2.getDisplayWidth()-5*2,  5,  2, "[/] Division");
       }
       if(index != 3){  
         u8g2.drawButtonUTF8(4,60,Selected_menu[notselected], u8g2.getDisplayWidth()-5*2,  5,  2, "[/] Division");
       } 
       
       }while(u8g2.nextPage());
 }
void GLcd::levelMenu(String level,String clevel){
   const String str = level;
   const String cstr = clevel;
  u8g2.firstPage();
  do
  {   
      u8g2.setFont(u8g2_font_ncenB08_tr);
      u8g2.drawStr(0,8,"GAME LEVEL");
      u8g2.setFont(u8g2_font_ncenR08_tr);
      u8g2.drawStr(0,18,"Current Level:");
      u8g2.setCursor(72,18);
      u8g2.print(cstr);
      u8g2.setFont(u8g2_font_ncenB14_tr);
      u8g2.setCursor(54,40);
      u8g2.print(str);
      u8g2.setFont(u8g2_font_ncenR08_tr);
     
      u8g2.drawStr(4,62,"[A] Select");
      u8g2.drawStr(64,62,"[B] Back"); 
  }while(u8g2.nextPage());
  } 

void GLcd::questionSetupMenu(String newTotal,String currentTotal){
   const String str_newTotal = newTotal;
   const String str_currentTotal = currentTotal;
  u8g2.firstPage();
  do
  {   
      u8g2.setFont(u8g2_font_ncenB08_tr);
      u8g2.drawStr(0,8,"Questions SetUp");
      u8g2.setFont(u8g2_font_ncenR08_tr);
      u8g2.drawStr(0,18,"Current total:");
      u8g2.setCursor(66,18);
      u8g2.print(str_currentTotal);
      u8g2.setFont(u8g2_font_ncenB14_tr);
      u8g2.setCursor(54,40);
      u8g2.print(str_newTotal);
      u8g2.setFont(u8g2_font_ncenR08_tr);
     
      u8g2.drawStr(4,62,"[A] Select");
      u8g2.drawStr(64,62,"[B] Back"); 
  }while(u8g2.nextPage());
}

void GLcd::preQuizSetupMenu(String topic,int level,int total,int duration){
  
  const String str_topic = topic;
  const String str_level = String(level);
  const String str_total = String(total);
  u8g2.firstPage();
  do
  { 
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.drawStr(0,8,"Pre-Quiz Info");
    u8g2.setFont(u8g2_font_ncenR08_tr);
    u8g2.setCursor(4,18);
    u8g2.print(str_topic);
    u8g2.drawStr(4,28,"Level:");
    u8g2.setCursor(36,28);
    u8g2.print(str_level);
    u8g2.drawStr(4,38,"No of questions:");
     u8g2.setCursor(84,38);
    u8g2.print(str_total);
    u8g2.drawStr(4,48,"Question Timer(Sec):");
     
    u8g2.drawStr(4,62,"[A] Start");
    u8g2.drawStr(64,62,"[B] Change"); 
     u8g2.setFont(u8g2_font_ncenB08_tr);
     u8g2.setCursor(110,48);
      u8g2.print(duration);  
    }while(u8g2.nextPage());
  
}
void GLcd::questionWindow(String topic,String totalQuestions,String currentq, String a ,String b,String symbol,String answer,
                   String optionA,String optionB,String optionC,String optionD,String duration){
     String str_topic = topic;
     String question = a+""+symbol+""+b+" = ?";
     String qindex = "["+currentq+"/"+totalQuestions+"]";
   u8g2.firstPage();
  do
  {
   u8g2.setFont(u8g2_font_ncenB08_tr);
   u8g2.setCursor(2,8);
   u8g2.print(str_topic);
   u8g2.setFont(u8g2_font_ncenR08_tr);
   u8g2.setCursor(96,8);
   u8g2.print(qindex);
   u8g2.drawStr(0,18,"Q:");
   u8g2.setCursor(12,18);
   u8g2.print(currentq); 
   u8g2.setFont(u8g2_font_ncenB12_tr);
   u8g2.setCursor(20,36);
    u8g2.print(question);
    
    u8g2.setFont(u8g2_font_ncenR08_tr);
   
    String str_optionA = "[A] "+ optionA;
    u8g2.setCursor(2,48);
    u8g2.print(str_optionA);
    
    String str_optionB = "[B] "+ optionB;
    u8g2.setCursor(64,48);
    u8g2.print(str_optionB);
    
    String str_optionC = "[C] "+ optionC;
    u8g2.setCursor(2,60);
    u8g2.print(str_optionC);
    
    String str_optionD = "[D] "+ optionD;
    u8g2.setCursor(64,60);
    u8g2.print(str_optionD);
    u8g2.setCursor(106,18);
    u8g2.print(duration);
    u8g2.setFont(u8g2_font_open_iconic_embedded_1x_t);
    u8g2.drawGlyph(96,18,0x0041);
    }while(u8g2.nextPage());
  }    
 void GLcd::questionWindowFeedback(String topic,String totalQuestions,String currentq, String a ,String b,
                             String symbol,String answer,String userAnswer,String user_msg){
     String str_topic = topic;
     String question = a+""+symbol+""+b+" = "+userAnswer;
     String qindex = "["+currentq+"/"+totalQuestions+"]";
   u8g2.firstPage();
  do
  {
   u8g2.setFont(u8g2_font_ncenB08_tr);
   u8g2.setCursor(2,8);
   u8g2.print(str_topic);
   u8g2.setFont(u8g2_font_ncenR08_tr);
   u8g2.setCursor(96,8);
   u8g2.print(qindex);
   u8g2.drawStr(2,18,"Q:");
   u8g2.setCursor(14,18);
   u8g2.print(currentq); 
   u8g2.setFont(u8g2_font_ncenB12_tr);
   u8g2.setCursor(4,36);
   u8g2.print(question); 
   
    
    if(userAnswer == answer){
       u8g2.setFont(u8g2_font_unifont_t_emoticons);
       u8g2.drawGlyph(111,36,0x002A);
       u8g2.setFont(u8g2_font_ncenR08_tr);
       u8g2.setCursor(2,52); 
       u8g2.print(user_msg);
      }else{
         u8g2.setFont(u8g2_font_unifont_t_emoticons);
         u8g2.drawGlyph(111,36,0x003E);
         u8g2.setFont(u8g2_font_ncenR08_tr);
         u8g2.setCursor(2,52); 
         u8g2.print(user_msg);
        }
                            
   }while(u8g2.nextPage());
  }   

void GLcd::drawlogo(){
  u8g2.firstPage();
  do
  {
     u8g2.drawXBMP(0, 0, u8g_logo_width, u8g_logo_height, office_bits);
     u8g2.setFont(u8g2_font_ncenB08_tr);
     u8g2.drawStr(10,62,"MATHEMATICS");
     u8g2.drawStr(68,38,"+ x - /");
     u8g2.drawRFrame(0,0,128,64,4);
   }while(u8g2.nextPage());
     delay(2000);
  }

 void GLcd::developerWindow(){
      this->drawlogo();
       u8g2.firstPage();
     do
     {
        u8g2.setFont(u8g2_font_ncenB08_tr);
        u8g2.drawStr(30,30,"BKN@2021");
        u8g2.drawStr(30,40,"Math Game!!");
        u8g2.setFont(u8g2_font_ncenR08_tr);
         u8g2.drawStr(20,50,"nyonib@biust.ac.bw");
        u8g2.drawRFrame(0,0,128,64,4);
   }while(u8g2.nextPage());
     delay(5000);  
  }
 void GLcd::quizFeedback(int total, int grandTotal,int percentage,String topic){
      String str = String(total)+"/"+String(grandTotal);
      String feedback = (percentage >= 50) ? "Great Job: ": "Keep Practising: ";
      String ux_feedback  = feedback+String(percentage)+"%";
     u8g2.firstPage();
     do{
          u8g2.setFont(u8g2_font_ncenB08_tr);
          u8g2.setCursor(4,10);
          u8g2.print(topic);
           u8g2.setFont(u8g2_font_ncenB14_tr);
           u8g2.setCursor(54,40);
           u8g2.print(str);
          u8g2.setFont(u8g2_font_ncenR08_tr);
          u8g2.setCursor(4,60);
          u8g2.print(ux_feedback);           
          u8g2.drawRFrame(0,0,128,64,4);
      }while(u8g2.nextPage()); 
    
  } 




  
  
