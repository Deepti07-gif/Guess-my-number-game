#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h> // For log() and ceil()
int main()
{
//declare variables
int min=0,max=100;
int possibleguesses= max + min -1;//range of possible guesses
int maxturns=ceil(log(possibleguesses)/log(2));//log base 2 of possible guesses rounded up
int guess; //number that the computer guesses
int player;
int tries=1;//number of the try
clrscr();
textcolor(GREEN);
cprintf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tWELCOME TO NUMBER GUESSING GAME!!\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n");
//tell the player about the game
printf("\n\t->THINK OF A NUMBER FROM %d to %d.\n",min,max);

printf("\n\t->I can guess it in %d tries.\n",maxturns);
//Do a divide and conquer algorithm
do{
//update the new range
possibleguesses= max + min -1;
guess=(int)ceil(possibleguesses/2.0);
textcolor(MAGENTA);
cprintf("\n\t\t\t\t\tIs your number %d ??\n",guess);

printf("\n\t1.YES!You guessed my number.\n");
printf("\n\t2.NO!Guess a higher number.\n");
printf("\n\t3.NO!Guess a smaller number.\n");
printf("\n\tPlease Tell me If I was correct or not so enter 1,2 or 3: ");
scanf("%d",&player);

if(player==2)
min=guess+1;//update new lower range
else if(player==3)
max=guess-1;//update new higher range
else if(player==1)
break;//break out of the loop
tries++;//increment of number of tries
}while(player!=1 && tries<=maxturns);
//print the result
if(tries>maxturns)
printf("Something went wrong!!\nMaximum Number of tries exceeded!!");
else
//textcolor(RED);
printf("\n\tHurray!I guessed it in %d tries.Your number is %d",tries,guess);
getch();
return 0;
}