#include<stdio.h> 

int main(){ 

  int x,y; 

  printf("enter x and y:"); 

  scanf("%d %d",&x,&y); 

if(x>0 && y>0){ 

     printf("x=%d & y=%d in 1st quadrant",x,y); 

} 

else if(x<0 && y>0){ 

    printf("x=%d & y=%d in 2nd quadrant",x,y); 

} 

else if(x<0 && y<0){ 

    printf("x=%d & y=%d in 3rd quadrant",x,y); 

} 

else if(x>0 && y<0){ 

    printf("x=%d & y=%d in 4th quadrant",x,y); 

} 

else if(x=0 && y!=0){ 
     printf("point on y axis y=%d",y); 

} 

else if(y=0 && x!=0){ 

    printf("point on x axis",x); 

} 

else{ 

     printf("point on origin"); 

} 

  

    return 0; 

} 