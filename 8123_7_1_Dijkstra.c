/*
Given a directed graph G (V, E) and a starting vertex 's'.
    Determine  the  lengths  of  the  shortest  paths  from  the  starting  vertex  's'  to  all  other vertices in the graph G using Dijkstra‟s Algorithm.
    Display the shortest path from the given source 's' to all other vertices.

Note#  Nodes  will  be  numbered consecutively  from  1  to  n  (user input),  and  edges  will  have varying distances or lengths. The graph G can be read from an input file "inDiAdjMat1.dat" that contains  non-negative  cost adjacency  matrix.  The  expected output  could  be  as  per  the  sample
format.

Content of the input file “inDiAdjMat1.dat" could be
0 10 0 5 0
0 0 1 2 0
0 0 0 0 4
3 0 9 0 2
7 0 6 0 0

Input:
Enter the Number of Vertices: 5
Enter the Source Vertex: 1

Output:
Source Destination Cost Path
1             1                  0        -
1             2                  8       1->4->2
1            3                   9       1->4->2->3
1           4                   5       1->4
1           5                   7       1->4->5
*/
