#include <bits/stdc++.h>
using namespace std;

string longestCommonSubsequence(string text1, string text2)
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

    int length = dp[n][m];
    string ans(length, ' ');

    int i = n, j = m, k = length - 1;

    while (i > 0 && j > 0)
    {
        // Commoncharacter print
        if (text1[i - 1] == text2[j - 1])
        {
            ans[k] = text1[i - 1];
            k--, i--, j--; // digonally up..
        }
        else{

            if(dp[i-1][j] >= dp[i][j-1]) i--; // go up

            else j--; // go left
        }
    }
    return ans;
}
int main()
{
    string t1 = "abcde", t2 = "aceb";

    cout << longestCommonSubsequence(t1, t2) << endl;  // ace
    return 0;
}