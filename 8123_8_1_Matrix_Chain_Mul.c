/*
8.1 Aim of the program: Write a C program to implement the matrix chain multiplication problem using  M-table  &  S-table  to  find  optimal  parenthesization  of  a  matrix-chain  product.  Print  the number of scalar multiplications required for the given input.

Note#  Dimensions  of  the  matrices  can  be  inputted  as  row  and  column  values.  Validate  the dimension compatibility.

Input:
Enter number of matrices: 4
Enter row and col size of A1: 30  35
Enter row and col size of A2: 35  15
Enter row and col size of A3: 15  5
Enter row and col size of A4: 5  10
Output:
M Table:
0     15750  7875    9375
0     0       2625    4375
0     0       0       750
0     0       0       0

S Table:
0     1       1       3
0     0       2       3
0     0       0       3
0     0       0       0

Optimal parenthesization: ( ( A1   (A2   A3))   A4)
The optimal ordering of the given matrices requires 9375 scalar multiplications
*/
#include <stdio.h>
#include <limits.h>

#define MAX_MATRICES 100

int m_123[MAX_MATRICES][MAX_MATRICES];
int s_123[MAX_MATRICES][MAX_MATRICES];

void matrix_chain_multiplication_123(int p_123[], int n_123)
{
    // Initialize the m_123 and s_123 tables
    for (int i = 1; i < n_123; i++)
    {
        m_123[i][i] = 0;
    }

    for (int l_123 = 2; l_123 < n_123; l_123++)
    {
        for (int i_123 = 1; i_123 < n_123 - l_123 + 1; i_123++)
        {
            int j = i_123 + l_123 - 1;
            m_123[i_123][j] = INT_MAX;
            for (int k_123 = i_123; k_123 < j; k_123++)
            {
                int q_123 = m_123[i_123][k_123] + m_123[k_123 + 1][j] + p_123[i_123 - 1] * p_123[k_123] * p_123[j];
                if (q_123 < m_123[i_123][j])
                {
                    m_123[i_123][j] = q_123;
                    s_123[i_123][j] = k_123;
                }
            }
        }
    }
}

void print_optimal_parenthesization_123(int s_123[][MAX_MATRICES], int i_123, int j)
{
    if (i_123 == j)
    {
        printf("A%d", i_123);
    }
    else
    {
        printf("(");
        print_optimal_parenthesization_123(s_123, i_123, s_123[i_123][j]);
        printf(" ");
        print_optimal_parenthesization_123(s_123, s_123[i_123][j] + 1, j);
        printf(")");
    }
}

int main()
{
    int p_123[MAX_MATRICES + 1];
    int n_123;

    printf("Enter number of matrices: ");
    scanf("%d", &n_123);

    for (int i_123 = 0; i_123 < n_123; i_123++)
    {
        int row_123, col_123;
        printf("Enter row and col size of A%d: ", i_123 + 1);
        scanf("%d %d", &row_123, &col_123);
        p_123[i_123] = row_123;
        p_123[n_123] = col_123;
    }

    matrix_chain_multiplication_123(p_123, n_123 + 1);

    printf("M Table:\n");
    for (int i_123 = 1; i_123 < n_123 + 1; i_123++)
    {
        for (int j = 1; j < n_123 + 1; j++)
        {
            printf("%d\t", m_123[i_123][j]);
        }
        printf("\n");
    }

    printf("\nS Table:\n");
    for (int i = 1; i < n_123 + 1; i++)
    {
        for (int j = 1; j < n_123 + 1; j++)
        {
            printf("%d\t", s_123[i][j]);
        }
        printf("\n");
    }

    printf("\nOptimal parenthesization: ");
    print_optimal_parenthesization_123(s_123, 1, n_123);
    printf("\nThe optimal ordering of the given matrices requires %d scalar multiplications\n", m_123[1][n_123]);

    return 0;
}