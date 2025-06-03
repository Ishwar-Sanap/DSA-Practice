#include <bits/stdc++.h>
using namespace std;
/*
return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.
https://leetcode.com/problems/coin-change-ii/description/

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
*/

// Tabulation : T.C O(N*Amount) S.C O(N*Amount)
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    for (int i = 0; i < n; i++)
    {
        for (int currAmount = 0; currAmount <= amount; currAmount++)
        {
            // base case..
            if (i == 0)
            {
                if (currAmount % coins[i] == 0)
                    dp[i][currAmount] = 1; // paisa bn sakta haii.....

                else
                    dp[i][currAmount] = 0;

                continue;
            }

            long long pick = 0, notPick = 0;
            if (coins[i] <= currAmount)
                pick = dp[i][currAmount - coins[i]];

            notPick = dp[i - 1][currAmount];

            dp[i][currAmount] = pick + notPick; // since we have to count all possible ways to make moneny
        }
    }

    return dp[n - 1][amount];
}

// space optimization :  T.C O(N*Amount) S.C O(Amount)
int change_OP(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<int> prevRow(amount + 1, 0);
    vector<int> currRow(amount + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int currAmount = 0; currAmount <= amount; currAmount++)
        {
            // base case..
            if (i == 0)
            {
                if (currAmount % coins[i] == 0)
                    currRow[currAmount] = 1; // paisa bn sakta haii.....

                else
                    currRow[currAmount] = 0;

                continue;
            }

            long long pick = 0, notPick = 0;
            if (coins[i] <= currAmount)
                pick = currRow[currAmount - coins[i]];

            notPick = prevRow[currAmount];

            currRow[currAmount] = pick + notPick; // since we have to count all possible ways to make moneny
        }

        prevRow = currRow;
    }

    return prevRow[amount];
}

int main()
{

    vector<int> coins = {1, 2, 5};
    cout << change_OP(5, coins) << endl;

    return 0;
}