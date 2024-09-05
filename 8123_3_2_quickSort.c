#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int comaprisons_123 = 0;
int partition_123(int arr_123[], int low_123, int high_123)
{
    int pivot_123 = arr_123[high_123];

    int i = (low_123 - 1);

    for (int j = low_123; j <= high_123 - 1; j++)
    {
        if (arr_123[j] < pivot_123)
        {
            comaprisons_123++;
            i++;
            int temp = arr_123[i];
            arr_123[i] = arr_123[j];
            arr_123[j] = temp;
        }
    }
    int temp = arr_123[i + 1];
    arr_123[i + 1] = arr_123[high_123];
    arr_123[high_123] = temp;
    return (i + 1);
}

void quickSort_123(int arr_123[], int low_123, int high_123)
{
    if (low_123 < high_123)
    {
        int piv_123 = partition_123(arr_123, low_123, high_123);
        quickSort_123(arr_123, low_123, piv_123 - 1);
        quickSort_123(arr_123, piv_123 + 1, high_123);
    }
}

int main()
{
    int n_123;

    FILE *ip = fopen("inputs/8123_3_2_in_asc.dat", "r");
    FILE *op = fopen("outputs/8123_3_2_out_asc.dat", "w");

    printf("Enter how many numbers do you want to read from the file: \n");
    scanf("%d", &n_123);

    int arr_123[n_123];

    printf("Before sorting: \n");
    for (int i = 0; i < n_123; i++)
    {
        fscanf(ip, "%d", &arr_123[i]);
        printf("%d \n", arr_123[i]);
    }

    quickSort_123(arr_123, 0, n_123 - 1);

    printf("After Sorting: \n");
    for (int i = 0; i < n_123; i++)
    {
        fprintf(op, "%d \n", arr_123[i]);
        printf("%d \n", arr_123[i]);
    }
    printf("Comparisons: %d \n", comaprisons_123);
    printf("Files are written successfully\n");
    return 0;
}