//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

void swap( int *a, int *b); // fine
int directionConvertor( char arrow);// fine
void randomise ( int board[], int width);// fine
int tileConversion( int board[], int tile);//fine
int *createBoard(int board[], int width); // fine
void printBoard ( int board[], int width); // fine
void makeMove ( int board[], int tileBoardConversion , int direction , int width, int OriginalTileNumber); // fine
void generateRandomMove(int board[], int width); // fine
void up( int board[], int tile , int width); // fine could do without width maybe size of
void down( int board[], int tile, int width); // fine
void left( int board[], int tile, int width); // fine
void right( int board[], int tile , int width); //



void swap( int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int directionConvertor( char arrow)
{
if ( arrow == 'u' || arrow == 'U')
  return 1;
else if ( arrow == 'd' || arrow == 'D')
  return 2;
else if ( arrow == 'l' || arrow == 'L')
  return 3;
else if ( arrow == 'r' || arrow == 'R')
  return 4;
else
  return 0;
}

int tileConversion( int board[], int tile)
{
  int countElement = 0;
  int tileBoardConversion = 0;
  while( board[countElement] != tile)
  {
    countElement++;
    tileBoardConversion++;
  }
  return tileBoardConversion;
}



void randomise ( int board[], int width)
{
    for(int i = width*width - 1; i > 0; i--)
    {
      int j = rand() % (i + 1);
      swap(&board[i], &board[j]);
    }
}

int *createBoard(int board[], int width)
{
    for ( int i = 0; i <= width * width; i++)
      board[i] = i;
    return 0;
}

void printBoard ( int board[], int width) // could tidy up the board for load of numbers 20 20 have a neter square

{
    printf("\n");
    for ( int i = 0; i < width*width; i++ )
    {
        if( i != 0 && i % width == 0)
          printf("\n\n");
        printf(" [%2i] ", board[i]);
    }
    printf("\n\n\n");
}

void up( int board[], int tileBoardConversion , int width)
{
      //if (tileBoardConversion/width ==0)
      if( tileBoardConversion < width)
        printf("Invalid move you will hit the top of the box\n");
      else if( board[tileBoardConversion - width] == 0  && board[tileBoardConversion] != 0)
        swap(&board[tileBoardConversion -width], &board[tileBoardConversion]);
      else if(board[tileBoardConversion] == 0 && board[tileBoardConversion - width] != 0)
        swap(&board[tileBoardConversion], &board[tileBoardConversion-width]); // move zero
      else
        printf("Up is not a valid move\n");
}

void down( int board[], int tileBoardConversion, int width)
{
      if( tileBoardConversion >= ((width*width) - width)  )
        printf("Invalid move you will hit the top of the box\n");
      else if( board[tileBoardConversion + width] == 0  && board[tileBoardConversion] != 0)
        swap(&board[tileBoardConversion + width], &board[tileBoardConversion]);
      else if(board[tileBoardConversion] == 0 && board[tileBoardConversion + width] != 0)
        swap(&board[tileBoardConversion], &board[tileBoardConversion+width]); // move zero
      else
        printf("Up is not a valid move\n");
}

void left( int board[], int tileBoardConversion, int width)
{
      if(tileBoardConversion == 0 || tileBoardConversion % width == 0 )
        printf("Invalid move you will hit the left edge\n");
      else if( board[tileBoardConversion -1] == 0  && board[tileBoardConversion] != 0)
        swap(&board[tileBoardConversion], &board[tileBoardConversion-1]);
      else if( board[tileBoardConversion] == 0  && board[tileBoardConversion - 1] != 0 && tileBoardConversion != 0 && tileBoardConversion % width !=0)
        swap(&board[tileBoardConversion], &board[tileBoardConversion-1]); // move zero
      else
        printf("Left is not a valid move\n");
}

void right( int board[], int tileBoardConversion , int width)
{
      //if( tileBoardConversion != 0 &&   tileBoardConversion -1 % width == 0 )
      if ( tileBoardConversion >= (width *width) - 1 || tileBoardConversion + 1 % width == 0)
        printf("Invalid move you will hit the right edge\n");
      else if( board[tileBoardConversion +1] == 0  && board[tileBoardConversion] != 0)
        swap(&board[tileBoardConversion+1], &board[tileBoardConversion]);
      else if(board[tileBoardConversion] == 0 && (tileBoardConversion + 1) % width != 0 && board[tileBoardConversion + 1] != 0 )
        swap(&board[tileBoardConversion], &board[tileBoardConversion + 1]); // move zero
      else
        printf("Right is not a valid move\n");
}

void generateRandomMove(int board[], int width)
{

      int x = 0;;
      int the_tile = tileConversion(board, 0); // the tile could be name better
      printf("Zero is at array element [%i]\n", the_tile);
      x= rand()%4+1;
      printf("The random number is %i\n", x);

      if ( x == 1)
      {
        printf("The direction is up");
        up(board, the_tile ,width);
      }
      else if (x == 2)
      {
        printf("The direction is down");
        down(board, the_tile, width);
      }
      else if (x == 3)
      {
        printf("The direction is down");
        left(board, the_tile, width);
      }
      else if (x == 4)
      {
        printf("The direction is right");
        right(board, the_tile, width);
      }
      else
      {
        printf("Invalid\n");
      }

}

void makeMove ( int board[], int tileBoardConversion , int direction , int width, int OriginalTileNumber)
{
          char move;

          if (direction == 1)
            move = 'U';
          else if (direction == 2)
            move = 'D';
          else if (direction == 3)
            move = 'L';
          else if (direction == 4)
            move = 'R';
          else
            move = '?';

          printf("\nthe tile is %i the array element is %i and direction is %c\n",
                    OriginalTileNumber, tileBoardConversion, move);

          if( direction == 1)
              up(board, tileBoardConversion ,width);
          else if( direction == 2)
              down(board, tileBoardConversion, width);
          else if( direction == 3)
              left(board, tileBoardConversion, width);
          else if( direction == 4)
              right(board, tileBoardConversion, width);
          else
              printf("Invalid input");

}


int checkWin( int board[] , int width)
{
    int state = 1;
    for( int i = 0 ; i < (width * width) -1; i++ )
    {
      if(board[i] != i+1 )
      {
        state = 0;
        break;
      }
    }
      if (state == 0)
        {
        printf("Not a win\n");
        return 0;
        }
      else
      {
        printf("You win\n");
        return 1;
      }
}


int main (void)
{

    srand(time(NULL));
    int width = 0;
    printf("Please tell me how big you want the array to be\n");
    scanf("%i", &width);
    int board[width*width];
    int OriginalTileNumber = 0;
    int directionMain = 0;
    char arrow = 'X';
    int state = 0;
    int turnCount = 0;
    int countElement= 0;
    int tileBoardConversion = 0;
    createBoard(board, width);
    randomise(board, width);
    //printBoard(board, width);
    //checkWin(board, width);

    while(state != 1 && turnCount <= 1)
    {

      printf("-------Turn %i -------\n", turnCount );
      printBoard(board, width);
      printf("Which direction?\n");
      scanf(" %c", &arrow);
      directionMain = directionConvertor(arrow);
      printf("Which num to move\n");
      scanf("%i", &OriginalTileNumber);
      printf("========\n");
      tileBoardConversion = tileConversion(board, OriginalTileNumber);
      makeMove(board, tileBoardConversion, directionMain, width, OriginalTileNumber);
      printf("-------Turn %i -------\n", turnCount );
      printBoard(board, width);
      //generateRandomMove(board,width);
      state = checkWin(board, width);
      turnCount++;
      //arrow = 'X';
    }
    printf("\n\n");

    printBoard(board, width);


    return 0;

}
