#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char inputFileName[65] =
        "/Users/n00bie/Learning/DAA_Lab_Report/inputs/8123_",
         buffer[15] = "", c;
    int n, input, inc, formatCode;
    char labNo[5], expNo[5];
    printf("Enter Lab & Exp Number: ");
    scanf("%s %s", labNo, expNo);
    strncat(buffer, labNo, strlen(labNo));
    // while (labNo != 0)
    // {
    // }
    strncat(buffer, "_", 1);
    strncat(buffer, expNo, strlen(expNo));
    // while (expNo != 0)
    // {
    //     c = (char)((expNo % 10) + '0');
    //     strncat(buffer, &c, 1);
    //     expNo /= 10;
    // }
    strncat(buffer, "_in.dat\0", 9);
    strncat(inputFileName, buffer, strlen(buffer));

    FILE *fp;
    fp = fopen(inputFileName, "w");
    if (fp == NULL)
    {
        printf("Error Creating File");
        return 0;
    }
    printf("Writing To File ");
    puts(inputFileName);
    printf("Enter 1 For Custom Input\nEnter 2 For N Random Numbers:\nEnter 3 For N Ascending Numbers\nEnter 4 For N Descending Numbers: ");
    scanf("%d", &input);
    printf("Enter N: ");
    scanf("%d", &n);
    printf("Do You Want to include N in the File? (1/0): ");
    scanf("%d", &inc);
    if (inc == 1)
    {
        fprintf(fp, "%ds\n", n);
    }
    int arr[n];
    int x = 0, y = n * 100;
    switch (input)
    {
    case 1:
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        break;
    case 2:
        printf("Enter Upper Limit\nEnter 0 to Set No Limit: ");
        scanf("%d", &input);
        for (int i = 0; i < n; i++)
        {
            if (input == 0)
                arr[i] = rand() % __INT_MAX__;
            else
                arr[i] = rand() % input + 1;
        }
        break;
    case 3:
        for (int i = 0; i < n; i++)
        {
            arr[i] = x;
            x += rand() % 100;
        }
        break;
    case 4:
        for (int i = 0; i < n; i++)
        {
            arr[i] = y;
            y -= rand() % 100;
        }
        break;
    default:
        return 0;
        break;
    }
    printf("Format 1: %%d \\n\nFormat 2: %%d %%d ... \nFormat 3: %%d %%d \\n\nEnter Format Code: ");
    scanf("%d", &formatCode);
    if (formatCode == 1)
    {
        for (int i = 0; i < n; i++)
        {
            fprintf(fp, "%d\n", arr[i]);
        }
    }
    else if (formatCode == 3)
    {
        for (int i = 0; i < n; i = i + 2)
        {
            fprintf(fp, "%d %d\n", arr[i], arr[i + 1]);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            fprintf(fp, "%d ", arr[i]);
        }
    }

    fclose(fp);
    return 0;
}