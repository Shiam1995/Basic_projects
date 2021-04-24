// coinflip -> my best program to date 30/07/2020

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void){


  time_t secondsFromEpoch = time(NULL);
  srand(secondsFromEpoch);
  double i = 0;
  int j = 0;
  int k = 0;
  int seventy = 0;
  int eighty = 0;
  int ninety = 0;
  int hundred = 0;
  int heads = 0;
  int tails = 0;
  int number;

  printf("Initialising\n");

  while ( i < 1000000){
  heads = 0;
  tails = 0;
  for ( j = 0;  j< 120; j++){
    number =  rand()%2;
     if( number == 0){
       heads++;
     } else {
       tails++;
     }
   }


  if(heads > 70 && heads <=79){
    seventy++;
    //printf("Element [%.0lf] is %i\n", i, heads);
  } else if(heads > 80 && heads <=89){
    eighty++;
  }else if(heads > 89 && heads <=99){
    ninety++;
    printf("Element [%.0lf] is %i\n", i, heads);
  }else if(heads == 100){
    printf("Element [%.0lf] is %i\n", i, heads);
    hundred++;
  }
  i++;
}


  printf("number of number between 70 -79 %i\n", seventy);
  printf("number of number between 80 -89 %i\n", eighty );
  printf("number of number between 89 -90 %i\n", ninety);
  printf("number of number 100s %i\n", hundred);
  printf("Done\n");


    return 0;
}
