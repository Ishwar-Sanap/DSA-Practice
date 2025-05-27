#include <bits/stdc++.h>
using namespace std;

// Memoization : T.C --> O(N*M) S.C --> O(N*M) + O(N*M)
int tryAllWays(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0 || obstacleGrid[i][j] == 1)
        return 0;
    if (i == 0 && j == 0)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = tryAllWays(i - 1, j, obstacleGrid, dp);
    int left = tryAllWays(i, j - 1, obstacleGrid, dp);

    return dp[i][j] = up + left;
}

// Tabulation
int uniquePathsWithObstacles_T(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // base case
            if (obstacleGrid[i][j] == 1)
                continue;
            else if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }

            int up = i - 1 < 0 ? 0 : dp[i - 1][j];
            int left = j - 1 < 0 ? 0 : dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }
    return dp[m - 1][n - 1];
}

// Space optimization
int uniquePathsWithObstacles_Optimized(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<int> prevRow(n, 0);

    for (int i = 0; i < m; i++)
    {
        vector<int> currRow(n, 0);
        for (int j = 0; j < n; j++)
        {
            // base case
            if (obstacleGrid[i][j] == 1)
                continue;
            else if (i == 0 && j == 0)
            {
                currRow[j] = 1;
                continue;
            }

            int up = i - 1 < 0 ? 0 : prevRow[j];
            int left = j - 1 < 0 ? 0 : currRow[j - 1];

            currRow[j] = up + left;
        }

        prevRow = currRow;
    }
    return prevRow[n - 1];
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return tryAllWays(m - 1, n - 1, obstacleGrid, dp);
}
int main()
{
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << uniquePathsWithObstacles(grid) << endl;

    return 0;
}