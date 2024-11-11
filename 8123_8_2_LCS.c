#include <stdio.h>
#include <string.h>

int lcs_123(char *s1_123, char *s2_123)
{
    int m_123 = strlen(s1_123);
    int n_123 = strlen(s2_123);
    int dp_123[m_123 + 1][n_123 + 1];

    // Initialize the dp_123 table
    for (int i = 0; i <= m_123; i++)
    {
        dp_123[i][0] = 0;
    }
    for (int j = 0; j <= n_123; j++)
    {
        dp_123[0][j] = 0;
    }

    // Compute the LCS length
    for (int i_123 = 1; i_123 <= m_123; i_123++)
    {
        for (int j_123 = 1; j_123 <= n_123; j_123++)
        {
            if (s1_123[i_123 - 1] == s2_123[j_123 - 1])
            {
                dp_123[i_123][j_123] = dp_123[i_123 - 1][j_123 - 1] + 1;
            }
            else
            {
                dp_123[i_123][j_123] = (dp_123[i_123 - 1][j_123] > dp_123[i_123][j_123 - 1]) ? dp_123[i_123 - 1][j_123] : dp_123[i_123][j_123 - 1];
            }
        }
    }

    return dp_123[m_123][n_123];
}

int main()
{
    char s1_123[100], s2_123[100];

    printf("Enter the first string: ");
    scanf("%s", s1_123);

    printf("Enter the second string: ");
    scanf("%s", s2_123);

    int lcs_length_123 = lcs_123(s1_123, s2_123);

    printf("LCS: %.*s\n", lcs_length_123, s1_123);
    printf("LCS Length: %d\n", lcs_length_123);

    return 0;
}