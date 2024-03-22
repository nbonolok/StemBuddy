#include "modquiz.h"
Quiz::Quiz(int level,int topic,int total,int score,int duration) {
  this->level = level;
  this->topic = topic;
  this->totalQuestions = total;
  this->score = score;
  this->duration = duration;
  this->remainder = 0;
  }
void Quiz::setDuration(int dtime){
    this->duration = dtime;
  }
int  Quiz::getDuration(void){
  return this->duration;
  }  
void Quiz::setLevel(int level){
     this->level = level; 
  }
int Quiz::getLevel(){
  return this->level; 
  }
void Quiz::settopic(int topic){
    this->topic = topic;
  }
int  Quiz::gettopic(void){
   return this->topic;
 }  
 String  Quiz::getTopicName(int index){
   String str = this->topics[index];
   return str;
  }
 String Quiz::getTopicSymbol(void){
   return this->topic_symbol[topic];
  } 
 void Quiz::setTotalQuestions(int total){
    this->totalQuestions = total;
  }
  int Quiz::getTotalQuestions(){
     return this->totalQuestions;
   }
    
void Quiz::genNumbers(){
   this->fnumber =  random(1,levels[this->level]);
   this->lnumber =  random(1,levels[this->level]); 
   
  }
 void Quiz::setAnswer(int answer){
     this->answer = answer;
  }
 int Quiz::getAnswer(){
   return this->answer;    
  }  
boolean Quiz::searchIndex(int number ,int* options,int arraysize){
  boolean flag = false;                  //not found
   int Array_size = arraysize;
   for(int i = 0; i < Array_size; i++){
          if(number == options[i]){
              flag = true;              //found
              break;
            } 
        }
      return flag;
  }  
int* Quiz::genOptions(){
  
   this->options_array[0]= 0; 
   this->options_array[1]= 0; 
   this->options_array[2]= this->answer+1; 
   this->options_array[3]= this->answer;
   int arraysize = sizeof(this->options_array)/sizeof(this->options_array[0]);
   boolean stillGen = true;
   int no_options = 0;
   while(stillGen){
       int gen_number = random(1,(levels[this->level]));
       boolean elementFound = this->searchIndex(gen_number,this->options_array,arraysize);
       if(!elementFound){
           this->options_array[no_options] = gen_number;
           no_options = no_options + 1;
           if(no_options > 1){
              break;
            }
        }
   }
    return this->options_array;
  }
int Quiz::findNumberFactors(int number){
 // Serial<<"Natural number:"<<number<<endl;
   int sizeofFactors = 0; 
   for(int i= 1; i < number; i++){
       if(number % i == 0){
          sizeofFactors = sizeofFactors + 1;
          
         }
    }
  int factors[sizeofFactors];
  memset(factors,0,sizeofFactors);
  int index  = 0; 
  for(int j= 1; j < number; j++){
       if((number % j) == 0){
          factors[index] = j;
          //Serial<< factors[index]<<endl;
          ++index;  
         
           }
        }
   int lastfactor = index ;//- 1;     
   int factor  = random(0,lastfactor);
   return factors[factor]; 
  }
  
int Quiz::getfnumber(){
  return this->fnumber;
  }
int Quiz::getlnumber(){
  return this->lnumber;
 }
void Quiz::setlnumber(int a){
     this->lnumber = a;
  }
int Quiz::addition(int a, int b){
  int result = a + b;
  return result;   
 }
int Quiz::subtraction(int a, int b){
  int result = a - b;
  return result; 
}

int Quiz::multiplication(int a,int b){
   int result = a * b;
  return result; 
}
int Quiz::division(int a, int b){
   if(a > b && a > 0){
       int result = a / b;
       int rem = a % b;
       this->remainder = rem;
       return result;
   }
   return 0; 
}
void Quiz::setScore(int score){
     this->score = score;
  }
int  Quiz::getScore(void){
      return this->score;
}
int Quiz::operationHandler(int topic, int a, int b){
  int result = 0;
      if(topic == 0 ){
        result = this->addition(a , b);
       
      }
     if(topic == 1){
        result = this->subtraction(a,b);
      }
      if(topic == 2){
        result = this->multiplication(a,b);
      } 
      if(topic == 3){
        result = this->division(a, b);
      }
      this->answer = result;
      return result; 
  }
 
  
