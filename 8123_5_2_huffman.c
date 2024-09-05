#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char alphabet_123;
    int frequency_123;
} SYMBOL_123;

typedef struct Node_123
{
    SYMBOL_123 symbol;
    struct Node_123 *left, *right;
} Node_123;

typedef struct
{
    Node_123 **array;
    int size_123;
    int capacity_123;
} MinHeap_123;

Node_123 *createNode_123(char alphabet_123, int frequency_123)
{
    Node_123 *newNode_123 = (Node_123 *)malloc(sizeof(Node_123));
    newNode_123->symbol.alphabet_123 = alphabet_123;
    newNode_123->symbol.frequency_123 = frequency_123;
    newNode_123->left = newNode_123->right = NULL;
    return newNode_123;
}

MinHeap_123 *createMinHeap_123(int capacity_123)
{
    MinHeap_123 *minHeap_123 = (MinHeap_123 *)malloc(sizeof(MinHeap_123));
    minHeap_123->size_123 = 0;
    minHeap_123->capacity_123 = capacity_123;
    minHeap_123->array = (Node_123 **)malloc(minHeap_123->capacity_123 * sizeof(Node_123 *));
    return minHeap_123;
}

void swapNode_123(Node_123 **a_123, Node_123 **b_123)
{
    Node_123 *t_123 = *a_123;
    *a_123 = *b_123;
    *b_123 = t_123;
}

void minHeapify_123(MinHeap_123 *minHeap_123, int idx_123)
{
    int smallest_123 = idx_123;
    int left_123 = 2 * idx_123 + 1;
    int right_123 = 2 * idx_123 + 2;

    if (left_123 < minHeap_123->size_123 && minHeap_123->array[left_123]->symbol.frequency_123 < minHeap_123->array[smallest_123]->symbol.frequency_123)
        smallest_123 = left_123;

    if (right_123 < minHeap_123->size_123 && minHeap_123->array[right_123]->symbol.frequency_123 < minHeap_123->array[smallest_123]->symbol.frequency_123)
        smallest_123 = right_123;

    if (smallest_123 != idx_123)
    {
        swapNode_123(&minHeap_123->array[smallest_123], &minHeap_123->array[idx_123]);
        minHeapify_123(minHeap_123, smallest_123);
    }
}

Node_123 *extractMin_123(MinHeap_123 *minHeap_123)
{
    Node_123 *temp_123 = minHeap_123->array[0];
    minHeap_123->array[0] = minHeap_123->array[minHeap_123->size_123 - 1];
    --minHeap_123->size_123;
    minHeapify_123(minHeap_123, 0);
    return temp_123;
}

void insertMinHeap(MinHeap_123 *minHeap_123, Node_123 *node_123)
{
    ++minHeap_123->size_123;
    int i = minHeap_123->size_123 - 1;
    while (i && node_123->symbol.frequency_123 < minHeap_123->array[(i - 1) / 2]->symbol.frequency_123)
    {
        minHeap_123->array[i] = minHeap_123->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap_123->array[i] = node_123;
}

MinHeap_123 *buildMinHeap_123(SYMBOL_123 symbols_123[], int size_123)
{
    MinHeap_123 *minHeap_123 = createMinHeap_123(size_123);
    for (int i = 0; i < size_123; ++i)
        minHeap_123->array[i] = createNode_123(symbols_123[i].alphabet_123, symbols_123[i].frequency_123);
    minHeap_123->size_123 = size_123;
    for (int i = (minHeap_123->size_123 - 2) / 2; i >= 0; --i)
        minHeapify_123(minHeap_123, i);
    return minHeap_123;
}

Node_123 *buildHuffmanTree_123(SYMBOL_123 symbols_123[], int size_123)
{
    Node_123 *left_123, *right_123, *top_123;
    MinHeap_123 *minHeap_123 = buildMinHeap_123(symbols_123, size_123);
    while (minHeap_123->size_123 != 1)
    {
        left_123 = extractMin_123(minHeap_123);
        right_123 = extractMin_123(minHeap_123);
        top_123 = createNode_123('$', left_123->symbol.frequency_123 + right_123->symbol.frequency_123);
        top_123->left = left_123;
        top_123->right = right_123;
        insertMinHeap(minHeap_123, top_123);
    }
    return extractMin_123(minHeap_123);
}

void inOrderTraversal_123(Node_123 *root_123)
{
    if (root_123)
    {
        inOrderTraversal_123(root_123->left);
        if (root_123->symbol.alphabet_123 != '$')
            printf("%c ", root_123->symbol.alphabet_123);
        inOrderTraversal_123(root_123->right);
    }
}

int main()
{
    int n_123;
    printf("Enter the number of distinct alphabets: ");
    if (scanf("%d", &n_123) == 0)
    {
        printf("\nInvalid Input\nProgram Exiting");
        return 0;
    }

    SYMBOL_123 symbols_123[n_123];
    printf("Enter the alphabets: ");
    for (int i = 0; i < n_123; i++)
    {
        if (scanf(" %c", &symbols_123[i].alphabet_123) == 0)
        {
            printf("\nInvalid Input\nProgram Exiting");
            return 0;
        }
    }

    printf("Enter its frequencies: ");
    for (int i = 0; i < n_123; i++)
    {
        if (scanf("%d", &symbols_123[i].frequency_123) == 0)
        {
            printf("\nInvalid Input\nProgram Exiting");
            return 0;
        }
    }

    Node_123 *root_123 = buildHuffmanTree_123(symbols_123, n_123);

    printf("In-order traversal of the tree (Huffman): ");
    inOrderTraversal_123(root_123);
    printf("\n");

    return 0;
}