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
} Edge;

typedef struct
{
    Edge *array;
    int size;
    int capacity;
} MinHeap;

MinHeap *createMinHeap(int capacity)
{
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (Edge *)malloc(capacity * sizeof(Edge));
    return minHeap;
}

void swapEdge(Edge *a, Edge *b)
{
    Edge t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left].weight < minHeap->array[smallest].weight)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right].weight < minHeap->array[smallest].weight)
        smallest = right;

    if (smallest != idx)
    {
        swapEdge(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

Edge extractMin(MinHeap *minHeap)
{
    Edge root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return root;
}

void insertMinHeap(MinHeap *minHeap, Edge edge)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && edge.weight < minHeap->array[(i - 1) / 2].weight)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = edge;
}

void primMST(int **graph, int n, int start, FILE *file)
{
    int parent[n];
    int key[n];
    int inMST[n];
    MinHeap *minHeap = createMinHeap(n);

    for (int v = 0; v < n; ++v)
    {
        key[v] = INT32_MAX;
        inMST[v] = 0;
        minHeap->array[v].vertex = v;
        minHeap->array[v].weight = key[v];
    }

    minHeap->array[start].vertex = start;
    minHeap->array[start].weight = key[start] = 0;
    minHeap->size = n;

    while (minHeap->size)
    {
        Edge minEdge = extractMin(minHeap);
        int u = minEdge.vertex;
        inMST[u] = 1;

        for (int v = 0; v < n; ++v)
        {
            if (graph[u][v] && inMST[v] == 0 && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
                insertMinHeap(minHeap, (Edge){v, key[v]});
            }
        }
    }

    int totalCost = 0;
    int **mst = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        mst[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            mst[i][j] = 0;
        }
    }

    for (int i = 1; i < n; ++i)
    {
        mst[parent[i]][i] = graph[parent[i]][i];
        mst[i][parent[i]] = graph[parent[i]][i];
        totalCost += graph[parent[i]][i];
    }

    printf("Cost adjacency matrix of the minimum spanning tree:\n");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d ", mst[i][j]);
            fprintf(file, "%d ", mst[i][j]);
        }
        printf("\n");
        fprintf(file, "\n");
    }
    printf("Total cost of the minimum spanning tree: %d\n", totalCost);
    fprintf(file, "Total cost of the minimum spanning tree: %d\n", totalCost);
    fclose(file);

    for (int i = 0; i < n; i++)
    {
        free(mst[i]);
    }
    free(mst);
    free(minHeap->array);
    free(minHeap);
}

int main()
{
    FILE *file = fopen("inputs/8123_6_1_inUnAdjMat.dat", "r");
    if (!file)
    {
        printf("Unable to open file.\n");
        return 1;
    }
    int n;
    printf("Enter the Number Of Vertices: ");
    scanf("%d", &n);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            fscanf(file, "%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = INT32_MAX;
        }
    }

    fclose(file);
    file = fopen("outputs/8123_6_1_outUnAdjMat.dat", "w");
    int start;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    start--;
    primMST(graph, n, start, file);
    for (int i = 0; i < n; i++)
    {
        free(graph[i]);
    }
    free(graph);
    return 0;
}