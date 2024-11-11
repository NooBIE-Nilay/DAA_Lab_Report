/*1.3 Aim of the program: Write a program to read „n‟ integers from a disc file that must contain some duplicate values and store them into an array. Perform the following operations on the array.
a) Find out the total number of duplicate elements.
b) Find out the most repeating element in the array.
Input: Enter how many numbers you want to read from file: 15

Output: The content of the array: 10 40 35 47 68 22 40 10 98 10 50 35 68 40 10
Total number of duplicate values = 4
The most repeating element in the array = 10
*/

#include <stdio.h>
int main()
{
    FILE *fp_123, *fpo_123;
    fp_123 = fopen("inputs/8123_1_3_in.dat", "r");
    fpo_123 = fopen("outputs/8123_1_3_out.dat", "w");
    int n_123;
    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n_123);
    int a_123[n_123];
    int num_123, count_123 = 0, maxCount_123 = -1;
    fprintf(fpo_123, "The content of the array: ");
    for (int i = 0; i < n_123; i++)
    {
        fscanf(fp_123, "%d", &a_123[i]);
        fprintf(fpo_123, "%d ", a_123[i]);
    }
    fclose(fp_123);
    for (int i = 0; i < n_123; i++)
    {
        count_123 = 0;
        for (int j = i + 1; j < n_123; j++)
        {
            if (a_123[i] == a_123[j])
                count_123++;
            if (count_123 > maxCount_123)
            {
                maxCount_123 = count_123;
                num_123 = a_123[i];
            }
        }
    }
    fprintf(fpo_123, "\nTotal number of duplicate values= %d\nThe most repeating element in the array = %d", maxCount_123, num_123);
    printf("Output has been written to 8123_1_3_out.dat\n");
    fclose(fpo_123);
}