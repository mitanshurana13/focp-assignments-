#include <stdio.h> 
#include <math.h> 
int main() { 
    int choice,i,digit,num2; 
    float num[20]={0},sum,sub,mult,div,num1,num3; 
 
    printf("\t# To add number's enter 1\n"); 
    printf("\t# To subtract number's enter 2\n"); 
    printf("\t# To multiply number's enter 3\n"); 
    printf("\t# To divide number's enter 4\n"); 
    printf("\t# To calculate logarithmic value enter 5\n"); 
    printf("\t# To calculate square of number's enter 6\n"); 
     
    printf("\nEnter your choice :"); 
    scanf("%d",&choice); 
     
    if (choice!=4 && choice<=6 && choice>=1) { 
    printf("\nEnter on how many digit's you want to perform above mentioned operation :"); 
    scanf("%d",&digit); 
 
    for(i=0;i<=digit-1;i=i+1) { 
        printf("Enter digit-%d :",i+1); 
        scanf("%f",&num[i]); 
    } 
    } 
 
if (choice>=1 && choice<=6) { 
        if (choice==1) { 
            for(i=0,sum=0;i<=digit-1;i=i+1) { 
                sum=sum+num[i]; 
            } 
            printf("Addition of number's is %f\n",sum); 
        } 
        else if (choice==2) { 
            for(i=0,sub=0;i<=digit-1;i=i+1) { 
                sub=sub-num[i]; 
                } 
                printf("Subtraction of number's is %f\n",sub); 
        } 
        else if (choice==3) { 
            for(i=0,mult=1,num;i<=digit-1;i=i+1) { 
                mult=mult*num[i]; 
            } 
            printf("Multiplication of number's is %f",mult); 
        } 
        else if (choice==4) { 
            printf("Enter a number to be divided :"); 
            scanf("%f",&num1); 
            printf("Enter how many time's you want to divide %.2f :",num1); 
            scanf("%d",&num2); 
            for(i=0,div=1;i<=num2-1;i=i+1) { 
                printf("Enter divisor-%d :",i+1); 
                scanf("%f",&num3); 
                div=num1/num3; 
                printf("Divison = %f\n",div); 
            } 
            } 
        else if (choice==5) { 
            for(i=0;i<=digit-1;i=i+1) { 
            printf("Logarithmic value of %.2f is %f\n",num[i],log(num[i])); 
            } 
        } 
        else if (choice==6) { 
            for(i=0;i<=digit-1;i=i+1) { 
                printf("Square of %.2f is %f\n",num[i],num[i]*num[i]); 
            } 
        } 
    } 
    else { 
        printf("# INVALID CHOICE"); 
    } 
   return 0; 
} 