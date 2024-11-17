#include <stdio.h>  
int main() { 
    int marks[5],i,sum=0; 
     
    for(i=0;i<=4;i=i+1) { 
        printf("Enter marks of student-%d :",i+1); 
        scanf("%d",&marks[i]); 
    } 
 
    for(i=0,sum;i<=4;i=i+1) { 
        if (marks[i]==99){ 
            printf("\nStudent-%d has scored 99 marks",i+1); 
            sum=sum+1; 
        } 
    } 
    printf("\n\n%d student's has scored 99 marks",sum); 
    return 0; 
} 