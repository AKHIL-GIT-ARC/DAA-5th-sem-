 // Implementation of Graph Traversal using DFS and BFS
#include <iostream>
using namespace std;

#define MAX 100
/*=========================================================
    Depth First Search (DFS)

    How it works:
    1. Visit and print the current vertex.
    2. Mark it as visited.
    3. Visit an unvisited adjacent vertex recursively.
    4. Backtrack when no unvisited adjacent vertex remains.

    Idea:
    Explore as deeply as possible before backtracking.

    Time Complexity:
    Best Case    : O(V^2)
    Average Case : O(V^2)
    Worst Case   : O(V^2)

    Space Complexity:
    O(V)

    Note:
    Uses an adjacency matrix and a visited array.
=========================================================*/

void dfs(int graph[MAX][MAX], int visited[], int v, int n)
{
    visited[v] = 1;
    cout << v << " ";

    for(int i = 0; i < n; i++)
    {
        if(graph[v][i] == 1 && visited[i] == 0)
            dfs(graph, visited, i, n);
    }
}

/*=========================================================
    Breadth First Search (BFS)

    How it works:
    1. Mark the starting vertex as visited and add it
       to the queue.
    2. Remove a vertex from the front and print it.
    3. Add its unvisited adjacent vertices to the queue.
    4. Repeat until the queue becomes empty.

    Idea:
    Visit vertices level by level using a queue.

    Time Complexity:
    Best Case    : O(V^2)
    Average Case : O(V^2)
    Worst Case   : O(V^2)

    Space Complexity:
    O(V)

    Note:
    Uses an adjacency matrix and an array-based queue.
=========================================================*/

void bfs(int graph[MAX][MAX], int start, int n)
{
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while(front < rear)
    {
        int v = queue[front++];
        cout << v << " ";

        for(int i = 0; i < n; i++)
        {
            if(graph[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int graph[MAX][MAX];
    int visited[MAX] = {0};
    int n, start, ch;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> graph[i][j];
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    if(n <= 0 || n > MAX || start < 0 || start >= n)
    {
        cout << "Invalid input!";
        return 1;
    }

    cout << "\n1. DFS";
    cout << "\n2. BFS";
    cout << "\nEnter your choice: ";
    cin >> ch;

    switch(ch)
    {
        case 1:
            cout << "\nDFS Traversal: ";
            dfs(graph, visited, start, n);
            break;

        case 2:
            cout << "\nBFS Traversal: ";
            bfs(graph, start, n);
            break;

        default:
            cout << "Invalid choice!";
    }

    cout << endl;
    return 0;
}

/*
Sample Output:

Enter number of vertices: 4
Enter adjacency matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
Enter starting vertex: 0

1. DFS
2. BFS
Enter your choice: 1

DFS Traversal: 0 1 3 2
*/