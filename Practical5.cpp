// Implementation of 0/1 Knapsack Problem using Dynamic Programming
#include <iostream>
using namespace std;
#define MAX 100

/*=========================================================
    0/1 Knapsack Problem

    How it works:
    For every item, we have two choices:
    1. Do not include the item.
    2. Include the item if it fits.

    The DP table stores the maximum profit possible
    for each number of items and each capacity.

    Idea:
    Divide the problem into smaller problems and store
    their results to avoid repeated calculations.

    Time Complexity:
    Best Case    : O(n * W)
    Average Case : O(n * W)
    Worst Case   : O(n * W)

    Space Complexity:
    O(n * W)

    Where:
    n = Number of items
    W = Knapsack capacity
=========================================================*/

int maximum(int a, int b)
{
    return (a > b) ? a : b;
}


// Knapsack Function
int knapsack(int wt[], int profit[], int n, int W)
{
    int dp[MAX][MAX] = {0};

    for(int i = 1; i <= n; i++)
    {
        for(int w = 1; w <= W; w++)
        {
            if(wt[i - 1] <= w)
            {
                // Take the item or leave it
                dp[i][w] = maximum(
                    profit[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );
            }
            else
            {
                // Item does not fit
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int wt[MAX], profit[MAX];
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter weights:\n";
    for(int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter profits:\n";
    for(int i = 0; i < n; i++)
        cin >> profit[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;

    cout << "\nMaximum Profit = "
         << knapsack(wt, profit, n, W);

    return 0;
}


/*
====================== SAMPLE OUTPUT ======================

Enter number of items: 4

Enter weights:
2 1 3 2

Enter profits:
12 10 20 15

Enter knapsack capacity: 5

Maximum Profit = 37

============================================================

WORKING:

Item     Weight     Profit
  1        2          12
  2        1          10
  3        3          20
  4        2          15

Capacity = 5

Selected Items:
Item 1 + Item 2 + Item 4

Total Weight:
2 + 1 + 2 = 5

Total Profit:
12 + 10 + 15 = 37

Maximum Profit = 37

============================================================
*/