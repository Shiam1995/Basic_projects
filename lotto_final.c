/*
project 3
lottery this is an attempt to model the euromillions lotterty
 where 5 numbers from 1- 50 and 2 numbers 1-12 are drawn
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main (void)
{

    time_t secondsFromEpoch = time(NULL);
    srand(secondsFromEpoch);



    int lottoOne[5] = {0,0,0,0,0};
    int lottoOneStar[2] = {0,0};
    int randomNumber = 0;
    int i = 0;
    int j = 0;
    int m = 0;
    int n = 0;
    int temp = 0;
    int count = 0;
    int dupCount = 0;
    int total = 0;
    int dCheckOne = 0;


    // This is a way to see the prizes

    int match0 = 0;
    int match1 = 0;
    int match2 =0;
    int match3 =0;
    int match4 = 0;
    int match5 = 0;
    int match2_1 =0;
    int match3_1 =0;
    int match4_1 = 0;
    int match5_1 = 0;
    int match2_2 =0;
    int match3_2 =0;
    int match4_2 = 0;
    int match5_2 = 0;
    int completeTotal = 0;


    //printf("This is test the value of lottoOne before any change\n");
    //for( i = 0; i < 5; i ++){
    //  printf("%i ", lottoOne[i]);
    //}

    //randomNumber = rand()%50+1;

    int lottoOneNums = 0;

    while( count < 5)
    {
      randomNumber = rand()%50+1;
      dupCount = 0;
      for(i = 0; i < 5; i++)
        {
          if( lottoOne[i] == randomNumber )
            {
            dupCount = 1;
            }
        }

          if ( dupCount == 0)
            {
            lottoOne[lottoOneNums] = randomNumber;
            count++;
            lottoOneNums++;
            }
     }




      int lottoOneNumsStar = 0;
      int starOneCount = 0;

      while( starOneCount < 2){
        randomNumber = rand()%12+1;
        dupCount = 0;
        for(i = 0; i < 2; i++){
            if( lottoOneStar[i] == randomNumber ){
              dupCount = 1;
            }
          }
            if ( dupCount == 0){
              lottoOneStar[lottoOneNumsStar] = randomNumber;
              starOneCount++;
              lottoOneNumsStar++;
            }
        }

/*
    printf("\nLotto one numbers randomly generated\n");
     for( i = 0; i < 5; i ++){
       printf("%i ", lottoOne[i]);
     }

   printf("\nLotto one stars numbers randomly generated\n");
  for( i = 0; i < 2; i ++){
    printf("%i ", lottoOneStar[i]);
    }

    printf("\n");

*/
    for( m = 0; m < 5; m++){
      for( n = 0; n < 5; n++){
        if( lottoOne[n] > lottoOne[n+1]){
            temp = lottoOne[n];
            lottoOne[n] = lottoOne[n+1];
            lottoOne[n+1] = temp;
        }
      }
    }

    int starTemp = 0;
    if( lottoOneStar[0] > lottoOneStar[1]){
      starTemp = lottoOneStar[0];
      lottoOneStar[0] = lottoOneStar[1];
      lottoOneStar[1] = starTemp;
      //printf("Swapped stars\n");
    }


  for ( i = 0; i < 5; i++){
    for( j = i+1; j < 5; j++){
      if( lottoOne[i] == lottoOne[j]){
        printf("Ok we have a dupe\n");
      }
    }
  }


  if( lottoOneStar[0] == lottoOneStar[1]){
      printf("We have a star dup\n");
  }

