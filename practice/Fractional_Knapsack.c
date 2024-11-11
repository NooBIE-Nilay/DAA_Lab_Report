#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int item_id;
    int item_profit;
    int item_weight;
    float profit_weight_ratio;
} Item;

void swap(Item *a, Item *b)
{
    Item temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Item items[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && items[left].profit_weight_ratio > items[largest].profit_weight_ratio)
        largest = left;

    if (right < n && items[right].profit_weight_ratio > items[largest].profit_weight_ratio)
        largest = right;

    if (largest != i)
    {
        swap(&items[i], &items[largest]);
        heapify(items, n, largest);
    }
}

void heapSort(Item items[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(items, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&items[0], &items[i]);
        heapify(items, i, 0);
    }
}

float fractionalKnapsack(Item items[], int n, int capacity)
{
    float total_profit = 0.0;
    printf("Item No\t\tProfit\t\t\tWeight\t\tProfit/Weight Ratio\t\tAmount to be taken\n");
    for (int i = n - 1; i >= 0; i--)
    {
        if (items[i].item_weight <= capacity)
        {
            capacity -= items[i].item_weight;
            total_profit += items[i].item_profit;
            printf("%d\t\t%.6f\t\t%.6f\t\t%.6f\t\t%.6f\n", items[i].item_id, (float)items[i].item_profit, (float)items[i].item_weight, items[i].profit_weight_ratio, 1.0);
        }
        else
        {
            float fraction = (float)capacity / items[i].item_weight;
            capacity -= items[i].item_weight;
            total_profit += items[i].item_profit * fraction;
            printf("%d\t\t%.6f\t\t%.6f\t\t%.6f\t\t%.6f\n", items[i].item_id, (float)items[i].item_profit, (float)items[i].item_weight, items[i].profit_weight_ratio, fraction);
        }
        if (capacity < 0)
        {
            capacity = 0;
        }
    }
    return total_profit;
}
int main()
{
    int n, K;
    printf("Enter No Of Items:");
    scanf("%d", &n);
    Item items[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%d %d", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i + 1;
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &K);

    heapSort(items, n);

    float max_profit = fractionalKnapsack(items, n, K);
    printf("Maximum profit: %.6f\n", max_profit);
    return 0;
}