#include<stdio.h>
#include<string.h>
int main()
{
   char text[100],pattern[100];
   int i,j,n,m,found=0;
   printf("Enter the text:");
   scanf("%s",&text);
   printf("Enter the parameter:");
   scanf("%s",&pattern);
   n=strlen(text);
   m=strlen(pattern);
   for(i=0;i<n-m;i++)
   {
      j=0;
      while(j<m&&text[i+j]==pattern[j])
      {
         j++;
      }
      if(j==m)
      {
         printf("Pattern found at position %d\n",i);
         found=1;
      }
   }
   if(!found)
      printf("Pattern not found\n");
   return 0;
}