/*
   printf("\nLotto one numbers sorted\n");
    for( i = 0; i < 5; i ++){
      printf("%i ", lottoOne[i]);
    }

    printf(" \nLotto one star num sorted:");
    printf("\n%i %i\n", lottoOneStar[0], lottoOneStar[1]);

*/

    int lottoCheck = 10000000;
    int lottoId = 0;

    while ( lottoCheck != 0 ){

        int lottoTwo[5] = {0,0,0,0,0};
        int lottoTwoStar[2] = {0,0};

        //printf("This is test the value of lotto %i before any change\n",lottoId);
        //for( i = 0; i < 5; i ++){
        //printf("%i ", lottoTwo[i]);
        //}

        //printf("\n");

        int prizeDraw = 0;
        int lottoTwoNums = 0;
        int count = 0;
        while( count < 5){
          randomNumber = rand()%50+1;
          dupCount = 0;
          for(i = 0; i < 5; i++){
              if( lottoTwo[i] == randomNumber ){
                dupCount = 1;
              }
            }
              if ( dupCount == 0){
                lottoTwo[lottoTwoNums] = randomNumber;
                count++;
                lottoTwoNums++;
              }
          }


                int lottoTwoNumsStar = 0;
                int starTwoCount = 0;

                while( starTwoCount < 2){
                  randomNumber = rand()%12+1;
                  dupCount = 0;
                  for(i = 0; i < 2; i++){
                      if( lottoTwoStar[i] == randomNumber ){
                        dupCount = 1;
                      }
                    }
                      if ( dupCount == 0){
                        lottoTwoStar[lottoTwoNumsStar] = randomNumber;
                        starTwoCount++;
                        lottoTwoNumsStar++;
                      }
                  }



        //  printf("\nLotto two [%i] numbers randomly generated\n", lottoId);
        //  for( i = 0; i < 5; i ++){
        //    printf("%i ", lottoTwo[i]);
        //  }

      //  printf("\nLotto two stars numbers randomly generated\n");
       //for( i = 0; i < 2; i ++){
      //   printf("%i ", lottoTwoStar[i]);
      //   }


          //printf("\n");

          for( m = 0; m < 5; m++){
            for( n = 0; n < 5; n++){
              if( lottoTwo[n] > lottoTwo[n+1]){
                  temp = lottoTwo[n];
                  lottoTwo[n] = lottoTwo[n+1];
                  lottoTwo[n+1] = temp;
              }
            }
          }

          int starTwoTemp = 0;
          if( lottoTwoStar[0] > lottoTwoStar[1]){
            starTwoTemp = lottoTwoStar[0];
            lottoTwoStar[0] = lottoTwoStar[1];
            lottoTwoStar[1] = starTwoTemp;
            //printf("Swapped stars\n");
          }

          for ( i = 0; i < 5; i++){
            for( j = i+1; j < 5; j++){
              if( lottoOne[i] == lottoOne[j]){
                printf("Ok we have a dupe\n");
              }
            }
          }

          if( lottoTwoStar[0] == lottoTwoStar[1]){
              printf("We have a star dup\n");
          }

      //    printf("\nLotto two stars numbers in order\n");
      //   for( i = 0; i < 2; i ++){
      //     printf("%i ", lottoTwoStar[i]);
      //     }


        //  printf("\nLotto two[%i] :", lottoId);
        //  for( i = 0; i < 5; i ++){
        //    printf("%i ", lottoTwo[i]);
        //  }

        //  printf("\n");

        int lottoBothCheck = 0;
        int lottoStarBothCheck =0;



        for( i = 0; i < 5; i++){
            if( lottoOne[i] == lottoTwo[i]){
              lottoBothCheck++;
            }
        }

        for( i = 0; i < 5; i++){
          if ( lottoOneStar[i] == lottoTwoStar[i]){
            lottoStarBothCheck++;
          }
        }
        //printf("(%i) -> lottoOne[%i] lottoTwo[%i] = %i\n",lottoId, lottoId, lottoId, lottoStarBothCheck);

        if (lottoBothCheck == 0){
          match0++;
        }else if(lottoBothCheck == 1){
          match1++;
        }else if ( lottoBothCheck == 5 && lottoStarBothCheck == 2){
            match5_2++;
            printf("This happened at draw %i\n", lottoId);
            break;
          }  else if ( lottoBothCheck == 4 && lottoStarBothCheck == 2){
            match4_2++;
          }  else if ( lottoBothCheck == 3 && lottoStarBothCheck == 2){
            match3_2++;
          }  else if ( lottoBothCheck == 2 && lottoStarBothCheck == 2){
            match2_2++;
          }  else if ( lottoBothCheck == 5 && lottoStarBothCheck == 1){
            match5_1++;
          }  else if ( lottoBothCheck == 4 && lottoStarBothCheck == 1){
            match4_1++;
          }  else if ( lottoBothCheck == 3 && lottoStarBothCheck == 1){
            match3_1++;
          }  else if ( lottoBothCheck == 2 && lottoStarBothCheck == 1){
            match2_1++;
          } else if ( lottoBothCheck == 5){
            match5++;
          } else if ( lottoBothCheck == 4){
            match4++;
          } else if ( lottoBothCheck == 3){
            match3++;
          } else if( lottoBothCheck == 2){
          match2++;
        }

        lottoCheck--;
        lottoId++;
        prizeDraw =0;
    }




    float finalTotal = 0;

    finalTotal = (match2 * 2.30) + (match3 * 4.80) +(match4 * 16.80) + (match5 * 6079.30);
    finalTotal += (match2_1 * 2.90) + (match3_1 * 5.20) +(match4_1 * 45.20) + (match5_1 * 242775.50);
    finalTotal += (match2_2 * 4.60) + (match3_2 * 34.50) +(match4_2 * 589.10) + (match5_2 * 146729731);

    double jackpot = 160906372;
    printf("There were %i at match zero\n",match0);
    printf("There were %i at match one\n",match1);
    printf("You won %i at match 2 which is %.2f\n",match2, match2 * 2.30);
    printf("You won %i at match 3 which is %.2f\n",match3, match3 * 4.80);
    printf("You won %i at match 4 which is %.2f\n",match4, match4 * 16.80);
    printf("You won %i at match 5 which is %.2f\n",match5, match5 * 6079.30);
    printf("You won %i at match 2 1 star which is %.2f\n", match2_1, match2_1* 2.30);
    printf("You won %i at match 3 1 star which is %.2f\n", match3_1, match3_1* 5.20);
    printf("You won %i at match 4 1 star which is %.2f\n", match4_1, match4_1* 45.20);
    printf("You won %i at match 5 1 star which is %.2f\n", match5_1, match5_1* 242775.50);
    printf("You won %i at match 2 2 star which is %.2f\n", match2_2, match2_2* 4.60);
    printf("You won %i at match 3 2 star which is %.2f\n", match3_2, match3_2* 34.50);
    printf("You won %i at match 4 2 star which is %.2f\n", match4_2, match4_2* 589.10);
    printf("You won %i at match 5 2 star which is %.2f\n", match5_2,match5_2 *jackpot);


    printf("The total afer %i attempts is %.2f total\n", 10000000, finalTotal);

    int cost = 25000000;

    if( cost > finalTotal){
      printf("You lost %.2f\n", cost - finalTotal);
    } else if ( cost < finalTotal){
      printf("You won %.2f\n", finalTotal - cost);
    }





    return 0;
}
