#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int *arr,int low, int high){
  int pivot = arr[low];
  int i = low, j = high;
  while(i<j){
    do{
      i++;
    }while(arr[i]<=pivot && i<high-1);
    do{
      j--;
    }while(arr[j]>pivot && j>low+1);
  if (i<j)
    swap(&arr[i],&arr[j]);
  }
  swap(&arr[low],&arr[j]);
  return j;
}

void quickSort(int *arr, int l, int h){
  if (l<h){
    int partitionIndex = partition(arr,l,h);
    quickSort(arr,l,partitionIndex);
    quickSort(arr,partitionIndex+1,h);
  }
}

void display(int *arr, int l, int h){
  for (int i=l;i<h;i++){
    printf("%d ",arr[i]);
  }
    printf("\n");
}
int main(){
  int n =10;
  int arr[n];
  for (int i=0;i<10;i++)
  {
    arr[i]=rand()%10;
  }
  printf("Before Sorting: ");
  display(arr,0,n);
  quickSort(arr,0,n);
  printf("After Sorting: ");
  display(arr,0,n);
}
