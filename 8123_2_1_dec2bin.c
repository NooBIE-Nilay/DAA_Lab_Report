#include <stdio.h>
#include <stdlib.h>
FILE *fp_in_123, *fp_out_123;
void decimalToBinary_123(int n_123)
{
    if (n_123 > 0)
    {
        decimalToBinary_123(n_123 / 2);
        fprintf(fp_out_123, "%d", n_123 % 2);
    }
}
int main(int argc, char *argv[])
{
    fp_in_123 = fopen("inputs/8123_2_1_in.dat", "r");
    fp_out_123 = fopen("outputs/8123_2_1_out.dat", "w");
    int n_123 = atoi(argv[1]);
    for (int i = 0; i < n_123; i++)
    {
        int num_123;
        if (fscanf(fp_in_123, "%d", &num_123))
            decimalToBinary_123(num_123);
        fprintf(fp_out_123, "\n");
    }
    printf("Output has been written to 8123_2_1_out.dat\n");
    fclose(fp_in_123);
    fclose(fp_out_123);
    return 0;
}
