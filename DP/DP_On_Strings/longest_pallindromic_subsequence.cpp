#include <bits/stdc++.h>
using namespace std;

/*----------------------------- Approach 1  --------------------------------------*/

int tryAllWays(int i, int j, string s, vector<vector<int>> &dp)
{
    if (i == j)
        return 1;
    else if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    // match
    if (s[i] == s[j])
        return dp[i][j] = 2 + tryAllWays(i + 1, j - 1, s, dp);

    // not match
    return dp[i][j] = max(tryAllWays(i + 1, j, s, dp), tryAllWays(i, j - 1, s, dp));
}

// Tabulation
int longestPalindromeSubseq_T(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                dp[i][j] = 1;
            else if (i > j)
                dp[i][j] = 0;
            else
            {

                if (s[i] == s[j])
                {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
    }

    return dp[0][n - 1];
}

/*---------------------------------- Approach 2 ------------------------------------------*/
// we can solve this using the same approach of finding longest common subsequences
// we have to take s1 = s, s2 = reverse(s)

int longestCommonSubsequence(string s1, string s2)
{
    int n = s1.size(), m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // match
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            // not match
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}

int longestPalindromeSubseq(string s)
{
    int n = s.size();
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // return tryAllWays(0, n - 1, s, dp);

    string s2 = s;
    reverse(s2.begin(), s2.end());
    
    return longestCommonSubsequence(s, s2);
}

int main()
{
    string str = "abcxdcb";
    cout << longestPalindromeSubseq(str) << endl;
    return 0;
}