#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

https://leetcode.com/problems/coin-change/description/

coins --> [20,40,50] , amount --> 180
output --> 4 (50 + 50 + 40 + 40)

*/

// Why Greedy approach will fail..
/*
    - if we tried by taking largest dominatinos first, and using coin[i] till all of their potential

    amount = amount % coins[i]

    // since we use all potential of current coin i , but in future there migh be no coin
    that will help to reduce amount :)

    so we have to optimally decide how much time current coins should take....
    that why greedy fails here....
*/

// Memoization : T.C --> O(N * A)  S.C --> O(N) + O(N * A)
int tryAllWays(int indx, int amount, vector<int> &coins, vector<vector<int>> &dp)
{

    if (amount == 0)
        return 0;

    if (indx == 0)
    {
        // since 0th index can be taken multiple times
        if ((amount % coins[indx]) == 0)
            return amount / coins[indx];

        // not possible
        return 1e7; // Returning smaller value than INT_MAX, sinc after returnig ther might be integer overflow cases
    }

    if (dp[indx][amount] != -1)
        return dp[indx][amount];

    int pick = 1e7, notPick = 1e7;

    if (coins[indx] <= amount)
    {
        // we can pick denomination of coin multiple times
        pick = 1 + tryAllWays(indx, amount - coins[indx], coins, dp);
    }

    notPick = 0 + tryAllWays(indx - 1, amount, coins, dp);

    return dp[indx][amount] = min(pick, notPick);
}

// Tabulation :   T.C --> O(N * A)  S.C --> O(N * A)
int tryAllWaysT(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    for (int i = 0; i < n; i++)
    {
        for (int am = 1; am <= amount; am++)
        {
            if (i == 0)
            {
                // since 0th index can be taken multiple times
                if ((am % coins[i]) == 0)
                    dp[i][am] = am / coins[i];

                else                 // not possible
                    dp[i][am] = 1e7; // Returning smaller value than INT_MAX, sinc after returnig ther migh be integer

                continue;
            }

            int pick = 1e7, notPick = 1e7;

            if (coins[i] <= am)
            {
                // we can pick denomination of coin multiple times
                pick = 1 + dp[i][am - coins[i]];
            }

            notPick = 0 + dp[i - 1][am];

            dp[i][am] = min(pick, notPick);
        }
    }

    return dp[n - 1][amount] == 1e7 ? -1 : dp[n - 1][amount];
}

// Space optimization to above tabulation is possible, using PrevRow, and currRow
// concept since we only using previous row and curr row every time
// T.C --> O(N * A)  S.C --> O( A)

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    int cnt = tryAllWays(n - 1, amount, coins, dp);
    return cnt == 1e7 ? -1 : cnt;
}

int main()
{
    vector<int> arr = {20, 40, 50};
    cout << coinChange(arr, 180) << endl;
    return 0;
}