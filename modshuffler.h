#ifndef MOD_SHUFFLER_H
#define MOD_SHUFFLER_H
#include <Arduino.h>
#include <Streaming.h>
class Shuffler {
  private:
          
  public:
        int order_array [4] = {0,0,0,0};
        int minrange,maxrange;
  public:
       Shuffler(int m, int n);
       boolean searchIndex(int number ,int* options,int arrysize); 
       void    createShuffleOrder(void);
       int* getOrder(void);
   };

#endif
