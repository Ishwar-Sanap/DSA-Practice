#include <bits/stdc++.h>
using namespace std;
/*
Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
https://leetcode.com/problems/longest-common-subsequence/

*/

// Recursive approch :  T.C --> O(2^n * 2^m),  S.C --> O(n) + O(m)
int tryAllWays(int indx1, int indx2, string &text1, string &text2)
{
    if (indx1 < 0 || indx2 < 0)
        return 0;

    // Counting the no of characteres from the subsequeces that are equal
    if (text1[indx1] == text2[indx2]) // matching characters found increment LCS length
        return 1 + tryAllWays(indx1 - 1, indx2 - 1, text1, text2);

    return 0 + max(tryAllWays(indx1 - 1, indx2, text1, text2), tryAllWays(indx1, indx2 - 1, text1, text2)); // returning the maximum length subsequence
}

// memoization of recursive solution:  T.C --> O(n*m),  S.C --> O(n) + O(m) stack space,  O(n*m) extra dp array
int tryAllWays(int indx1, int indx2, string &text1, string &text2, vector<vector<int>> &dp)
{
    if (indx1 < 0 || indx2 < 0)
        return 0;

    if (dp[indx1][indx2] != -1)
        return dp[indx1][indx2];

    // Counting the no of characteres from the subsequeces that are equal
    if (text1[indx1] == text2[indx2])
        return dp[indx1][indx2] = 1 + tryAllWays(indx1 - 1, indx2 - 1, text1, text2, dp);

    return dp[indx1][indx2] = 0 + max(tryAllWays(indx1 - 1, indx2, text1, text2, dp), tryAllWays(indx1, indx2 - 1, text1, text2, dp)); // returning the maximum length subsequence
}

// Tabulation  T.C --> O(n*m),  S.C -->  O(n*m) extra dp array
int longestCommonSubsequence_T(string text1, string text2)
{
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // we can't write the base conditions on -1 indices so we have to shift the indices..
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1]; // matcing character found.. increment LCS length

            else
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}

// T.C --> O(n*m),  S.C -->  O(m) extra dp array
int longestCommonSubsequence_OP(string text1, string text2)
{
    int n = text1.size(), m = text2.size();

    vector<int> prevRow(m + 1, 0);
    vector<int> currRow(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // we can't write the base conditions on -1 indices so we have to shift the indices..
            if (text1[i - 1] == text2[j - 1])
                currRow[j] = 1 + prevRow[j - 1]; // matcing character found..

            else
                currRow[j] = 0 + max(prevRow[j], currRow[j - 1]);
        }

        prevRow = currRow;
    }

    return prevRow[m];
}
int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size(), m = text2.size();
    // return tryAllWays(n - 1, m - 1, text1, text2);

    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // return tryAllWays(n - 1, m - 1, text1, text2, dp);

    return longestCommonSubsequence_T(text1, text2);
}

int main()
{
    string t1 = "abcde", t2 = "abc";

    cout << longestCommonSubsequence(t1, t2) << endl;
    return 0;
}