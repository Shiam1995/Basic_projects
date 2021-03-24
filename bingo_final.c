/* Shiam
  23/03/2021
  Bingo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>


void delay(int seconds)
{

    int milliseconds = 1000 * seconds;
    clock_t start_time = clock();

    while (clock() < start_time + milliseconds)
    ;
}

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void randomise ( int arr[], int n)
{
    srand(time(NULL));

    for ( int i = n - 1; i > 0 ; i--)
    {
        int j = rand()% (i + 1);


        swap(&arr[i], &arr[j]);
    }
}


int main (void)
{

  printf("Program start\n\n\n");

  srand(time(NULL));
  int raffle = 0;

  //int array[5][5];
  int array[25];
  int compArray[25];
  int playerCard[25];
  int compCard[25];
  int ballsCalled[100];
  int balls[100];
  int i = 0;
  int j = 0;
  int a = 0;
  int b = 0;
  int z = 0;
  int sizeBalls = 0;
  int dup;
  int count = 0;
  int compCount = 0;
  int userNum = 0;
  int compNum = 0;
  int playerWin = 0;
  int compWin = 0;
  char answer = ' ';
  char happyWith = 'n';
  int bingoball = 0;
  int pRow_1 = 0 ,pRow_2 = 0, pRow_3 = 0, pRow_4 = 0, pRow_5 = 0;
  int cRow_1 = 0 ,cRow_2 = 0, cRow_3 = 0, cRow_4 = 0, cRow_5 = 0;
  int pCol_1 = 0 ,pCol_2 = 0, pCol_3 = 0, pCol_4 = 0, pCol_5 = 0;
  int cCol_1 = 0 ,cCol_2 = 0, cCol_3 = 0, cCol_4 = 0, cCol_5 = 0;
  int pdiagonal1, pdiagonal2 = 0; // to be done
  int cdiagonal1, cdiagonal2 = 0; //  to be done
  int cWin = 0;
  int pWin = 0;

  for (i = 0; i<= 99; i++)
  {
  balls[i] = i;
  }

  sizeBalls = sizeof(balls)/sizeof(balls[0]);
  randomise(balls, sizeBalls);

  //for (i = 0; i <= 99; i++)
  //{
  //printf("%i\n", balls[i]);  }

  for( i = 0; i <= 100; i++)
  {
    ballsCalled[i] = 100;
  }

  for( i = 0; i <= 24; i++)
  {
    array[i] = 100;
  }




  printf("Would you like a randomly generated card please type (y\\n) \n");
  scanf("%c", &answer);

  if (answer == 'y')
  {
    happyWith = 'n';
    while ( happyWith != 'y')
    {
        while ( count <= 24)
          {

              userNum = rand()%98+1;
              dup = 0;
              for ( i = 0; i <= count; i++)
              {
                if(array[i] == userNum )
                {
                  dup = 1;
                }
              }
                if(dup != 1)
                {
                  array[count] = userNum;
                  //printf("count = %i\n", count);
                  count++;
                }

                for( i = 0; i <= 24; i++)
                {
                playerCard[i] = array[i];
                compCard[i] = compArray[i];
                }
            }

            printf("User card\n");
            for (  i = 0; i <= 24; i++)
            {
              if (i % 5 == 0)
              {
                printf("\n");
              }
              printf(" | %3i | ", playerCard[i]);
              }
            printf("\n");
            printf("Are you happy with this card?\n");
            scanf(" %c", &happyWith);
            count = 0;
          }
      }
      else if (answer != 'y')
      {

        while ( count <= 24)
        {

          printf("Please enter the number you would like between 1-99\n\n");
          scanf("%i", &userNum);
          dup = 0;

          if(userNum > 0 && userNum > 99)
          {
            printf("Number too big\n");
            dup = 2;
          }

          if ( userNum < 1)
          {
            printf("Number too small\n");
            dup = 2;
          }

          for ( i = 0; i <= count; i++)
          {
            if(array[i] == userNum )
            {
              dup = 1;
              printf("%i has already been choosen\n", userNum);
            }
          }

          if(dup == 0)
          {
            printf("[%i] = %i\n", count, userNum);
            array[count] = userNum;
            printf("count = %i\n\n", count);
            count++;
          }
          else
          {
          printf("Pick another number between 1-99\n\n");
          }


  }

}
  // Comp num
  while ( compCount <= 24)
  {


    compNum = rand()%98+1;
    dup = 0;

    for ( i = 0; i <= count; i++)
    {
      if(compArray[i] == compNum )
      {
      dup = 1;
      }
    }

    if(dup != 1)
    {

      compArray[compCount] = compNum;
      printf("count = %i\n", count);
      compCount++;
    }



  }

  for( i = 0; i <= 24; i++)
  {
    playerCard[i] = array[i];
    compCard[i] = compArray[i];
  }

  printf("User card\n");

  for (  i = 0; i <= 24; i++)
  {
    if (i % 5 == 0)
    {
      printf("\n");
    }

    printf(" | %i | ", playerCard[i]);
  }


  printf("\nComp card\n");

  for (  i = 0; i <= 24; i++)
  {
    if (i % 5 == 0)
    {
      printf("\n");
    }

    printf(" | %i | ", compCard[i]);
  }




int k;
k = 0;


  for ( z = 0; z <= 100; z++)

  {

    bingoball = balls[k];
    printf("The number is %i\n", bingoball);
    printf("The draw is %i\n", z);
    ballsCalled[z] = bingoball;
    k++;
    printf("\n\n\n\n");
      for (  i = 0 ; i <= 24; i++)
      {
        if( bingoball == playerCard[i])
        {
          playerCard[i] = 100;
          playerWin++;
          printf("Player has a match\n");
        }
      }

      for (  i = 0 ; i <= 24; i++)
      {
        if( bingoball == compCard[i])
        {
          compCard[i] = 100;
          compWin++;
          printf("Comp has a match\n");
        }
      }
      printf("\n");
      printf(" Current scores are player:[%i], comp:[%i]\n", playerWin, compWin);
      printf("\n");
      printf("User card\n");

      for (  i = 0; i <= 24; i++)
      {
        if (i % 5 == 0)
        {
          printf("\n");
        }

        printf(" | %3i | ", playerCard[i]);
      }
      printf("\n");

      printf("\nComp card\n");

      for (  i = 0; i <= 24; i++)
      {
        if (i % 5 == 0)
        {
          printf("\n");
        }

        printf(" | %3i | ", compCard[i]);
      }

      printf("\n");
      delay(100);
      printf("\n");

      pRow_1 = playerCard[0]+playerCard[1]+playerCard[2]+playerCard[3]+playerCard[4];
      pRow_2 = playerCard[5]+playerCard[6]+playerCard[7]+playerCard[8]+playerCard[9];
      pRow_3 = playerCard[10]+playerCard[11]+playerCard[12]+playerCard[13]+playerCard[14];
      pRow_4 = playerCard[15]+playerCard[16]+playerCard[17]+playerCard[18]+playerCard[19];
      pRow_5 = playerCard[20]+playerCard[21]+playerCard[22]+playerCard[23]+playerCard[24];


      cRow_1 = compCard[0]+compCard[1]+compCard[2]+compCard[3]+compCard[4];
      cRow_2 = compCard[5]+compCard[6]+compCard[7]+compCard[8]+compCard[9];
      cRow_3 = compCard[10]+compCard[11]+compCard[12]+compCard[13]+compCard[14];
      cRow_4 = compCard[15]+compCard[16]+compCard[17]+compCard[18]+compCard[19];
      cRow_5 = compCard[20]+compCard[21]+compCard[22]+compCard[23]+compCard[24];

      pCol_1 = playerCard[0]+playerCard[5]+playerCard[10]+playerCard[15]+playerCard[20];
      pCol_2 = playerCard[1]+playerCard[6]+playerCard[11]+playerCard[16]+playerCard[21];
      pCol_3 = playerCard[2]+playerCard[7]+playerCard[12]+playerCard[17]+playerCard[22];
      pCol_4 = playerCard[3]+playerCard[8]+playerCard[13]+playerCard[18]+playerCard[23];
      pCol_5 = playerCard[4]+playerCard[9]+playerCard[14]+playerCard[19]+playerCard[24];


      cCol_1 = compCard[0]+compCard[5]+compCard[10]+compCard[15]+compCard[20];
      cCol_2 = compCard[1]+compCard[6]+compCard[11]+compCard[16]+compCard[21];
      cCol_3 = compCard[2]+compCard[7]+compCard[12]+compCard[17]+compCard[22];
      cCol_4 = compCard[3]+compCard[8]+compCard[13]+compCard[18]+compCard[23];
      cCol_5 = compCard[4]+compCard[9]+compCard[14]+compCard[19]+compCard[24];

      pdiagonal1 = playerCard[0]+playerCard[6]+playerCard[12]+playerCard[18]+playerCard[24]; // to be done
      cdiagonal1 = compCard[0]+compCard[6]+compCard[12]+compCard[18]+compCard[24]; //  to be done
      pdiagonal2 = playerCard[4]+playerCard[8]+playerCard[12]+playerCard[16]+playerCard[20]; // to be done
      cdiagonal2 = compCard[4]+compCard[8]+compCard[12]+compCard[16]+compCard[20];

      if (pRow_1 == 500)
      {
        printf("Player wins\n");
        printf("Row 1 on turn %i\n", z);
        pWin = z;
        break;
      }
       else if ( pRow_2 == 500)
      {
        printf("Player wins\n");
        printf("Row 2 on turn %i\n", z);
        pWin = z;
        break;
      }
      else if ( pRow_3 == 500)
      {
       printf("Player wins\n");
       printf("Row 3 on turn %i\n", z);
       pWin = z;
       break;
      }
      else if ( pRow_4 == 500)
      {
       printf("Player wins\n");
       printf("Row 4 on turn %i\n", z);
       pWin = z;
       break;
      }
      else if ( pRow_5 == 500)
      {
      printf("Player wins\n");
      printf("Row 5 on turn %i\n", z);
      pWin = z;
      break;
      }
      else if ( pCol_1 == 500)
     {
       printf("Player wins\n");
       printf("Col 1 on turn %i\n", z);
       pWin = z;
       break;
     }
     else if ( pCol_2 == 500)
     {
      printf("Player wins\n");
      printf("Col 2 on turn %i\n", z);
      pWin = z;
      break;
     }
     else if ( pCol_3 == 500)
     {
      printf("Player wins\n");
      printf("Col 3 on turn %i\n", z);
      pWin = z;
      break;
     }
     else if ( pCol_4 == 500)
     {
     printf("Player wins\n");
     printf("Col 4 on turn %i\n", z);
     pWin = z;
     break;
     }
     else if ( pCol_5 == 500)
     {
     printf("Player wins\n");
     printf("Col 5 on turn %i\n", z);
     pWin = z;
     break;
     }
     else if ( pdiagonal1 == 500)
     {
     printf("Player wins\n");
     printf("diagnoal 1 (R->L) on turn %i\n", z);
     pWin = z;
     break;
     }
     else if ( pdiagonal2 == 500)
     {
     printf("Player wins\n");
     printf("diagnoal 2(R->L) on turn %i\n", z);
     pWin = z;
     break;
     }

     if (cRow_1 == 500)
     {
       printf("comp wins\n");
       printf("Row 1 on turn %i\n", z);
       cWin = z;
       break;
     }
      else if ( cRow_2 == 500)
     {
       printf("comp wins\n");
       printf("Row 2 on turn %i\n", z);
       cWin = z;
       break;
     }
     else if ( cRow_3 == 500)
     {
      printf("comp wins\n");
      printf("Row 3 on turn %i\n", z);
      cWin = z;
      break;
     }
     else if ( cRow_4 == 500)
     {
      printf("comp wins\n");
      printf("Row 4 on turn %i\n", z);
      cWin = z;
      break;
     }
     else if ( cRow_5 == 500)
     {
     printf("comp wins\n");
     printf("Row 5 on turn %i\n", z);
     cWin = z;
     break;
     }
     else if ( cCol_1 == 500)
    {
      printf("comp wins\n");
      printf("Col 1 on turn %i\n", z);
      cWin = z;
      break;
    }
    else if ( cCol_2 == 500)
    {
     printf("comp wins\n");
     printf("Col 2 on turn %i\n", z);
     cWin = z;
     break;
    }
    else if ( cCol_3 == 500)
    {
     printf("comp wins\n");
     printf("Col 3 on turn %i\n", z);
     cWin = z;
     break;
    }
    else if ( cCol_4 == 500)
    {
    printf("comp wins\n");
    printf("Col 4 on turn %i\n", z);
    cWin = z;
    break;
    }
    else if ( cCol_5 == 500)
    {
    printf("comp wins\n");
    printf("Col 5 on turn %i\n", z);
    cWin = z;
    break;
    }
    else if ( cdiagonal1 == 500)
    {
    printf("comp wins\n");
    printf("diagnoal 1 (R->L) on turn %i\n", z);
    cWin = z;
    break;
    }
    else if ( cdiagonal2 == 500)
    {
    printf("comp wins\n");
    printf("diagnoal 2(R->L) on turn %i\n", z);
    cWin = z;
    break;
    }

  }

  printf("Final score is player:[%i], comp:[%i]\n", playerWin, compWin);

  if(cWin == pWin)
  {
    printf("We have a tie\n");
  }
  else if (cWin > pWin)
  {
    printf("Comp wins\n");
  }
  else
  {
    printf("Player wins\n");
  }

  printf("User card\n");

  for (  i = 0; i <= 24; i++)
  {
    if (i % 5 == 0)
    {
      printf("\n");
    }

    printf(" | %3i | ", playerCard[i]);
  }


  printf("\nComp card\n");

  for (  i = 0; i <= 24; i++)
  {
    if (i % 5 == 0)
    {
      printf("\n");
    }

    printf(" | %3i | ", compCard[i]);
  }

  printf("\n\n\n");
/*
  printf("The numbers drawn are\n");

  i = 0;
  while(ballsCalled[i] != 100)
  {
    printf(" draw[%i] = [%i]\n", i, ballsCalled[i]);
    i++;
  }
*/
  printf("\n\n\n Program end\n\n\n\n");

  return 0;

}
