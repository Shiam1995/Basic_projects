// c lottery


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void)
{

    int number[5], stars[2];
    int numGen = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int temp = 0;
    int starTemp = 0;
    time_t secondsFromEpoch = time(NULL);
    srand(secondsFromEpoch);

    int count = 0;
    int dCount = 0;
    int dup = 0;
    int sCount =0;

    printf("\n");

    while ( count <= 4 )
    {
      numGen = rand()%50;
      dup = 0;

          for ( j = 0; j <= 4; j++)
          {
            if(numGen == number[j])
            {
            dup = 1;
            }
          }

          if( dup == 1)
          {
            dCount++;
          }
          else
          {
            number[count] = numGen;
            count++;
          }
    }

    while ( sCount <= 1 )
    {
      numGen = rand()%12;
      dup = 0;

          for ( j = 0; j <= 1; j++)
          {
            if(numGen == stars[j])
            {
            dup = 1;
            }
          }

          if( dup == 1)
          {
            dCount++;
          }
          else
          {
            stars[sCount] = numGen;
            sCount++;
          }
    }

    //for (i = 0; i <= 4; i++){
    //    printf("%i ", number[i]);
    //}

  //  printf("||");

  //  for (i = 0; i <= 1; i++){
  //      printf(" %i", stars[i]);
  //  }

  //  printf("\nPost sort\n");

    for (l = 0; l <= 4; l++){
      for(m = 0; m <= 4; m++){
        if(number[m] > number[m+1]){
          temp = number[m];
          number[m] = number[m+1];
          number[m+1] = temp;
        }
      }
    }


    if(stars[0] > stars[1]){
      temp = stars[0];
      stars[0] = stars[1];
      stars[1] = temp;

    }

    for (i = 0; i <= 4; i++){
        printf("%i ", number[i]);
    }

    printf("||");

    for (i = 0; i <= 1; i++){
        printf(" %i", stars[i]);
    }

    printf("\n");
    //printf("\ndup count was %i\n", dCount);
    return 0;


}
