#include<Thread.h>
#include <ThreadController.h>
#define SECOND 1000 
int seconds =  0;
int minutes =  0;
int hours  =   0;
int days   =   0;

ThreadController controll = ThreadController();
Thread*  thread_timer = new Thread();

void stopwatch(){
     if(seconds  > 59){
         seconds = 0;
         minutes = minutes + 1;
       }
     if(minutes > 59){
            minutes = 0;
            hours = hours + 1;
          }  
     if(hours > 24){
         days  = days + 1;  
         hours = 0;
         minutes = 0;
         seconds = 0;
      } 
     seconds = seconds + 1;
  
  }
void createTimer(){
    seconds = 0;
    minutes = 0; 
    hours  = 0; 
    days = 0;
    thread_timer->onRun(stopwatch);
    thread_timer->setInterval(1000);
    controll.add(thread_timer); 
  }

void stopTimer(){
     controll.remove(thread_timer);
  }

    
         
    
