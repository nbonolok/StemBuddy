#include "modshuffler.h"
Shuffler::Shuffler(int m, int n) {
    this->minrange  = m;
    this->maxrange = n;
  }
boolean Shuffler::searchIndex(int number ,int* options,int arraysize){
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

 void  Shuffler::createShuffleOrder(void){
   this->order_array[0]= 0;
   this->order_array[1]= 0;
   this->order_array[2]= 0;
   this->order_array[3]= 0;
   int arrysize = sizeof(this->order_array)/sizeof(this->order_array[0]);
   boolean stillGen = true;
   int no_options = 0;
   while(stillGen){
       int gen_number = random(this->minrange,this->maxrange);
       boolean elementFound = this->searchIndex(gen_number,this->order_array,arrysize);
       if(!elementFound){
           this->order_array[no_options] = gen_number;
           no_options = no_options + 1;
           if(no_options > 3){
              break;
            }
        }
   }
  
  }

   int* Shuffler::getOrder(void){
     return this->order_array;
    }  
