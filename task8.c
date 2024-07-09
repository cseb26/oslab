// first fit 
#include<stdio.h> 
#define max 25 
void main() 
{  int frag[max],b[max],f[max],i,j,nb,nf,temp,highest=0; 
static int bf[max],ff[max]; 
printf("Memory management Scheme-first fit"); 
printf("\nenter number of blocks:"); 
scanf("%d",&nb); 
printf("\n enter the number of files:"); 
scanf("%d",&nf); 
printf("\n enter size of blocks:"); 
for(i=1;i<=nb;i++) 
{     printf("\nblock %d:",i); 
scanf("%d",&b[i]); 
} 
printf("\n enter size of files:"); 
for(i=1;i<=nf;i++) 
{ 
printf("\nfile %d:",i); 
scanf("%d",&f[i]); 
} 
for(i=1;i<=nf;i++) 
{ 
for(j=1;j<=nb;j++) 
{ 
if(bf[j]!=1) 
{ 
temp=b[j]-f[i]; 
if(temp>=0) 
34 
{ 
ff[i]=j; 
break;  
} 
} 
} 
frag[i]=temp; 
bf[ff[i]]=1; 
} 
printf("\n file no\tfile size\tblock no\tblocksize\tfragment"); 
for(i=1;i<=nf;i++) 
printf("\n %d  \t %d \t %d \t %d \t %d",i,f[i],ff[i],b[ff[i]],frag[i]); 
}


// ============================================================
// best fit
#include<stdio.h> 
#define MAX 25 
void main() 
{ 
int frag[MAX],b[MAX],f[MAX],i,j,nb,nf,temp,lowest=10000; 
static int bf[MAX],ff[MAX]; 
printf("\nEnter the number of blocks"); 
scanf("%d",&nb); 
printf("\nEnter the number of files"); 
scanf("%d",&nf); 
printf("\nEnter the size of the blocks"); 
for(i=1;i<=nb;i++) 
{ 
printf("\nBlock %d",i); 
scanf("%d",&b[i]); 
} 
printf("\nEnter the size of files"); 
for(i=1;i<=nf;i++) 
{ 
printf("\nFile %d",i); 
scanf("%d",&f[i]); 
} 
for(i=1;i<=nf;i++) 
{ 
for(j=1;j<=nb;j++) 
{ 
if(bf[j]!=1) 
{ 
temp=b[j]-f[i]; 
if(temp>=0) 
{ 
36 
ff[i]=j; 
lowest=temp; 
} 
} 
} 
frag[i]=lowest; 
bf[ff[i]]=1; 
lowest=10000; 
} 
printf("\nFile No \t File Size \t Block No \t Block Size \t fragment"); 
for(i=1;i<=nf&&ff[i]!=0;i++) 
printf("\n %d \t %d \t %d \t %d \t %d",i,f[i],ff[i],b[ff[i]],frag[i]); 
}