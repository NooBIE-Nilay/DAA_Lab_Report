/*Given an undirected weighted connected graph G(V, E) and starring vertex „s‟.Maintain a Min- Priority Queue "Q" from the vertex set V and apply Prim‟s algorithm to
    -> Find the minimum spanning tree T(V, E'). Display the cost adjacency matrix of "T".
    -> Display total cost of the minimum spanning tree T.
Note #Nodes will be numbered consecutively from 1 to n(user input), and edges will have varying weight.The graph G can be read from an input file “inUnAdjMat.dat” that contains cost adjacency matrix.The expected output could be displayed as the cost adjacency matrix of the minimum spanning tree and total cost of the tree.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int vertex;
    int weight;
} Edge_123;

typedef struct
{
    Edge_123 *array;
    int size;
    int capacity;
} MinHeap_123;

MinHeap_123 *createMinHeap_123(int capacity)
{
    MinHeap_123 *minHeap_123 = (MinHeap_123 *)malloc(sizeof(MinHeap_123));
    minHeap_123->size = 0;
    minHeap_123->capacity = capacity;
    minHeap_123->array = (Edge_123 *)malloc(capacity * sizeof(Edge_123));
    return minHeap_123;
}

void swapEdge_123(Edge_123 *a_123, Edge_123 *b_123)
{
    Edge_123 t_123 = *a_123;
    *a_123 = *b_123;
    *b_123 = t_123;
}

void minHeapify_123(MinHeap_123 *minHeap_123, int idx_123)
{
    int smallest_123 = idx_123;
    int left_123 = 2 * idx_123 + 1;
    int right_123 = 2 * idx_123 + 2;

    if (left_123 < minHeap_123->size && minHeap_123->array[left_123].weight < minHeap_123->array[smallest_123].weight)
        smallest_123 = left_123;

    if (right_123 < minHeap_123->size && minHeap_123->array[right_123].weight < minHeap_123->array[smallest_123].weight)
        smallest_123 = right_123;

    if (smallest_123 != idx_123)
    {
        swapEdge_123(&minHeap_123->array[smallest_123], &minHeap_123->array[idx_123]);
        minHeapify_123(minHeap_123, smallest_123);
    }
}

Edge_123 extractMin_123(MinHeap_123 *minHeap_123)
{
    Edge_123 root_123 = minHeap_123->array[0];
    minHeap_123->array[0] = minHeap_123->array[minHeap_123->size - 1];
    --minHeap_123->size;
    minHeapify_123(minHeap_123, 0);
    return root_123;
}

void insertMinHeap_123(MinHeap_123 *minHeap_123, Edge_123 edge_123)
{
    ++minHeap_123->size;
    int i = minHeap_123->size - 1;
    while (i && edge_123.weight < minHeap_123->array[(i - 1) / 2].weight)
    {
        minHeap_123->array[i] = minHeap_123->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap_123->array[i] = edge_123;
}

void primMST_123(int **graph_123, int n_123, int start_123, FILE *file_123)
{
    int parent_123[n_123];
    int key_123[n_123];
    int inMST_123[n_123];
    MinHeap_123 *minHeap_123 = createMinHeap_123(n_123);

    for (int v = 0; v < n_123; ++v)
    {
        key_123[v] = INT32_MAX;
        inMST_123[v] = 0;
        minHeap_123->array[v].vertex = v;
        minHeap_123->array[v].weight = key_123[v];
    }

    minHeap_123->array[start_123].vertex = start_123;
    minHeap_123->array[start_123].weight = key_123[start_123] = 0;
    minHeap_123->size = n_123;

    while (minHeap_123->size)
    {
        Edge_123 minEdge_123 = extractMin_123(minHeap_123);
        int u = minEdge_123.vertex;
        inMST_123[u] = 1;

        for (int v = 0; v < n_123; ++v)
        {
            if (graph_123[u][v] && inMST_123[v] == 0 && graph_123[u][v] < key_123[v])
            {
                key_123[v] = graph_123[u][v];
                parent_123[v] = u;
                insertMinHeap_123(minHeap_123, (Edge_123){v, key_123[v]});
            }
        }
    }

    int totalCost_123 = 0;
    int **mst_123 = (int **)malloc(n_123 * sizeof(int *));
    for (int i = 0; i < n_123; i++)
    {
        mst_123[i] = (int *)malloc(n_123 * sizeof(int));
        for (int j = 0; j < n_123; j++)
        {
            mst_123[i][j] = 0;
        }
    }

    for (int i = 1; i < n_123; ++i)
    {
        mst_123[parent_123[i]][i] = graph_123[parent_123[i]][i];
        mst_123[i][parent_123[i]] = graph_123[parent_123[i]][i];
        totalCost_123 += graph_123[parent_123[i]][i];
    }

    printf("Cost adjacency matrix of the minimum spanning tree:\n");
    for (int i = 0; i < n_123; ++i)
    {
        for (int j = 0; j < n_123; ++j)
        {
            printf("%d ", mst_123[i][j]);
            fprintf(file_123, "%d ", mst_123[i][j]);
        }
        printf("\n");
        fprintf(file_123, "\n");
    }
    printf("Total cost of the minimum spanning tree: %d\n", totalCost_123);
    fprintf(file_123, "Total cost of the minimum spanning tree: %d\n", totalCost_123);
    fclose(file_123);

    for (int i = 0; i < n_123; i++)
    {
        free(mst_123[i]);
    }
    free(mst_123);
    free(minHeap_123->array);
    free(minHeap_123);
}

int main()
{
    FILE *file_123 = fopen("inputs/8123_6_1_inUnAdjMat.dat", "r");
    if (!file_123)
    {
        printf("Unable to open file_123.\n");
        return 1;
    }
    int n_123;
    printf("Enter the Number Of Vertices: ");
    scanf("%d", &n_123);

    int **graph_123 = (int **)malloc(n_123 * sizeof(int *));
    for (int i = 0; i < n_123; i++)
    {
        graph_123[i] = (int *)malloc(n_123 * sizeof(int));
        for (int j = 0; j < n_123; j++)
        {
            fscanf(file_123, "%d", &graph_123[i][j]);
            if (graph_123[i][j] == 0)
                graph_123[i][j] = INT32_MAX;
        }
    }

    fclose(file_123);
    file_123 = fopen("outputs/8123_6_1_outUnAdjMat.dat", "w");
    int start_123;
    printf("Enter the starting vertex: ");
    scanf("%d", &start_123);
    start_123--;
    primMST_123(graph_123, n_123, start_123, file_123);
    for (int i = 0; i < n_123; i++)
    {
        free(graph_123[i]);
    }
    free(graph_123);
    return 0;
}