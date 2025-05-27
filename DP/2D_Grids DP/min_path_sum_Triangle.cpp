#include <bits/stdc++.h>
using namespace std;

/*
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11

The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11
https://leetcode.com/problems/triangle/description/
*/

// Memoization : T.C --> O(m*n)  S.C --> O(m*m) + O(m*m)
int tryAllWays(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    int m = triangle.size(), n = triangle[i].size();

    if (i >= m || j >= n)
        return INT_MAX;
    
    // Due to variable size ending point , best answer can be any column of last row
    if (i == m - 1)
        return triangle[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = triangle[i][j] + tryAllWays(i + 1, j, triangle, dp);
    int cross = triangle[i][j] + tryAllWays(i + 1, j + 1, triangle, dp);

    return dp[i][j] = min(down, cross);
}

// Tabulation T.c --> O(m*n)  s.c --> O(m*m)
int tryAllWays(vector<vector<int>> &triangle)
{
    int m = triangle.size();
    vector<vector<int>> dp(m, vector<int>(m, -1));

    for (int i = m - 1; i >= 0; i--)
    {
        int n = triangle[i].size();
        for (int j = n - 1; j >= 0; j--)
        {
            // base condition
            if (i == m - 1)
            {
                dp[i][j] = triangle[i][j];
                continue;
            }

            int cross = INT_MAX, down = INT_MAX;

            down = triangle[i][j] + dp[i + 1][j];

            cross = triangle[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(cross, down);
        }
    }
    return dp[0][0];
}
int minimumTotal_optimized(vector<vector<int>> &triangle)
{
    int m = triangle.size();
    int size = triangle[m - 1].size();

    vector<int> nexRow(size, 0);

    for (int i = m - 1; i >= 0; i--)
    {
        int n = triangle[i].size();
        vector<int> currRow(n, 0);

        for (int j = n - 1; j >= 0; j--)
        {
            // base condition
            if (i == m - 1)
            {
                currRow[j] = triangle[i][j];
                continue;
            }

            int cross = INT_MAX, down = INT_MAX;

            down = triangle[i][j] + nexRow[j];

            cross = triangle[i][j] + nexRow[j + 1];

            currRow[j] = min(cross, down);
        }

        nexRow = currRow;
    }
    return nexRow[0];
}
int minimumTotal(vector<vector<int>> &triangle)
{

    int m = triangle.size(), n = triangle[0].size();
    vector<vector<int>> dp(m, vector<int>(m, -1));

    return tryAllWays(0, 0, triangle, dp);
}

int main()
{

    return 0;
}