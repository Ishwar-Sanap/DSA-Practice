#include <bits/stdc++.h>
using namespace std;

/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

https://leetcode.com/problems/wildcard-matching/description/

ex:
    S =  pabcdnn  p =  pa*bcd* --> true
    S =  pabcdnn  p =  **bcd* --> true
    S =  pabcdnn  p =  r**bcd* --> false
    S =  pabcdnn  p =  *bcd*? --> true
*/

bool tryAllWays(int i, int j, string &s, string &p, vector<vector<int>> &dp)
{
    // Base conditions
    // string s is finished and string p is finished
    if (i < 0 && j < 0)
        return true;

    // stirng s have some characters but j is finished
    if (i >= 0 && j < 0)
        return false;

    if (i < 0 && j >= 0)
    {
        // still, some characters in p are exist...
        while (j >= 0)
        {
            if (p[j] == '*')
                j--;

            else
                return false;
        }

        return true;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    bool retVal = false;

    // match
    if (s[i] == p[j])
        retVal = tryAllWays(i - 1, j - 1, s, p, dp);

    // not match
    else if (p[j] == '?') // wild card
    {
        retVal = tryAllWays(i - 1, j - 1, s, p, dp); // matches one characterw with s
    }

    else if (p[j] == '*') // wild card
    {
        retVal = tryAllWays(i, j - 1, s, p, dp); // ignoring the * , and match other characters...

        retVal = retVal || tryAllWays(i - 1, j, s, p, dp); // * compares the one characters from s
    }

    return dp[i][j] = retVal;
}

// Converting memoization into tabulation
bool isMatched_T(string s, string p)
{
    int n1 = s.length(), n2 = p.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    // considering the 1 based indexing to storing results into dp, to avoid -ve indices

    // base conditions

    dp[0][0] = 1;

    for (int i = 1; i <= n1; i++)
    {
        dp[i][0] = 0;
    }

    for (int j = 1; j <= n2; j++)
    {
        bool flag = true;

        for (int k = j; k > 0; k--)
        {
            if (p[k - 1] == '*')
                continue;
            else
            {
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            bool retVal = false;

            // match
            if (s[i - 1] == p[j - 1])
                retVal = dp[i - 1][j - 1];

            // not match
            else if (p[j - 1] == '?')
                retVal = dp[i - 1][j - 1];

            else if (p[j - 1] == '*')
            {
                retVal = dp[i][j - 1] || dp[i - 1][j];
            }

            dp[i][j] = retVal;
        }
    }

    return dp[n1][n2];
}
bool isMatch(string s, string p)
{
    int n1 = s.length(), n2 = p.length();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));

    return tryAllWays(n1 - 1, n2 - 1, s, p, dp);
}

int main()
{
    string s = "pabcdnn", p = "pa*bcd*";

    cout << isMatch(s, p);
    return 0;
}