// Implementation of Coin Change using Dynamic Programming
#include <iostream>
using namespace std;

#define MAX 100
#define INF 999999

/*=========================================================
    Coin Change Problem using Dynamic Programming

    How it works:
    1. Find the minimum coins required for each amount.
    2. Store the coin selected for the minimum solution.
    3. Count the different combinations for the target amount.

    Idea:
    Store previously calculated results to avoid
    repeated calculations.

    Time Complexity:
    Minimum Coins : O(n * Amount)
    Number of Ways: O(n * Amount)

    Space Complexity:
    O(Amount)

    Where:
    n      = Number of coin denominations
    Amount = Target amount
=========================================================*/

int minimumCoins(int coin[], int n, int amount, int selected[])
{
    int dp[MAX];
    dp[0] = 0;
    for(int i = 1; i <= amount; i++)
    {
        dp[i] = INF;
        selected[i] = -1;
    }
    for(int i = 1; i <= amount; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(coin[j] <= i && dp[i - coin[j]] != INF)
            {
                if(dp[i - coin[j]] + 1 < dp[i])
                {
                    dp[i] = dp[i - coin[j]] + 1;
                    selected[i] = coin[j];
                }
            }
        }
    }
    if(dp[amount] == INF)
        return -1;
    return dp[amount];
}

int numberOfWays(int coin[], int n, int amount)
{
    int dp[MAX];
    for(int i = 0; i <= amount; i++)
        dp[i] = 0;
    dp[0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = coin[i]; j <= amount; j++)
        {
            dp[j] = dp[j] + dp[j - coin[i]];
        }
    }
    return dp[amount];
}

int main()
{
    int coin[MAX], selected[MAX];
    int n, amount;
    cout << "Enter number of coin denominations: ";
    cin >> n;
    cout << "Enter coin values:\n";
    for(int i = 0; i < n; i++)
        cin >> coin[i];
    cout << "Enter target amount: ";
    cin >> amount;
    int minCoins = minimumCoins(coin, n, amount, selected);
    int ways = numberOfWays(coin, n, amount);
    cout << "\nCoin Denominations: ";
    for(int i = 0; i < n; i++)
        cout << coin[i] << " ";
    cout << "\nTarget Amount: " << amount;
    if(minCoins == -1)
    {
        cout << "\nMinimum Coins: Cannot make the amount";
        cout << "\nCoins Used: None";
    }
    else
    {
        cout << "\nMinimum Coins: " << minCoins;
        cout << "\nCoins Used: ";
        int current = amount;
        while(current > 0)
        {
            cout << selected[current];
            current = current - selected[current];
            if(current > 0)
                cout << " + ";
        }
    }
    cout << "\nNumber of Ways: " << ways << endl;
    return 0;
}

/*
Sample Output:

Enter number of coin denominations: 3
Enter coin values:
1 2 5
Enter target amount: 5

Coin Denominations: 1 2 5
Target Amount: 5
Minimum Coins: 1
Coins Used: 5
Number of Ways: 4
*/