#include<stdio.h> 
#include<stdlib.h> 
int mutex=1,full=0,empty=3,x=0; 
void main() 
{ 
 int n; 
 void producer(); 
 void consumer(); 
 int wait(int); 
 int signal(int); 
 printf("\n 1.Producer 2.Consumer 3.Exit:"); 
 while(1) 
 { 
  printf("\n Enter your choice:"); 
  scanf("%d",&n); 
  switch(n) 
  { 
   case 1:if((mutex==1)&&(empty!=0)) 
    producer(); 
    else 
    printf("Buffer is full"); 
    break; 
   case 2:if((mutex==1)&&(full!=0)) 
    consumer(); 
22 
 
    else 
    printf("Buffer is empty"); 
    break; 
   case 3:exit(0); 
    break; 
  } 
 } 
} 
int wait(int s) 
{ while(s<=0); 
 return(--s); 
} 
int signal(int s) 
{ 
 return (++s); 
} 
void producer() 
{     
     empty=wait(empty); 
 mutex=wait(mutex); 
  
  
 x++; 
 printf("Producer produces item %d",x); 
 mutex=signal(mutex); 
 full=signal(full); 
} 
void consumer() 
{     full=wait(full); 
mutex=wait(mutex); 
printf("Consumer consumes item %d",x); 
x--; 
mutex=signal(mutex); 
empty=signal(empty); 
}