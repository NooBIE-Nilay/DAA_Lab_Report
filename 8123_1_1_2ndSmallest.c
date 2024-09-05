// 1.1 Aim of the program: Write a program to find out the second smallest and second largest element stored in an array of n integers.
// Input : Size of the array is "n" and read "n" number of elements from a disc file.
// Output : Second smallest, Second largest

#include <stdio.h>
int main()
{
    FILE *fptr_123;
    fptr_123 = fopen("inputs/8123_1_1_in.dat", "r");
    int n_123;
    fscanf(fptr_123, "%d", &n_123);
    int a_123[n_123];
    for (int i = 0; i < n_123; i++)
    {
        fscanf(fptr_123, "%d", &a_123[i]);
    }
    fclose(fptr_123);
    int lar_123 = a_123[0], sml_123 = a_123[0];
    int secLar_123 = __INT_MAX__ * -1, secSml_123 = __INT_MAX__;
    for (int i = 1; i < n_123; i++)
    {
        if (a_123[i] > lar_123)
        {
            secLar_123 = lar_123;
            lar_123 = a_123[i];
        }
        else if (a_123[i] > secLar_123 && a_123[i] != lar_123)
        {
            secLar_123 = a_123[i];
        }
        if (a_123[i] < sml_123)
        {
            secSml_123 = sml_123;
            sml_123 = a_123[i];
        }
        else if (a_123[i] < secSml_123 && a_123[i] != sml_123)
        {
            secSml_123 = a_123[i];
        }
    }
    fptr_123 = fopen("outputs/8123_1_1_out.dat", "w");
    fprintf(fptr_123, "Second Smallest %d\nSecond Largest %d", secSml_123, secLar_123);
    printf("Output Saved to File\n");
    fclose(fptr_123);
    return 0;
}