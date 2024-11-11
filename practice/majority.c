#include <stdio.h>
int findMajority(int *a, int n){
       int me = a[0];      // Assume majority to be first
  int count = 1;             
  for(int i=1;i<n;i++){
    if (me == a[i])    // If Majority is ith element, we increment count
      count++;
    else if (count == 0)  // Else Check if count == 0, change majority to ith element
      {
        me = a[i];
        count = 1;
      }
    else             // Else decrement count
      count--;
  }
  count = 0;
  // Count Freq Of Majority Element
  for(int i=0;i<n;i++){
    if (a[i]==me)
      count++;
  }
  // If Count is majority, return me, else return -1
  if (count > n/2)
    return me;
  else
    return -1;
}
int main(){
  int arr[] = {1,1,1,2,2,2,2,2,2,1};
  int len = 10;
  printf("%d\n",findMajority(arr,len));
  int arr1[] = {1,1,2,1,2,1,2,1,2,1,2};
  printf("%d\n",findMajority(arr1,11));
}
