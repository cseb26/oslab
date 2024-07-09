// sequential file allocation 
#include<stdio.h> 
#include<string.h> 
void main() 
{ 
int st[20],b[20],b1[20],ch,i,j,n,blocks[20][20],sz[20]; 
char F[20][20],S[20]; 
printf("\n Enter no. of Files ::"); 
scanf("%d",&n); 
for(i=0;i<n;i++) 
{ 
printf("\n Enter file %d name ::",i+1); 
scanf("%s",&F[i]); 
printf("\n Enter file%d size(in kb)::",i+1); 
scanf("%d",&sz[i]); 
printf("\n Enter Starting block of %d::",i+1); 
scanf("%d",&st[i]); 
printf("\n Enter blocksize of File%d(in bytes)::",i+1); 
scanf("%d",&b[i]); 
} 
for(i=0;i<n;i++) 
b1[i]=(sz[i]*1024)/b[i]; 
for(i=0;i<n;i++) 
{ 
for(j=0;j<b1[i];j++) 
blocks[i][j]=st[i]+j; 
} 
do 
{ 
54 
printf("\nEnter the Filename ::"); 
scanf("%s",S); 
for(i=0;i<n;i++) 
{ 
if(strcmp(S,F[i])==0) 
{ 
printf("\nFname\tStart\tNblocks\tBlocks\n"); 
printf("\n---------------------------------------------\n"); 
printf("\n%s\t%d\t%d\t",F[i],st[i],b1[i]); 
for(j=0;j<b1[i];j++) 
printf("%d->",blocks[i][j]); 
} 
} 
printf("\n---------------------------------------------\n"); 
printf("\nDo U want to continue ::(Y:n)"); 
scanf("%d",&ch); 
if(ch!=1) 
break; 
}while(1); 
}


// ==========================================================
    // indexed file allocation method
#include<stdio.h> 
#include<string.h> 
int n; 
void main() 
{ 
int b[20],b1[20],i,j,blocks[20][20],sz[20]; 
char F[20][20],S[20],ch; 
printf("\n Enter no. of Files ::"); 
scanf("%d",&n); 
for(i=0;i<n;i++) 
{ 
printf("\n Enter file %d name ::",i+1); 
scanf("%s",&F[i]); 
printf("\n Enter file%d size(in kb)::",i+1); 
scanf("%d",&sz[i]); 
printf("\n Enter blocksize of File%d(in bytes)::",i+1); 
scanf("%d",&b[i]); 
} 
for(i=0;i<n;i++) 
{ 
b1[i]=(sz[i]*1024)/b[i]; 
printf("\n\nEnter blocks for file%d",i+1); 
for(j=0;j<b1[i];j++) 
{ 
printf("\n Enter the %dblock ::",j+1); 
scanf("%d",&blocks[i][j]); 
} 
} 
do 
{ 
printf("\nEnter the Filename ::"); 
scanf("%s",&S); 
57 
for(i=0;i<n;i++) 
{ 
if(strcmp(F[i],S)==0) 
{ 
printf("\nFname\tFsize\tBsize\tNblocks\tBlocks\n"); 
printf("\n---------------------------------------------\n"); 
printf("\n%s\t%d\t%d\t%d\t",F[i],sz[i],b[i],b1[i]); 
for(j=0;j<b1[i];j++) 
printf("%d->",blocks[i][j]); 
} 
} 
printf("\n---------------------------------------------\n"); 
printf("\nDo U want to continue ::(Y:n)"); 
scanf("%d",&ch); 
}while(ch!=0); 
}



// =======================================================================
// linked file allocation method

#include<stdio.h> 
#include<string.h> 
int n; 
void main() 
{ 
int b[20],b1[20],i,j,blocks[20][20],sz[20]; 
char F[20][20],S[20],ch; 
int sb[20],eb[20],x; 
printf("\n Enter no. of Files ::"); 
scanf("%d",&n); 
for(i=0;i<n;i++) 
{ 
printf("\n Enter file %d name ::",i+1); 
scanf("%s",&F[i]); 
printf("\n Enter file%d size(in kb)::",i+1); 
scanf("%d",&sz[i]); 
printf("\n Enter blocksize of File%d(in bytes)::",i+1); 
scanf("%d",&b[i]); 
} 
for(i=0;i<n;i++) 
{ 
b1[i]=(sz[i]*1024)/b[i]; 
printf("\n Enter Starting block of file%d::",i+1); 
scanf("%d",&sb[i]); 
59 
printf("\n Enter Ending block of file%d::",i+1); 
scanf("%d",&eb[i]); 
printf("\nEnter blocks for file%d::\n",i+1); 
for(j=0;j<b1[i]-2;) 
{ 
printf("\n Enter the %dblock ::",j+1); 
scanf("%d",&x); 
if(x>sb[i]&&x<eb[i]) 
{ 
blocks[i][j]=x; 
j++; 
} 
else 
printf("\n Invalid block::"); 
} 
} 
do 
{ 
printf("\nEnter the Filename ::"); 
scanf("%s",&S); 
for(i=0;i<n;i++) 
{ 
if(strcmp(F[i],S)==0) 
{ 
printf("\nFname\tFsize\tBsize\tNblocks\tBlocks\n"); 
60 
printf("\n---------------------------------------------\n"); 
printf("\n%s\t%d\t%d\t%d\t",F[i],sz[i],b[i],b1[i]); 
printf("%d->",sb[i]); 
for(j=0;j<b1[i]-2;j++) 
printf("%d->",blocks[i][j]); 
printf("%d->",eb[i]); 
} 
} 
printf("\n---------------------------------------------\n"); 
printf("\nDo U want to continue (Y:n)::"); 
scanf("%d",&ch); 
}while(ch!=0);