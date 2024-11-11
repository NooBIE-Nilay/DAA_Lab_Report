/*
Given an undirected weighted connected graph G(V, E).Apply Krushkal's algorithm to
        Find the minimum spanning tree T(V, E') and Display the selected edges of G.
        Display total cost of the minimum spanning tree T.
Note: Nodes will be numbered consecutively from 1 to n(user input), and edges will have varying weight.The weight matrix of the graph can be represented from the user's input in the given format.The expected output could be the selected edge and the corresponding cost of the edge as per the sample output.

Input Format :
    The first line contains two space - separated integers 'n' and 'm', the number of nodes and edges in the graph.
    Each line 'i' of the 'm' subsequent lines contains three space - separated integers 'u' , 'v' and 'w', that describe an edge(u, v) and weight 'w'.

Input :
9 14
1 2 4
1 8 8
2 3 8
2 8 11
3 4 7
3 6 4
3 9 2
4 5 9
4 6 14
5 6 10
6 7 2
7 8 1
7 9 6
8 9 7

Output :
Edge_123  Cost
8 --7  1
7 --6  2
3 --9  2
1 --2  4
3 --6  4
3 --4  7
1 --8  8
4 --5  9
Total Weight of the Spanning Tree : 37
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int u, v, w;
} Edge_123;

typedef struct
{
    int parent;
    int rank;
} Subset_123;

int compareEdges_123(const void *a_123, const void *b_123)
{
    Edge_123 *edgeA_123 = (Edge_123 *)a_123;
    Edge_123 *edgeB = (Edge_123 *)b_123;
    return edgeA_123->w - edgeB->w;
}

int find_123(Subset_123 subsets_123[], int i)
{
    if (subsets_123[i].parent != i)
    {
        subsets_123[i].parent = find_123(subsets_123, subsets_123[i].parent);
    }
    return subsets_123[i].parent;
}

void unionSets_123(Subset_123 subsets_123[], int x_123, int y_123)
{
    int rootX_123 = find_123(subsets_123, x_123);
    int rootY_123 = find_123(subsets_123, y_123);

    if (subsets_123[rootX_123].rank < subsets_123[rootY_123].rank)
    {
        subsets_123[rootX_123].parent = rootY_123;
    }
    else if (subsets_123[rootX_123].rank > subsets_123[rootY_123].rank)
    {
        subsets_123[rootY_123].parent = rootX_123;
    }
    else
    {
        subsets_123[rootY_123].parent = rootX_123;
        subsets_123[rootX_123].rank++;
    }
}

void kruskal_123(Edge_123 edges_123[], int n, int m)
{
    qsort(edges_123, m, sizeof(Edge_123), compareEdges_123);

    Subset_123 *subsets_123 = (Subset_123 *)malloc(n * sizeof(Subset_123));
    for (int v = 0; v < n; ++v)
    {
        subsets_123[v].parent = v;
        subsets_123[v].rank = 0;
    }

    Edge_123 *result = (Edge_123 *)malloc((n - 1) * sizeof(Edge_123));
    int e = 0;
    int i = 0;
    int totalCost_123 = 0;

    while (e < n - 1 && i < m)
    {
        Edge_123 nextEdge = edges_123[i++];
        int x_123 = find_123(subsets_123, nextEdge.u);
        int y_123 = find_123(subsets_123, nextEdge.v);

        if (x_123 != y_123)
        {
            result[e++] = nextEdge;
            totalCost_123 += nextEdge.w;
            unionSets_123(subsets_123, x_123, y_123);
        }
    }

    printf("Edge_123     Cost\n");
    for (i = 0; i < e; ++i)
    {
        printf("%d--%d     %d\n", result[i].u + 1, result[i].v + 1, result[i].w);
    }
    printf("Total Weight of the Spanning Tree: %d\n", totalCost_123);

    free(subsets_123);
    free(result);
}

int main()
{
    int n, m;
    printf("Enter the Number of Vertices and Edges: ");
    scanf("%d %d", &n, &m);

    Edge_123 *edges_123 = (Edge_123 *)malloc(m * sizeof(Edge_123));
    printf("Enter the Edges and Weights in the order \n[vertex1 vertex2 weight]:\n");
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d %d", &edges_123[i].u, &edges_123[i].v, &edges_123[i].w);
        edges_123[i].u--;
        edges_123[i].v--;
    }

    kruskal_123(edges_123, n, m);

    free(edges_123);
    return 0;
}
