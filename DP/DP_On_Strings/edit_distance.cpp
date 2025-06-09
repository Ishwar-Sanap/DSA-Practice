#include <bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/edit-distance/

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

op1 : Insert a character
op2 : Delete a character
op3 : Replace a character

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

// In this memoization approach we have written base conditons at -ve indices,
// but converting this approach into tabulation we can't use the -ve indices at base case..
int tryAllWays(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
{
    // word1 exuasted
    if (i < 0)
        return j + 1; // no of remaining characters in word2 we have to inserted in word1 to make equal

    // word2 exusted
    if (j < 0)
        return i + 1; // no of remaining characters from word1 we have to delete, to make equal

    if (dp[i][j] != -1)
        return dp[i][j];

    // Match characters
    if (word1[i] == word2[j])
        return dp[i][j] = 0 + tryAllWays(i - 1, j - 1, word1, word2, dp);
    else
    { // not match

        int op1 = 1 + tryAllWays(i, j - 1, word1, word2, dp);     // hypothetically inserted character in word1 to match with word2 j character
        int op2 = 1 + tryAllWays(i - 1, j, word1, word2, dp);     // Hypothetically deleted the ith character from word1
        int op3 = 1 + tryAllWays(i - 1, j - 1, word1, word2, dp); // Hypothetically replaced character

        return dp[i][j] = min({op1, op2, op3});
    }
}

// Memoization with shifted indices.., i.e consider 1 based indexing
int tryAllWays_shifted(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
{
    // word1 exuasted
    if (i == 0)
        return j; // no of remaining characters in word2 we have to inserted in word1 to make equal

    // word2 exusted
    if (j == 0)
        return i; // no of remaining characters from word1 we have to delete, to make equal

    if (dp[i][j] != -1)
        return dp[i][j];

    // Match characters
    if (word1[i - 1] == word2[j - 1]) // since we have call function as (n1, n2) we have to use 1 less index to compare
        return dp[i][j] = 0 + tryAllWays_shifted(i - 1, j - 1, word1, word2, dp);
    else
    { // not match

        int op1 = 1 + tryAllWays_shifted(i, j - 1, word1, word2, dp);     // hypothetically inserted character in word1 to match with word2 j character
        int op2 = 1 + tryAllWays_shifted(i - 1, j, word1, word2, dp);     // Hypothetically deleted the ith character from word1
        int op3 = 1 + tryAllWays_shifted(i - 1, j - 1, word1, word2, dp); // Hypothetically replaced character

        return dp[i][j] = min({op1, op2, op3});
    }
}
// Tabulation
int minDistance_T(string word1, string word2)
{
    int n1 = word1.length(), n2 = word2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    // j --> 0 i.e word2 exusted
    for (int i = 0; i <= n1; i++)
        dp[i][0] = i;

    // i--> 0 i.e word1 exuasted
    for (int j = 0; j <= n2; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {

                int op1 = 1 + dp[i][j - 1];
                int op2 = 1 + dp[i - 1][j];
                int op3 = 1 + dp[i - 1][j - 1];

                dp[i][j] = min({op1, op2, op3});
            }
        }
    }

    return dp[n1][n2];
}
int minDistance(string word1, string word2)
{
    int n1 = word1.length(), n2 = word2.length();
    // vector<vector<int>> dp(n1, vector<int>(n2, -1));
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

    // return tryAllWays(n1 - 1, n2 - 1, word1, word2, dp);
    return tryAllWays_shifted(n1, n2, word1, word2, dp);
}

int main()
{
    string s1 = "intention", s2 = "execution";

    cout << minDistance(s1, s2) << endl;

    return 0;
}