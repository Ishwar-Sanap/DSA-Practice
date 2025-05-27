#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/unique-paths/description/

// Memoization
// T.C --> O(N*M)  S.C --> O(n-1 + m-1) recusive stack space + O(N*M) extra dp array
int tryAllWays(int i, int j, vector<vector<int>> &dp)
{
    // Invalid index
    if (i < 0 || j < 0)
        return 0;

    // base case
    if (i == 0 && j == 0)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = tryAllWays(i - 1, j, dp);
    int left = tryAllWays(i, j - 1, dp);

    return dp[i][j] = up + left;
}

// Tabulation
// T.C --> O(N*M) S.C --> O(N*M)
int tryAllWays(int i, int j, int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // base case
    dp[0][0] = 1;

    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row == 0 && col == 0)
                continue;

            int up = row - 1 < 0 ? 0 : dp[row - 1][col];
            int left = col - 1 < 0 ? 0 : dp[row][col - 1];

            dp[row][col] = up + left;
        }
    }

    return dp[m - 1][n - 1];
}

// Space optimiation
//  If ther is prev row or prev col used then we can optimized the space
int uniquePaths_Optimized(int i, int j, int m, int n)
{
    vector<int> prev(n, 0);

    for (int row = 0; row < m; row++)
    {
        vector<int> curr(n, 1);
        for (int col = 0; col < n; col++)
        {
            if (row == 0 && col == 0)
            {
                curr[col] = 1; // Initilizing base case
                continue;
            }

            int up = prev[col];
            int left = col - 1 < 0 ? 0 : curr[col - 1];

            curr[col] = up + left;
        }

        prev = curr;
    }

    return prev[n - 1];
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));

    /// here we pass the m-1, n-1 because from recursive function we want to get No of unique ways to reach m-1, n-1 from 0 0
    /// so recursion will do the job
    return tryAllWays(m - 1, n - 1, dp);
}

int main()
{
    cout << uniquePaths(3, 7) << endl;
    return 0;
}