// password generator

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

    int password[100];
    int number = 0;
    int i = 0;
    int j = 0;
    time_t secondsFromEpoch = time(NULL);
    srand(secondsFromEpoch);


    printf("How many characters do you want you password?\n");
    scanf("%i", &number);

    for ( i = 0; i <= number; i++){
          password[i] =  (rand()%94+33);
    }

    for ( j = 0; j <= number; j++){
        printf("%i\n", password[j]);
    }


    for ( j = 0; j <= number; j++){
        printf("%c", password[j]);

    }

    printf("\n");

    return 0;


}
