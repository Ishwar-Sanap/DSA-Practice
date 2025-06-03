#include <bits/stdc++.h>
using namespace std;

/*

Given n items, each with a specific weight and value, and a knapsack with a capacity
 of W, the task is to put the items in the knapsack such that the sum of weights of
 the items <= W and the sum of values associated with them is maximized.
Note: You can either place an item entirely in the bag or leave it out entirely.
Also, each item is available in single quantity.

 https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

*/

// Memoization : T.C --> O(N*W)  S.C --> O(N*w) + O(N)
int tryAllWays(int indx, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{
    // Base cases...
    if (W == 0)
        return 0;

    if (indx == 0)
    {
        if (wt[indx] <= W)
            return val[indx];
        return 0;
    }
    if (dp[indx][W] != -1)
        return dp[indx][W];

    int pick = 0, notPick = 0;
    if (wt[indx] <= W)
        pick = val[indx] + tryAllWays(indx - 1, W - wt[indx], val, wt, dp);

    notPick = 0 + tryAllWays(indx - 1, W, val, wt, dp);

    return dp[indx][W] = max(pick, notPick);
}

// Tabulation :  T.C --> O(N*W)  S.C --> O(N*w)
int tryAllWays_T(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    for (int i = 0; i < n; i++)
    {
        for (int currWt = 0; currWt <= W; currWt++)
        {
            // Base cases
            if (currWt == 0)
            {

                dp[i][currWt] = 0;
                continue;
            }

            if (i == 0)
            {
                if (wt[i] <= currWt)
                    dp[i][currWt] = val[i];

                continue;
            }

            int pick = 0, notPick = 0;
            if (wt[i] <= currWt)
                pick = val[i] + dp[i - 1][currWt - wt[i]];

            notPick = 0 + dp[i - 1][currWt];

            dp[i][currWt] = max(pick, notPick);
        }
    }

    return dp[n - 1][W];
}

// Space optimization T.C --> O(N*W)  S.C --> O(W)
int knapsack_Optimized(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();
    vector<int> prevRow(W + 1, 0);
    vector<int> currRow(W + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int currWt = 0; currWt <= W; currWt++)
        {
            // Base cases
            if (currWt == 0)
            {

                currRow[currWt] = 0;
                continue;
            }

            if (i == 0)
            {
                if (wt[i] <= currWt)
                    currRow[currWt] = val[i];

                continue;
            }

            int pick = 0, notPick = 0;
            if (wt[i] <= currWt)
                pick = val[i] + prevRow[currWt - wt[i]];

            notPick = 0 + prevRow[currWt];

            currRow[currWt] = max(pick, notPick);
        }

        prevRow = currRow;
    }

    return prevRow[W];
}

int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    // code here
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));

    // return tryAllWays(n - 1, W, val, wt, dp);
    return knapsack_Optimized(W, val, wt);
}
int main()
{
    vector<int> val = {10, 6, 5, 4, 15, 2};
    vector<int> wt = {2, 8, 11, 2, 7, 3};


    cout << knapsack(10, val, wt);

    return 0;
}