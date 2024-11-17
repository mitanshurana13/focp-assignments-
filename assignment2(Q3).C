#include <stdio.h>  
int main() { 
    int marks[5],i; 
     
    for(i=0;i<=4;i=i+1) { 
        printf("Enter marks of student-%d :",i+1); 
        scanf("%d",&marks[i]); 
    } 
 
    for(i=0;i<=4;i=i+1) { 
        if (marks[i]==99){ 
            printf("Student-%d has scored first 99 marks",i+1); 
            break; 
        } 
    } 
    return 0; 
} 