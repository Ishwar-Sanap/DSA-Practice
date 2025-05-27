#include <bits/stdc++.h>
using namespace std;

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
https://leetcode.com/problems/minimum-path-sum/description/

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum

*/

// Tabulation : T.C O(N*M) , S.C O(N*M)
int minPathSum(vector<vector<int>> &grid)
{

    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            /// base case
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
                continue;
            }

            int up = INT_MAX, left = INT_MAX;
            if (i > 0)
                up = grid[i][j] + dp[i - 1][j];
            if (j > 0)
                left = grid[i][j] + dp[i][j - 1];

            dp[i][j] = min(up, left);
        }
    }

    return dp[m - 1][n - 1];
}

// Space optimization : T.C --> O(N*M)  S.C--> O(N)
int minPathSum_Optimized(vector<vector<int>> &grid)
{

    int m = grid.size(), n = grid[0].size();
    vector<int> prevRow(n, 0);

    for (int i = 0; i < m; i++)
    {
        vector<int> currRow(n, 0);

        for (int j = 0; j < n; j++)
        {
            /// base case
            if (i == 0 && j == 0)
            {
                currRow[j] = grid[i][j];
                continue;
            }

            int up = INT_MAX, left = INT_MAX;
            if (i > 0)
                up = grid[i][j] + prevRow[j];
            if (j > 0)
                left = grid[i][j] + currRow[j - 1];

            currRow[j] = min(up, left);
        }

        prevRow = currRow;
    }

    return prevRow[n - 1];
}

int main()
{

    return 0;
}