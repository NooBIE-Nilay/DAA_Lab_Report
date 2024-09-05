#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int item_id;
    int item_profit;
    int item_weight;
    float profit_weight_ratio;
} Item_123;

void displayItems_123(Item_123 items_123[], int n_123)
{
    printf("Item No\t\tprofit\t\tWeight\t\tProfit/Weight Ratio\n");
    for (int i = 0; i < n_123; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%f\n", items_123[i].item_id, items_123[i].item_weight, items_123[i].item_profit, items_123[i].profit_weight_ratio);
    }
}
void calculateProfitWeightRatio_123(Item_123 items_123[], int n_123)
{
    for (int i = 0; i < n_123; i++)
    {
        items_123[i].profit_weight_ratio = items_123[i].item_profit / items_123[i].item_weight;
    }
}

void swap_123(Item_123 *a_123, Item_123 *b_123)
{
    Item_123 temp_123 = *a_123;
    *a_123 = *b_123;
    *b_123 = temp_123;
}

void heapify_123(Item_123 items_123[], int n_123, int i_123)
{
    int largest_123 = i_123;
    int left_123 = 2 * i_123 + 1;
    int right_123 = 2 * i_123 + 2;

    if (left_123 < n_123 && items_123[left_123].profit_weight_ratio > items_123[largest_123].profit_weight_ratio)
        largest_123 = left_123;

    if (right_123 < n_123 && items_123[right_123].profit_weight_ratio > items_123[largest_123].profit_weight_ratio)
        largest_123 = right_123;

    if (largest_123 != i_123)
    {
        swap_123(&items_123[i_123], &items_123[largest_123]);
        heapify_123(items_123, n_123, largest_123);
    }
}

void heapSort_123(Item_123 items_123[], int n_123)
{
    for (int i = n_123 / 2 - 1; i >= 0; i--)
        heapify_123(items_123, n_123, i);

    for (int i = n_123 - 1; i >= 0; i--)
    {
        swap_123(&items_123[0], &items_123[i]);
        heapify_123(items_123, i, 0);
    }
}

float fractionalKnapsack_123(Item_123 items_123[], int n_123, int capacity_123)
{
    float total_profit_123 = 0.0;
    printf("Item No\t\tProfit\t\t\tWeight\t\tProfit/Weight Ratio\t\tAmount to be taken\n");
    for (int i = n_123 - 1; i >= 0; i--)
    {
        if (items_123[i].item_weight <= capacity_123)
        {
            capacity_123 -= items_123[i].item_weight;
            total_profit_123 += items_123[i].item_profit;
            printf("%d\t\t%.6f\t\t%.6f\t\t%.6f\t\t%.6f\n", items_123[i].item_id, (float)items_123[i].item_profit, (float)items_123[i].item_weight, items_123[i].profit_weight_ratio, 1.0);
        }
        else
        {
            float fraction_123 = (float)capacity_123 / items_123[i].item_weight;
            capacity_123 -= items_123[i].item_weight;
            total_profit_123 += items_123[i].item_profit * fraction_123;
            printf("%d\t\t%.6f\t\t%.6f\t\t%.6f\t\t%.6f\n", items_123[i].item_id, (float)items_123[i].item_profit, (float)items_123[i].item_weight, items_123[i].profit_weight_ratio, fraction_123);
        }
        if (capacity_123 < 0)
        {
            capacity_123 = 0;
        }
    }
    return total_profit_123;
}
int main()
{
    int n_123, capacity_123;

    printf("Enter the number of items: ");
    scanf("%d", &n_123);

    Item_123 items_123[n_123];

    for (int i = 0; i < n_123; i++)
    {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%d %d", &items_123[i].item_profit, &items_123[i].item_weight);
        items_123[i].item_id = i + 1;
    }
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity_123);

    calculateProfitWeightRatio_123(items_123, n_123);
    heapSort_123(items_123, n_123);
    printf("Items After Sorting Based on Profit/Weight Ratio: \n");
    displayItems_123(items_123, n_123);
    float max_profit = fractionalKnapsack_123(items_123, n_123, capacity_123);

    printf("Maximum profit: %.6f\n", max_profit);

    return 0;
}