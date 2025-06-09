#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
/*
Input: s1 = "ABCDGH", s2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" with a length of 4.

*/
string longestCommonSubstr(string &s1, string &s2)
{
    // your code here

    int n = s1.size(), m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxLen = 0;
    int indx1 = -1, indx2 = -1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // shfiting indices, consider 1 based indexing
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            // Maintain the the maximum length and it's position
            if (dp[i][j] > maxLen)
            {
                indx1 = i;
                indx2 = j;
                maxLen = dp[i][j]; 
            }    
        }
    }

    // maximum length of common substring..
    string ans(maxLen, ' ');
    int k = maxLen - 1;
    // In dp array maximum length position helps you to get started to generate subtring

    while (indx1 > 0 && indx2 > 0)
    {
        if (dp[indx1][indx2] > 0)
        {
            ans[k] = s1[indx1 - 1];
            k--, indx1--, indx2--;
        }
        else
        {
            break;
        }
    }

    return ans;
}
int main()
{

    string s1 = "ABCDGH", s2 = "ACDGHR";
    cout << longestCommonSubstr(s1, s2) << endl;
    return 0;
}