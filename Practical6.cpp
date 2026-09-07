// Implementation of Matrix Chain Multiplication using Dynamic Programming
#include <iostream>
using namespace std;

#define MAX 100
#define INF 999999

/*=========================================================
    Matrix Chain Multiplication

    How it works:
    1. Divide the matrix chain into smaller chains.
    2. Try every possible position to split the chain.
    3. Calculate the multiplication cost for each split.
    4. Store the minimum cost in the DP table.
    5. The final answer is stored in dp[1][n].

    Idea:
    Find the best order of multiplying matrices so that
    the total number of scalar multiplications is minimum.

    Time Complexity:
    Best Case    : O(n^3)
    Average Case : O(n^3)
    Worst Case   : O(n^3)

    Space Complexity:
    O(n^2)

    Note:
    For n matrices, n + 1 dimensions are required.
=========================================================*/

int matrixChain(int p[], int n)
{
    int dp[MAX][MAX] = {0};

    // Cost of multiplying one matrix is 0
    for(int i = 1; i <= n; i++)
        dp[i][i] = 0;

    // Find minimum cost for different chain lengths
    for(int len = 2; len <= n; len++)
    {
        for(int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INF;

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

    // Display DP Table
    cout << "\nDP Cost Table:\n\n";

    cout << "\t";
    for(int i = 1; i <= n; i++)
        cout << "A" << i << "\t";

    cout << endl;

    for(int i = 1; i <= n; i++)
    {
        cout << "A" << i << "\t";

        for(int j = 1; j <= n; j++)
        {
            if(j < i)
                cout << "-\t";
            else
                cout << dp[i][j] << "\t";
        }

        cout << endl;
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

    // Display matrix details
    cout << "\nMatrix Details:\n";

    for(int i = 1; i <= n; i++)
    {
        cout << "A" << i << " = "
             << p[i - 1] << " x " << p[i] << endl;
    }

    int result = matrixChain(p, n);

    cout << "\nMinimum Scalar Multiplications = "
         << result << endl;

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

DP Cost Table:

        A1      A2      A3
A1      0       6000    18000
A2      -       0       24000
A3      -       -       0

Minimum Scalar Multiplications = 18000


====================== TABLE MEANING ======================

dp[i][j] represents the minimum number of scalar
multiplications required to multiply matrices Ai to Aj.

For example:

dp[1][2] = 6000

A1(10x20) × A2(20x30)

Cost = 10 × 20 × 30
     = 6000


dp[2][3] = 24000

A2(20x30) × A3(30x40)

Cost = 20 × 30 × 40
     = 24000


dp[1][3] = 18000

Minimum cost for A1 × A2 × A3.

Possible orders:

(A1 × A2) × A3

= 10×20×30 + 10×30×40
= 6000 + 12000
= 18000


A1 × (A2 × A3)

= 20×30×40 + 10×20×40
= 24000 + 8000
= 32000


Therefore:

Minimum Scalar Multiplications = 18000

============================================================
*/