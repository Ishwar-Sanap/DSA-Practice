#include <bits/stdc++.h>
using namespace std;

/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.
https://leetcode.com/problems/distinct-subsequences/description/


Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag

*/

int tryAllWays(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    // t is completed matched..
    if (j < 0)
        return 1;

    if (i < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int pick = 0, notPick = 0;

    // match
    if (s[i] == t[j])
        pick = tryAllWays(i - 1, j - 1, s, t, dp);

    // not match
    notPick = tryAllWays(i - 1, j, s, t, dp);

    return dp[i][j] = pick + notPick;
}

int numDistinct_Tabulation(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // For managing the -ve indices of the base case we have to use the shifting of indices

    // DP[0][0] --> base conditions
    for (int i = 0; i <= n; i++)    // 0th column should be always 1
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int pick = 0, notPick = 0;
            if (s[i - 1] == t[j - 1])
                pick = dp[i - 1][j - 1];

            notPick = dp[i - 1][j];

            dp[i][j] = pick + notPick;
        }
    }
    return dp[n][m];
}

int numDistinctOP(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<int> prevRow(m + 1, 0);
    vector<int> currRow(m + 1, 0);

    // For managing the -ve indices of the base case we have to use the shifting of indices

    // DP[0][0] --> base conditions

    currRow[0] =  prevRow[0] = 1; // every time 0th element must be 1 so setting currRow[0] as 1

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int pick = 0, notPick = 0;
            if (s[i - 1] == t[j - 1])
                pick = prevRow[j - 1];

            notPick = prevRow[j];

            currRow[j] = pick + notPick;
        }
        prevRow = currRow;
    }
    return prevRow[m];
}
int numDistinct(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return tryAllWays(n - 1, m - 1, s, t, dp);
}
int main()
{
    string s = "babgbag", t = "bag";
    cout << numDistinct_Tabulation(s, t) << endl;
    return 0;
}