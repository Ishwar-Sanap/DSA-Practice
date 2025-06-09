#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".

*/

int lengthOfLongestPallindromicSubseq(string s1, string s2)
{
    int n = s1.length();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][n];
}
int minInsertions(string s)
{

    int n = s.length();

    int i = 0, j = n - 1;

    while (i < j && s[i] == s[j])
    {
        i++;
        j--;
    }

    // given string is alredy pallindrome
    if (i >= j)
        return 0;

    string s1 = s.substr(i, j - i + 1);
    string s2 = s1;
    reverse(s2.begin(), s2.end());

    int LPS = lengthOfLongestPallindromicSubseq(s1, s2);

    int minInsertions = s1.length() - LPS;

    return minInsertions;
}
int main()
{

    return 0;
}