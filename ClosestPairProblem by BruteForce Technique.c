#include<stdio.h>
#include<math.h>
int main(){
   int n,i,j;
   float x[20],y[20];
   float d,dist;
   int p1=0,p2=1;
   printf("Enter the number of points(n>=2):");
   scanf("%d",&n);
   for(i=0;i<n;i++){
      printf("Enter x %d and y %d:",i+1,i+1);
      scanf("%f%f",&x[i],&y[i]);
   }
   d=sqrt((x[0]-x[1])*(x[0]-x[1])+(y[0]-y[1])*(y[0]-y[1]));
   for(i=0;i<n-1;i++){
      for(j=i+1;j<n;j++){
         dist=sqrt((x[i]-x[j])*(x[i]-x[j]))+((x[i]-y[j])*(y[i]-y[j]));
         if(dist<d){
            d=dist;
            p1=i;
            p2=j;
         }
      }
   }
   printf("\nClosest pair points:\n");
   printf("p%d(%.2f,%.2f) and p%d(%.2f,%.2f)\n",p1+1,x[p1],y[p1],p2+1,x[p2],y[p2]);
   printf("Minimum distance=%.2f\n",d);
   return 0;
}
