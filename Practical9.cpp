// Implementation of Prim's Algorithm
#include <iostream>
using namespace std;

#define MAX 100
#define INF 999999

/*=========================================================
    Prim's Algorithm - Minimum Spanning Tree

    How it works:
    1. Start from vertex 0.
    2. Find the minimum-weight edge connecting a selected
       vertex to an unselected vertex.
    3. Add the edge to the MST.
    4. Repeat until n - 1 edges are selected.

    Idea:
    Greedily select the minimum-weight edge that connects
    the MST to a new vertex.

    Time Complexity:
    Best Case    : O(V^2)
    Average Case : O(V^2)
    Worst Case   : O(V^2)

    Space Complexity:
    O(V^2)

    Note:
    The graph must be connected and undirected.
    Enter 0 for no edge between different vertices.
=========================================================*/

void primMST(int graph[MAX][MAX], int n)
{
    int selected[MAX] = {0};
    int totalCost = 0;

    // Start from vertex 0
    selected[0] = 1;

    cout << "\nMST Edges:\n";
    cout << "Source\tDestination\tWeight\n";

    // An MST contains n - 1 edges
    for(int edge = 0; edge < n - 1; edge++)
    {
        int minimum = INF;
        int source = -1, destination = -1;

        // Find the minimum edge connecting selected
        // and unselected vertices
        for(int i = 0; i < n; i++)
        {
            if(selected[i] == 1)
            {
                for(int j = 0; j < n; j++)
                {
                    if(selected[j] == 0 &&
                       graph[i][j] != 0 &&
                       graph[i][j] < minimum)
                    {
                        minimum = graph[i][j];
                        source = i;
                        destination = j;
                    }
                }
            }
        }

        // Check whether an edge was found
        if(source == -1)
        {
            cout << "\nGraph is disconnected!";
            return;
        }

        cout << source << "\t"
             << destination << "\t\t"
             << minimum << endl;

        totalCost += minimum;
        selected[destination] = 1;
    }

    cout << "\nMinimum Cost = " << totalCost << endl;
}

int main()
{
    int graph[MAX][MAX];
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    if(n <= 0 || n > MAX)
    {
        cout << "Invalid number of vertices!";
        return 1;
    }

    cout << "Enter cost adjacency matrix:\n";
    cout << "Enter 0 for no edge.\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> graph[i][j];
    }

    primMST(graph, n);

    return 0;
}

/*
Sample Output:

Enter number of vertices: 4
Enter cost adjacency matrix:
Enter 0 for no edge.
0 10 6 0
10 0 5 15
6 5 0 4
0 15 4 0

MST Edges:
Source  Destination     Weight
0       2               6
2       3               4
2       1               5

Minimum Cost = 15
*/