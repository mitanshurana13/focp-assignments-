#include <stdio.h>
#include <stdlib.h>
int main() {
    int user_choice,computer_choice=rand() %1501,num,round,i=1,num1;

    printf("\nEnter number of round's you want to play :");
    scanf("%d",&round);
    
while (round >= i) {
    printf("\n\t 1).To select ROCK enter your choice as 1\n");
    printf("\t 2).To select PAPER enter your choice as 2\n");
    printf("\t 3).To select SCISSOR enter your choice as 3\n");
    
    printf("\nEnter your choice :");
    scanf("%d",&user_choice);

    if (user_choice==1)
    printf("You have selected ROCK\n");
    else if (user_choice==2)
    printf("You have selected PAPER\n");
    else if (user_choice==3)
    printf("You have selected SCISSOR\n");
    else {
    printf("# INVALID CHOICE\n");
    printf("# Game has been terminated");
    break;
    }
     
    if (computer_choice>=0 && computer_choice<=500){
    printf("System has selected ROCK\n");
    num=1;
    }
    else if (computer_choice>500 && computer_choice<=1000){
    printf("System has selected PAPER\n");
    num=2;
    }
    else {
    printf("System has selected SCISSOR\n");
    num=3;
    }

    if (user_choice==num){
    printf("\n\tMATCH TIE\n");
    }
    else if ((user_choice==1 && num==3) || (user_choice==2 && num==1
              ) || (user_choice==3 && num==2))
    printf("\n\tCongratulation's !!! You have won the game\n");
    else{
    printf("\n\tOops !!! System has won the game\n");
    printf("\t      Better luck next time\n");
    }

    printf("\nNOTE- if you want to exit press-9 :");
    scanf("%d",&num1);
    if (num1==9) {
        printf("You have successfully exited from game");
        break;
    }
    else 
    continue;

    i=i+1;

}
return 0;
}
    

