#include <stdio.h>

//Programme to check whether a number is armstrong or not

int main() {
    int num,remainder,sum=0,num1;
    printf("Enter a number :");
    scanf("%d",&num);
    num1=num;

    while (num1!=0) {
        remainder=num1%10;
        sum=sum+(remainder*remainder*remainder);
        num1=num1/10;
        
    }

    if (sum==num)
    printf("%d is an armstrong number.",num);
    else
    printf("%d is not an armstrong number.",num);
    
    return 0;


}