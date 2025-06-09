#include <bits/stdc++.h>
using namespace std;

/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.
https://leetcode.com/problems/delete-operation-for-two-strings/description/

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
*/
int lengthOfLongestSubseq(string s1, string s2)
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

    return dp[n][m];
}
int minDistance(string word1, string word2)
{
    int lenLCS = lengthOfLongestSubseq(word1, word2);
    int n1 = word1.length(), n2 = word2.length();

    int minD = (n1 - lenLCS) + (n2 - lenLCS);

    return minD;
}
int main()
{

    return 0;
}
