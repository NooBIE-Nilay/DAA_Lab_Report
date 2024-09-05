#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

void displayPersons_123(struct person *people_123, int n_123)
{
    printf("Id\tName\t\t\tAge\tHeight\tWeight\n");
    for (int i = 0; i < n_123; i++)
    {
        printf("%d\t%s\t\t%d\t%d\t%d\n", people_123[i].id, people_123[i].name, people_123[i].age, people_123[i].height, people_123[i].weight);
    }
}

void readData_123(struct person **people_123, int *n_123)
{
    FILE *file_123 = fopen("inputs/8123_4_1_in.dat", "r");
    if (!file_123)
    {
        printf("Error opening file.\n");
        return;
    }
    *n_123 = 6;
    *people_123 = (struct person *)malloc(*n_123 * sizeof(struct person));
    for (int i = 0; i < *n_123; i++)
    {
        (*people_123)[i].name = (char *)malloc(50 * sizeof(char));
        fscanf(file_123, "%d %s %d %d %d", &(*people_123)[i].id, (*people_123)[i].name, &(*people_123)[i].age, &(*people_123)[i].height, &(*people_123)[i].weight);
    }
    fclose(file_123);
}

void swap_123(struct person *a_123, struct person *b_123)
{
    struct person temp_123 = *a_123;
    *a_123 = *b_123;
    *b_123 = temp_123;
}

void heapifyMin_123(struct person *heap_123, int n_123, int i_123)
{
    int smallest_123 = i_123;
    int left_123 = 2 * i_123 + 1;
    int right_123 = 2 * i_123 + 2;

    if (left_123 < n_123 && heap_123[left_123].age < heap_123[smallest_123].age)
        smallest_123 = left_123;

    if (right_123 < n_123 && heap_123[right_123].age < heap_123[smallest_123].age)
        smallest_123 = right_123;

    if (smallest_123 != i_123)
    {
        swap_123(&heap_123[i_123], &heap_123[smallest_123]);
        heapifyMin_123(heap_123, n_123, smallest_123);
    }
}

void createMinHeap_123(struct person *heap_123, int n_123)
{
    for (int i = n_123 / 2 - 1; i >= 0; i--)
        heapifyMin_123(heap_123, n_123, i);
}

void heapifyMax_123(struct person *heap_123, int n_123, int i_123)
{
    int largest_123 = i_123;
    int left_123 = 2 * i_123 + 1;
    int right_123 = 2 * i_123 + 2;

    if (left_123 < n_123 && heap_123[left_123].weight > heap_123[largest_123].weight)
        largest_123 = left_123;

    if (right_123 < n_123 && heap_123[right_123].weight > heap_123[largest_123].weight)
        largest_123 = right_123;

    if (largest_123 != i_123)
    {
        swap_123(&heap_123[i_123], &heap_123[largest_123]);
        heapifyMax_123(heap_123, n_123, largest_123);
    }
}

void createMaxHeap_123(struct person *heap_123, int n_123)
{
    for (int i = n_123 / 2 - 1; i >= 0; i--)
        heapifyMax_123(heap_123, n_123, i);
}

void displayWeightOfYoungest_123(struct person *heap_123, int n_123)
{
    if (n_123 == 0)
    {
        printf("Heap is empty.\n");
        return;
    }
    printf("Name & Weight of youngest student: %s %.2f kg\n", heap_123[0].name, heap_123[0].weight * 0.453592);
}

void insertPerson_123(struct person **heap_123, int *n_123, struct person newPerson_123)
{
    *heap_123 = (struct person *)realloc(*heap_123, (*n_123 + 1) * sizeof(struct person));
    int i = (*n_123)++;
    (*heap_123)[i] = newPerson_123;

    while (i != 0 && (*heap_123)[(i - 1) / 2].age > (*heap_123)[i].age)
    {
        swap_123(&(*heap_123)[i], &(*heap_123)[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteOldestPerson_123(struct person *heap_123, int *n_123)
{
    if (*n_123 == 0)
    {
        printf("Heap is empty.\n");
        return;
    }
    heap_123[0] = heap_123[--(*n_123)];
    heapifyMin_123(heap_123, *n_123, 0);
}

int main()
{
    struct person *people_123 = NULL;
    int n_123 = 0;
    int option_123;

    while (option_123 != 7)
    {
        printf("MAIN MENU (HEAP)\n");
        printf("0. Display Data\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter Option: ");
        scanf("%d", &option_123);

        switch (option_123)
        {
        case 0:
            displayPersons_123(people_123, n_123);
            break;
        case 1:
            readData_123(&people_123, &n_123);
            displayPersons_123(people_123, n_123);
            break;
        case 2:
            createMinHeap_123(people_123, n_123);
            displayPersons_123(people_123, n_123);
            break;
        case 3:
            createMaxHeap_123(people_123, n_123);
            displayPersons_123(people_123, n_123);
            break;
        case 4:
            displayPersons_123(people_123, n_123);
            createMinHeap_123(people_123, n_123);
            displayWeightOfYoungest_123(people_123, n_123);
            break;
        case 5:
        {
            struct person newPerson_123;
            newPerson_123.name = (char *)malloc(50 * sizeof(char));
            printf("Enter id, name, age, height, weight: ");
            scanf("%d %s %d %d %d", &newPerson_123.id, newPerson_123.name, &newPerson_123.age, &newPerson_123.height, &newPerson_123.weight);
            insertPerson_123(&people_123, &n_123, newPerson_123);
            displayPersons_123(people_123, n_123);
            break;
        }
        case 6:
            createMinHeap_123(people_123, n_123);
            deleteOldestPerson_123(people_123, &n_123);
            printf("People List After Deletion\n");
            displayPersons_123(people_123, n_123);
            break;
        case 7:
            for (int i = 0; i < n_123; i++)
            {
                free(people_123[i].name);
            }
            free(people_123);
            return 0;
        default:
            printf("Invalid Option.\n");
        }
    }
}
