#include <bits/stdc++.h>
using namespace std;

/*
https://www.naukri.com/code360/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&leftPanelTab=0&leftPanelTabValue=PROBLEM

*/

// Memoization : T.C --> O(N*M*M)*9  S.C --> O(N*M*M) + O(N)
int tryAllWays(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    int m = grid.size(), n = grid[0].size();
    // out of bound
    if (j1 < 0 || j2 < 0 || j1 >= n || j2 >= n)
        return -1e6;

    // base case reach to the last row
    if (i == m - 1)
    {
        // if both are on same cell only one can pick
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    // For each Alice move there are 3 differents Bobs move possible
    int maxValue = -1e6;
    for (int m1 = -1; m1 <= 1; m1++)
    {
        for (int m2 = -1; m2 <= 1; m2++)
        {
            int currVal = 0;
            if (j1 == j2) // if both are on same cell only one can pick
                currVal = grid[i][j1] + tryAllWays(i + 1, j1 + m1, j2 + m2, grid, dp);
            else
                currVal = grid[i][j1] + grid[i][j2] + tryAllWays(i + 1, j1 + m1, j2 + m2, grid, dp);

            maxValue = max(maxValue, currVal);
        }
    }

    return dp[i][j1][j2] = maxValue;
}

// Tabulation:  T.C --> O(N*M*M)*9  S.C --> O(N*M*M)
int maximumChocolates_T(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    // 3D Dp
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j1 = n - 1; j1 >= 0; j1--)
        {
            for (int j2 = n - 1; j2 >= 0; j2--)
            {
                // base case
                if (i == m - 1)
                {
                    // if both are on same cell only one can pick
                    if (j1 == j2)
                        dp[i][j1][j2] = grid[i][j1];
                    else
                        dp[i][j1][j2] = grid[i][j1] + grid[i][j2];

                    continue;
                }

                // For each Alice move there are 3 differents Bobs move possible
                int maxValue = -1e6;
                for (int m1 = -1; m1 <= 1; m1++)
                {
                    for (int m2 = -1; m2 <= 1; m2++)
                    {
                        if (j1 + m1 < 0 || j1 + m1 >= n || j2 + m2 < 0 || j2 + m2 >= n)
                            continue;

                        int currVal = 0;
                        if (j1 == j2) // if both are on same cell only one can pick
                            currVal = grid[i][j1] + dp[i + 1][j1 + m1][j2 + m2];
                        else
                            currVal = grid[i][j1] + grid[i][j2] + dp[i + 1][j1 + m1][j2 + m2];

                        maxValue = max(maxValue, currVal);
                    }
                }

                dp[i][j1][j2] = maxValue;
            }
        }
    }

    return dp[0][0][n - 1];
}

// Space optimization : T.C --> O(N*M*M)*9  S.C --> O(N*N)
int maximumChocolates_T(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    // 2D Dp
    // Every time you only require next 2D array
    vector<vector<int>> next(n, vector<int>(n, 0));

    vector<vector<int>> curr(n, vector<int>(n, 0));

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j1 = n - 1; j1 >= 0; j1--)
        {
            for (int j2 = n - 1; j2 >= 0; j2--)
            {
                // base case
                if (i == m - 1)
                {
                    // if both are on same cell only one can pick
                    if (j1 == j2)
                        curr[j1][j2] = grid[i][j1];
                    else
                        curr[j1][j2] = grid[i][j1] + grid[i][j2];

                    continue;
                }

                // For each Alice move there are 3 differents Bobs move possible
                int maxValue = -1e6;
                for (int m1 = -1; m1 <= 1; m1++)
                {
                    for (int m2 = -1; m2 <= 1; m2++)
                    {
                        if (j1 + m1 < 0 || j1 + m1 >= n || j2 + m2 < 0 || j2 + m2 >= n)
                            continue;

                        int currVal = 0;
                        if (j1 == j2) // if both are on same cell only one can pick
                            currVal = grid[i][j1] + next[j1 + m1][j2 + m2];
                        else
                            currVal = grid[i][j1] + grid[i][j2] + next[j1 + m1][j2 + m2];

                        maxValue = max(maxValue, currVal);
                    }
                }

                curr[j1][j2] = maxValue;
            }
        }

        // for next i update next = curr
        next = curr;
    }

    return next[0][n - 1];
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    // We have to simaltaneous move alice and bob for collecting chocolates
    // every time they move any how they reaches to next row
    // Ex: Alice (i1, j1)  Bob (i2, j2) // both are initially at first row
    // Alice can move --> (i1+1, j1-1) (i1+1, j1) (i1+1 , j1 +1)
    // Bob can move --> (i2+1 , j2 -1) (i2+1, j2) (i2+1, j2 + 1)

    // As we can see i1 and i2 moving same row, so we can use only single varible i for both Alice and Bob

    int m = grid.size(), n = grid[0].size();

    // 3D Dp
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

    return tryAllWays(0, 0, n - 1, grid, dp);
}

int main()
{

    return 0;
}