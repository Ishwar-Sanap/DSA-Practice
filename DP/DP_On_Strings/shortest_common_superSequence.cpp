#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/shortest-common-supersequence/description/

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple
valid strings, return any of them.

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation:

*/
string LongestCommonSubseq_Modified(string s1, string s2)
{
    int n = s1.length(), m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int lcsLength = dp[n][m];

    // AS we want to make commonSuperSequence then it's shortest length is
    int len = (n + m) - lcsLength; // Substracting Common subsequence length from total length

    // Finding the superSequence string..
    string ans(len, ' ');
    int k = len - 1;

    int i = n, j = m;
    while (i > 0 && j > 0)
    {   
        // Common character taking only once
        if (s1[i - 1] == s2[j - 1])
        {
            ans[k] = s1[i - 1];
            k--, i--, j--;
        }
        else
        {
            // At this position in dp, we had come either from left or Up
            if (dp[i][j] == dp[i - 1][j])
            {
                ans[k] = s1[i - 1];
                i--;
                k--;
            }
            else if (dp[i][j] == dp[i][j - 1])
            {
                ans[k] = s2[j - 1];
                j--;
                k--;
            }
        }
    }


    /// Adding remaining characters...
    while (i > 0 && k >= 0)
    {
        ans[k] = s1[i - 1];
        k--;
        i--;
    }

    while (j > 0 && k >= 0)
    {
        ans[k] = s2[j - 1];
        k--;
        j--;
    }

    return ans;
}
string shortestCommonSupersequence(string str1, string str2)
{

    return LongestCommonSubseq_Modified(str1, str2);
}
int main()
{
    string s1 = "bcacaaab", s2 = "bbabaccc";

    return 0;
}