// rock paper scissors


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

  int Bool = 1;
  char answer = ' ';
  int score = 0;
  int comp_score = 0;
  char choice;
  int compChoice = 0;
  char test;
  int playerScore = 0;
  int computerScore = 0;
  int loop = 0;
  // need srand
  // 1 rock, 2 scissors, 3 = paper
  // could have used switch maybe


  printf("Would you like to play a game:\n");
  scanf("%c", &answer);


  while (answer != 'n' /*Bool == 1*/)
  {
    //answer = ' ';
      //choice = ' ';
      //printf("Would you like to play a game:\n");
      //scanf("%c", &answer);


        if ( answer == 'y')

          {//a
            printf("Please choose r/p/s\n");
            scanf(" %c", &choice);
            compChoice = rand()%3;
            printf("You choose %c ", choice);

              if ( compChoice == 1)
                { //n
                  printf(" - r choosen by comp\n");
                } //n
                else if ( compChoice ==2 )
                { //m
                  printf(" - s choosen by comp\n");
                } //m
                else if ( compChoice ==3 )
                { // l
                  printf(" - p choosen by comp\n");
                } //l
                else if (compChoice == 1 && choice == 'r')
                { //k
                  printf("Draw\n");
                } //k
                else if (compChoice == 1 && choice == 'p')
                { //j
                  printf("Player wins.\n");
                  playerScore++;
                } //j
                else if (compChoice == 1 && choice == 's')
                { //i
                  printf("Computer wins.\n");
                  computerScore++;
                } //i
                else if (compChoice == 2 && choice == 'r')
                { //h
                  printf("Player wins.\n");
                  playerScore++;
                } //h
                else if (compChoice == 2 && choice == 's')
                {//g
                  printf("Draw.\n");
                } //g
                else if (compChoice == 2 && choice == 'p')
                { //f
                  printf("Computer wins.\n");
                  computerScore++;
                } //e
                else if (compChoice == 3 && choice == 'r')
                { //d
                  printf("Player wins.\n");
                  playerScore++;
                } //d
                else if (compChoice == 3 && choice == 's')
                { //c
                  printf("Player wins.\n");
                  playerScore++;
                } //c
                else if (compChoice == 3 && choice == 'p')
                { //b
                  printf("Draw\n");
                } //b


            //printf("Your choice is %c\n", choice);
            //printf("compChoice = %i\n", compChoice);

          } // a
                  else if (answer == 'n')
                {
                  //Bool = 0;
                  printf("Game over\n");
                }



             loop++;
             printf("Number of games played = %d\n",loop);
             answer = 'n';
             answer = ' ';
             printf("Would you like to play a game:\n");
             scanf("%c", &answer);
             //if( answer == 'n')
            //   break;


  }






  if( playerScore > computerScore){
    printf("Player wins, %i - %i\n", playerScore, computerScore);
  } else if ( computerScore > playerScore){
    printf("Computer wins, %i - %i\n", computerScore,playerScore);
  } else {
    printf("Draw %i - %i\n", computerScore,playerScore);
  }

  return 0;
}
