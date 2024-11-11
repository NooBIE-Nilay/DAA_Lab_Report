#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS_123 1000

int read_panel_files_123(const char *filename_123, int arr_123[])
{
    FILE *file_123 = fopen(filename_123, "r");
    if (!file_123)
    {
        printf("Error opening file: %s\n", filename_123);
        return -1;
    }
    int count_123 = 0;
    while (fscanf(file_123, "%d", &arr_123[count_123]) != EOF && count_123 < MAX_STUDENTS_123)
    {
        count_123++;
    }
    fclose(file_123);
    return count_123;
}

int compare_123(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void find_selected_students_123(int *p1, int n1, int *p2, int n2, int *p3, int n3, int *p4, int n4)
{
    int i = 0, j = 0, k = 0, l = 0;
    int selected_count_123 = 0;

    while (i < n1 || j < n2 || k < n3 || l < n4)
    {
        int count_123 = 0;
        int min_val = INT32_MAX;

        if (i < n1 && p1[i] < min_val)
            min_val = p1[i];
        if (j < n2 && p2[j] < min_val)
            min_val = p2[j];
        if (k < n3 && p3[k] < min_val)
            min_val = p3[k];
        if (l < n4 && p4[l] < min_val)
            min_val = p4[l];

        if (i < n1 && p1[i] == min_val)
        {
            count_123++;
            i++;
        }
        if (j < n2 && p2[j] == min_val)
        {
            count_123++;
            j++;
        }
        if (k < n3 && p3[k] == min_val)
        {
            count_123++;
            k++;
        }
        if (l < n4 && p4[l] == min_val)
        {
            count_123++;
            l++;
        }

        if (count_123 >= 3)
        {
            selected_count_123++;
            printf("Selected student roll number: %d\n", min_val);
        }
    }
    printf("Total number of selected students: %d\n", selected_count_123);
}

int main()
{
    int p1[MAX_STUDENTS_123], p2[MAX_STUDENTS_123], p3[MAX_STUDENTS_123], p4[MAX_STUDENTS_123];
    int n1, n2, n3, n4;

    n1 = read_panel_files_123("panel1.dat", p1);
    n2 = read_panel_files_123("panel2.dat", p2);
    n3 = read_panel_files_123("panel3.dat", p3);
    n4 = read_panel_files_123("panel4.dat", p4);

    if (n1 == -1 || n2 == -1 || n3 == -1 || n4 == -1)
    {
        return 1;
    }
    qsort(p1, n1, sizeof(int), compare_123);
    qsort(p2, n2, sizeof(int), compare_123);
    qsort(p3, n3, sizeof(int), compare_123);
    qsort(p4, n4, sizeof(int), compare_123);
    find_selected_students_123(p1, n1, p2, n2, p3, n3, p4, n4);
    return 0;
}