#include <stdio.h>
int gcd_123(int a_123, int b_123)
{
    if (a_123 == b_123)
        return a_123;
    else if (a_123 > b_123)
        return gcd_123(a_123 - b_123, b_123);
    else
        return gcd_123(a_123, b_123 - a_123);
}
int main()
{
    FILE *fp_123, *fpo_123;
    fp_123 = fopen("inputs/8123_2_2_in.dat", "r");
    fpo_123 = fopen("outputs/8123_2_2_out.dat", "w");
    int n_123;
    printf("Enter the number of pairs you want to check: ");
    scanf("%d", &n_123);
    for (int i = 0; i < n_123; i++)
    {
        int a_123, b_123;
        fscanf(fp_123, "%d %d", &a_123, &b_123);
        fprintf(fpo_123, "%d\n", gcd_123(a_123, b_123));
    }
    return 0;
}