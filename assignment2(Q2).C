#include <stdio.h> 
int main() { 
    int marks[5],i; 
 
    for(i=0;i<=4;i=i+1) { 
        printf("Enter marks of student-%d :",i+1); 
        scanf("%d",&marks[i]); 
    } 
 
    printf("\n# Grade list of student's as per marks\n"); 
 
    for(i=0;i<=4;i=i+1) { 
        if (marks[i]>=75) 
        printf("Student-%d has achieved Grade-A\n",i+1); 
        else if (marks[i]>=60 && marks[i]<75) 
        printf("Student-%d has achieved Grade-B\n",i+1); 
        else if (marks[i]>=40 && marks[i]<60) 
        printf("Student-%d has achieved Grade-C\n",i+1); 
        else if (marks[i]>=0 && marks[i]<40) 
        printf("Student-%d has achieved Grade-D\n",i+1); 
        else 
        printf("NOTE--Enter marks on scale of 0-100.\n"); 
    } 
    return 0; 
} 