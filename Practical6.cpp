// Implementation of Matrix Chain Multiplication using Dynamic Programming
#include <iostream>
using namespace std;

#define MAX 100

/*=========================================================
    Matrix Chain Multiplication

    How it works:
    1. Divide the chain of matrices into smaller parts.
    2. Try every possible position to split the chain.
    3. Calculate the multiplication cost for each split.
    4. Store the minimum cost in the DP table.
    5. The final minimum cost is stored in dp[1][n].

    Idea:
    Find the best order to multiply matrices so that
    the total number of scalar multiplications is minimum.

    Time Complexity:
    Best Case    : O(n^3)
    Average Case : O(n^3)
    Worst Case   : O(n^3)

    Space Complexity:
    O(n^2)

    Note:
    Matrix dimensions are given using an array p[].
    For n matrices, n + 1 dimensions are required.
=========================================================*/

int matrixChain(int p[], int n)
{
    int dp[MAX][MAX] = {0};

    // Chain length
    for(int len = 2; len <= n; len++)
    {
        for(int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = 999999;

            // Try every possible split
            for(int k = i; k < j; k++)
            {
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if(cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    return dp[1][n];
}

int main()
{
    int n, p[MAX];

    cout << "Enter number of matrices: ";
    cin >> n;

    cout << "Enter " << n + 1 << " dimensions:\n";
    for(int i = 0; i <= n; i++)
        cin >> p[i];

    cout << "\nMatrix Details:\n";

    for(int i = 1; i <= n; i++)
    {
        cout << "A" << i << " = "
             << p[i - 1] << " x " << p[i] << endl;
    }

    cout << "\nMinimum Scalar Multiplications = "
         << matrixChain(p, n);

    return 0;
}


/*
====================== SAMPLE OUTPUT ======================

Enter number of matrices: 3
Enter 4 dimensions:
10 20 30 40

Matrix Details:
A1 = 10 x 20
A2 = 20 x 30
A3 = 30 x 40

Minimum Scalar Multiplications = 18000

============================================================

WORKING:

Matrices:
A1 = 10 x 20
A2 = 20 x 30
A3 = 30 x 40

Possible orders:

(A1 × A2) × A3
Cost = 10×20×30 + 10×30×40
     = 6000 + 12000
     = 18000

A1 × (A2 × A3)
Cost = 20×30×40 + 10×20×40
     = 24000 + 8000
     = 32000

Therefore:

Minimum Scalar Multiplications = 18000

============================================================
*/