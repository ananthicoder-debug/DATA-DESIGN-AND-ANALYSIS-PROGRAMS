#include<iostream>
using namespace std;
int main(){
   int n,temp;
   cout<<"Enter number of elements:";
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++){
      cin>>a[i];
   }
   for(int i=0;i<n-1;i++){
      for(int j=0;j<n-i;j++){
         if(a[j]>a[j+1]){
               temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
         }
      }
   }
   cout<<"Sorted array using bubble sort:\n";
   for (int i=0;i<n;i++){
      cout<<a[i]<<" ";
   }
   cout<<"\n";
   return 0;
}
