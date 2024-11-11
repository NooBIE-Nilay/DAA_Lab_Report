// 1.2 Aim of the program: Given an array arr[] of size N, find the prefix sum of the array. A prefix sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is arr[0] + arr[1] + arr[2]...arr[i].
#include <stdio.h>
int main()
{
    FILE *fp_123;
    fp_123 = fopen("inputs/8123_1_2_in.dat", "r");
    int n_123, s_123 = 0;
    fscanf(fp_123, "%d", &n_123);
    int a_123[n_123];
    for (int i = 0; i < n_123; i++)
    {
        fscanf(fp_123, "%d", &a_123[i]);
    }
    fclose(fp_123);
    fp_123 = fopen("outputs/8123_1_2_out.dat", "w");
    for (int i = 0; i < n_123; i++)
    {
        s_123 += a_123[i];
        a_123[i] = s_123;
        fprintf(fp_123, "%d ", s_123);
    }
    printf("Output has been written to 8123_1_2_out.dat\n");
    fclose(fp_123);
    return 0;
}