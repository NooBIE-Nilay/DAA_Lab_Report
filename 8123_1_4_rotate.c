/*
1.4 Aim of the program: Write a function to ROTATE_RIGHT(p1, p2 ) right an array for first p2  elements by 1 position using EXCHANGE(p, q) function that swaps/exchanges the numbers p &  q. Parameter p1 be the starting address of the array and p2 be the number of elements to be  rotated.
        Input : Enter an array A of size N(9) : 11 22 33 44 55 66 77 88 99 Call the function ROTATE_RIGHT(A, 5)
        Output : Before ROTATE : 11 22 33 44 55 66 77 88 99 After ROTATE : 55 11 22 33 44 66 77 88 99
*/
#include <stdio.h>
void EXCHANGE_123(int *p_123, int *q_123)
{
        int temp_123 = *p_123;
        *p_123 = *q_123;
        *q_123 = temp_123;
}
void ROTATE_RIGHT_123(int *p1_123, int p2_123)
{
        int last_123 = *(p1_123 + p2_123 - 1);
        for (int i = p2_123 - 1; i > 0; i--)
                EXCHANGE_123(p1_123 + i, p1_123 + i - 1);
        *p1_123 = last_123;
}
int main()
{
        int N_123, R_123;
        printf("Enter Size Of Array: ");
        scanf("%d", &N_123);
        int A_123[N_123];
        printf("Enter Array Elements: ");
        for (int i = 0; i < N_123; i++)
                scanf("%d", &A_123[i]);
        printf("Enter Number Of Elements To Be Rotated: ");
        scanf("%d", &R_123);
        printf("Before ROTATE: ");
        for (int i = 0; i < N_123; i++)
                printf("%d ", A_123[i]);
        printf("\n");
        ROTATE_RIGHT_123(A_123, R_123);
        printf("After ROTATE: ");
        for (int i = 0; i < N_123; i++)
                printf("%d ", A_123[i]);
        printf("\n");
        return 0;
}
