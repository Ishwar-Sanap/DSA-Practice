#include <bits/stdc++.h>
using namespace std;

/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next
row that is either directly below or diagonally left/right. Specifically, the next
element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

https://leetcode.com/problems/minimum-falling-path-sum/description/

*/

// T.C --> O(N*M)  S.C --> O(N)(path to reach last row recursive stack space) + O(N*M)
int tryAllWays(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    int m = matrix.size(), n = matrix[0].size();

    if (i >= m || j >= n || j < 0)
        return INT_MAX;
    // base condtion reached to last row
    // Due to variable ending point , best answer can be any column of last row
    if (i == m - 1)
        return matrix[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int d1 = tryAllWays(i + 1, j - 1, matrix, dp);
    int d2 = tryAllWays(i + 1, j, matrix, dp);
    int d3 = tryAllWays(i + 1, j + 1, matrix, dp);

    if (d1 != INT_MAX)
        d1 += matrix[i][j];
    if (d2 != INT_MAX)
        d2 += matrix[i][j];
    if (d3 != INT_MAX)
        d3 += matrix[i][j];

    return dp[i][j] = min({d1, d2, d3});
}

// Tabulation Approach T.C --> O(N*M)  S.C --> O(N*M)
int tryAllWays(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1)
            {
                dp[i][j] = matrix[i][j];
                continue;
            }

            int d1 = INT_MAX, d2 = INT_MAX, d3 = INT_MAX;

            if (j - 1 >= 0)
                d1 = matrix[i][j] + dp[i + 1][j - 1];

            d2 = matrix[i][j] + dp[i + 1][j];

            if (j + 1 <= n - 1)
                d3 = matrix[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min({d1, d2, d3});
        }
    }

    // Since you have computed DP array for min answer
    int minVal = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        minVal = min(minVal, dp[0][j]);
    }

    return minVal;
}

// Space optimization  T.C --> O(N*M)  S.C --> O(N)
int tryAllWays_Space_Optimized(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    // every time you are required only nextRow
    vector<int> nextRow(n, 0);

    for (int i = m - 1; i >= 0; i--)
    {
        vector<int> currRow(n, 0);
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1)
            {
                currRow[j] = matrix[i][j];
                continue;
            }

            int d1 = INT_MAX, d2 = INT_MAX, d3 = INT_MAX;

            if (j - 1 >= 0)
                d1 = matrix[i][j] + nextRow[j - 1];

            d2 = matrix[i][j] + nextRow[j];

            if (j + 1 <= n - 1)
                d3 = matrix[i][j] + nextRow[j + 1];

            currRow[j] = min({d1, d2, d3});
        }

        nextRow = currRow;
    }

    //Since you have computed min answer in nextRow
    int minVal = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        minVal = min(minVal, nextRow[j]);
    }

    return minVal;
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();

    // we have to select best starting location for min sum from any point form first row
    int minVal = INT_MAX;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // Try all possible starting point, due to variable starting point
    for (int j = 0; j < n; j++)
    {
        minVal = min(minVal, tryAllWays(0, j, matrix, dp));
    }

    return minVal;
}

int main()
{

    return 0;
}