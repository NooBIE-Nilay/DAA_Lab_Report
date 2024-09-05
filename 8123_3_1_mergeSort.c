#include <stdio.h>
#include <time.h>
int countComparisons = 0;
// time_t t1, t2;
void merge(int *arr_123, int low_123, int mid_123, int rear_123)
{
  int i, j, k;
  int n1 = mid_123 - low_123 + 1;
  int n2 = rear_123 - mid_123;
  int Left_123[n1], Right_123[n2];
  for (i = 0; i < n1; i++)
    Left_123[i] = arr_123[low_123 + i];
  for (j = 0; j < n2; j++)
    Right_123[j] = arr_123[mid_123 + 1 + j];
  i = 0, j = 0;
  k = low_123;
  while (i < n1 && j < n2)
  {
    countComparisons++;
    if (Left_123[i] <= Right_123[j])
    {
      arr_123[k] = Left_123[i];
      i++;
    }
    else
    {
      arr_123[k] = Right_123[j];
      j++;
    }
    k++;
  }
  while (i < n1)
  {
    arr_123[k] = Left_123[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    arr_123[k] = Right_123[j];
    j++;
    k++;
  }
}

void mergeSort(int *arr_123, int low_123, int high_123)
{
  if (low_123 < high_123)
  {

    int mid_123 = (low_123 + high_123) / 2;
    mergeSort(arr_123, low_123, mid_123);
    mergeSort(arr_123, mid_123 + 1, high_123);
    merge(arr_123, low_123, mid_123, high_123);
  }
}
int main()
{
  FILE *fptr_123;
  int input_123, n_123;
  printf("Merge Sort (Menu Driven)\n");
  printf("1 to sort Ascending Data\n2 to sort Descending Data\n3 to sort Random Data\n");
  scanf("%d", &input_123);
  switch (input_123)
  {
  case 1:
    fptr_123 = fopen("inputs/8123_3_1_in_asc.dat", "r");
    break;
  case 2:
    fptr_123 = fopen("inputs/8123_3_1_in_desc.dat", "r");
    break;
  case 3:
    fptr_123 = fopen("inputs/8123_3_1_in_rand.dat", "r");
    break;
  default:
    printf("Invalid Input\n");
    return 0;
    break;
  }
  if (fptr_123 == NULL)
  {
    printf("Invalid File Name\n");
    return 0;
  }
  fscanf(fptr_123, "%d ", &n_123);
  int arr_123[n_123];
  for (int i = 0; i < n_123; i++)
  {
    fscanf(fptr_123, "%d", &arr_123[i]);
  }
  fclose(fptr_123);
  fptr_123 = fopen("outputs/8123_3_1_out.dat", "w");
  // t1 = time(NULL);
  mergeSort(arr_123, 0, n_123);
  // t2 = time(NULL);
  for (int i = 0; i < n_123; i++)
    fprintf(fptr_123, "%d \n", arr_123[i]);
  printf("Comparisons: %d \n", countComparisons);
  printf("File Sorted & Saved To File\n");
  fclose(fptr_123);
}
