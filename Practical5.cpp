// Implementation of 0/1 Knapsack Problem using Dynamic Programming
#include <iostream>
using namespace std;
#define MAX 100

/*=========================================================
    0/1 Knapsack using Dynamic Programming

    How it works:
    1. Consider each item one by one.
    2. For every capacity, check two choices:
       - Do not take the current item.
       - Take the current item if it fits.
    3. Store the maximum value in a DP table.
    4. The final answer is stored in dp[n][capacity].

    Idea:
    Maximize the total value of selected items without
    exceeding the given bag capacity.

    Note:
    Each item can be taken only once (0/1).

    Time Complexity:
    Best Case    : O(n * W)
    Average Case : O(n * W)
    Worst Case   : O(n * W)

    Space Complexity:
    O(n * W)

    n = Number of items
    W = Knapsack capacity
=========================================================*/

int knapsack(int weight[], int value[], int n, int capacity)
{
    int dp[MAX][MAX] = {0};

    for(int i = 1; i <= n; i++)
    {
        for(int w = 1; w <= capacity; w++)
        {
            // Item does not fit
            if(weight[i - 1] > w)
                dp[i][w] = dp[i - 1][w];

            // Item fits: choose maximum of take and don't take
            else
                dp[i][w] = max(
                    dp[i - 1][w],
                    value[i - 1] + dp[i - 1][w - weight[i - 1]]
                );
        }
    }

    return dp[n][capacity];
}

int main()
{
    int weight[MAX], value[MAX];
    int n, capacity, i, ans;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter weights:\n";
    for(i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter values:\n";
    for(i = 0; i < n; i++)
        cin >> value[i];

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    ans = knapsack(weight, value, n, capacity);

    cout << "\nMaximum Profit = " << ans;

    return 0;
}

/*
====================== SAMPLE OUTPUT ======================

Enter number of items: 4

Enter weights:
2 1 3 2

Enter values:
12 10 20 15

Enter knapsack capacity: 5

Maximum Profit = 37

============================================================

WORKING:

Items:
Weight:  2  1  3  2
Value:  12 10 20 15

Capacity = 5

Best selection:
Item 1 + Item 2 + Item 4

Total Weight:
2 + 1 + 2 = 5

Total Value:
12 + 10 + 15 = 37

Therefore:

Maximum Profit = 37

============================================================
*/