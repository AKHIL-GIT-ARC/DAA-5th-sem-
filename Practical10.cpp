// Implementation of Kruskal's Algorithm
#include <iostream>
using namespace std;

#define MAX 100

struct Edge
{
    int u, v, w;
};

Edge edge[MAX];
int parent[MAX];

/*=========================================================
    Kruskal's Algorithm - Minimum Spanning Tree

    How it works:
    1. Sort all edges in increasing order of weight.
    2. Select the smallest edge that does not form a cycle.
    3. Merge the sets of the selected edge's vertices.
    4. Repeat until V - 1 edges are selected.

    Idea:
    Use a greedy approach to select the minimum-weight
    edges without forming a cycle.

    Time Complexity:
    Best Case    : O(E^2)
    Average Case : O(E^2)
    Worst Case   : O(E^2)

    Space Complexity:
    O(V + E)

    Where:
    V = Number of vertices
    E = Number of edges
=========================================================*/

// Find the representative of a vertex
int find(int x)
{
    while(parent[x] != x)
        x = parent[x];

    return x;
}

// Merge two sets
void Union(int a, int b)
{
    parent[a] = b;
}

// Sort edges using Bubble Sort
void sortEdges(int e)
{
    Edge temp;

    for(int i = 0; i < e - 1; i++)
    {
        for(int j = 0; j < e - i - 1; j++)
        {
            if(edge[j].w > edge[j + 1].w)
            {
                temp = edge[j];
                edge[j] = edge[j + 1];
                edge[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int v, e, totalCost = 0;
    int selectedEdges = 0;

    cout << "Enter number of vertices: ";
    cin >> v;

    cout << "Enter number of edges: ";
    cin >> e;

    if(v <= 0 || v > MAX || e < 0 || e > MAX)
    {
        cout << "Invalid input!";
        return 1;
    }

    cout << "Enter Source, Destination and Weight:\n";

    for(int i = 0; i < e; i++)
    {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;

        if(edge[i].u < 0 || edge[i].u >= v ||
           edge[i].v < 0 || edge[i].v >= v)
        {
            cout << "Invalid vertex number!";
            return 1;
        }
    }

    // Initialize each vertex as a separate set
    for(int i = 0; i < v; i++)
        parent[i] = i;

    // Sort edges by weight
    sortEdges(e);

    cout << "\nMST Edges:\n";
    cout << "Source\tDestination\tWeight\n";

    // Select edges without forming a cycle
    for(int i = 0; i < e && selectedEdges < v - 1; i++)
    {
        int p1 = find(edge[i].u);
        int p2 = find(edge[i].v);

        if(p1 != p2)
        {
            Union(p1, p2);

            cout << edge[i].u << "\t"
                 << edge[i].v << "\t\t"
                 << edge[i].w << endl;

            totalCost += edge[i].w;
            selectedEdges++;
        }
    }

    if(selectedEdges == v - 1)
        cout << "\nMinimum Cost = " << totalCost << endl;
    else
        cout << "\nGraph is disconnected. MST cannot be formed.\n";

    return 0;
}

/*
Sample Output:

Enter number of vertices: 4
Enter number of edges: 5
Enter Source, Destination and Weight:
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

MST Edges:
Source  Destination     Weight
2       3               4
0       3               5
0       1               10

Minimum Cost = 19
*/