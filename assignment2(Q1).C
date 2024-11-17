#include <stdio.h>  
int main() { 
    int marks[5],i,j; 
     
    for(i=0;i<=4;i=i+1) { 
        printf("Enter marks of student-%d :",i+1); 
        scanf("%d",&marks[i]); 
    } 
     
    printf("\n# Updated marks list of student's\n"); 
 
    for(j=0;j<=4;j=j+1) { 
        printf("Final marks of student-%d : %d\n",j+1,marks[j]+5); 
    } 
    return 0; 
} 