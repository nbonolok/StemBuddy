#ifndef MOD_GLCD_H
#define MOD_GLCD_H
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
#include <Streaming.h>
#include "data.h"
class GLcd {
     private:
           U8G2_ST7920_128X64_F_SW_SPI u8g2;
     public:
            GLcd();
            void begin();
            void ModeTypeMenu(int index);
            void SettingMenu(int index);
            void categoryMenu(int index);
            void levelMenu(String level,String clevel);
            void questionSetupMenu(String newTotal,String currentTotal);
            void preQuizSetupMenu(String topic,int level,int total,int duration);
            void questionWindow(String topic,String totalQuestions,String currentq, String a ,String b,String symbol,String answer,
                   String optionA,String optionB,String optionC,String optionD,String duration); 
            void questionWindowFeedback(String topic,String totalQuestions,String currentq, String a ,String b,
                             String symbol,String answer,String userAnswer,String user_msg); 
            void quizFeedback(int total, int grandTotal,int percentage,String topic);                 
            void drawlogo(); 
            void developerWindow();                           
};
#endif
