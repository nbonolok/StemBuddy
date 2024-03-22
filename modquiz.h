#ifndef MOD_QUIZ_H
#define MOD_QUIZ_H
#include <Arduino.h>
#include <Streaming.h>
class Quiz {
  private:
     int level,topic,totalQuestions,score,duration; 
     int fnumber,lnumber,optionA, optionB, optionC,optionD,answer;
     int levels [11] = {0,10,20,30,40,50,60,70,80,100,200};
     int options_array [4] = {0,0,0,0};
     String topics [4] = {"Addition","Subtraction","Multiplication","Division"};
     String topic_symbol[4] ={"+","-","x","/"};
     String instructions[3] = {"Select topic","Select Level","Questions Mgr"};
     
  public:
    int remainder;
    int addition(int a, int b);
    int subtraction(int a, int b);
    int multiplication(int a,int b);
    int division(int a, int b);
    int operationHandler(int topic, int a, int b);
    boolean searchIndex(int number ,int* options,int arraysize); 
    int findNumberFactors(int number);
  public: 
           void setDuration(int dtime);
           int  getDuration(void);
           void setScore(int score);
           int  getScore(void); 
           void setLevel(int level);
           int getLevel();
           void settopic(int topic);
           int  gettopic(void);
           String getTopicName(int index);
           String getTopicSymbol(void);
           void setTotalQuestions(int total);
           int getTotalQuestions();
           
  public:  
     Quiz(int level,int category,int total,int score,int duration);
     void genNumbers();
     int* genOptions();
     int  getfnumber();
     int  getlnumber();
     void setlnumber(int a);
     String getquestion();
     void setAnswer(int answer);
     int  getAnswer();  
   };

#endif
