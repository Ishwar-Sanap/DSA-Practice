#include <bits/stdc++.h>
using namespace std;

/*-

https://leetcode.com/problems/longest-string-chain/description/


Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].


*/

static bool comp(string &a, string &b)
{
    return b.length() > a.length();
}
bool isPredressor(string wordA, string wordB)
{
    // function to check wheter the wordA is predessor of wordB or not
    int n1 = wordA.length(), n2 = wordB.length();
    if (n1 == n2 || n1 > n2 || n2 - n1 > 1)
        return false;

    int needToInsert = 0;

    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (wordA[i] != wordB[j])
        {
            needToInsert++;
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }

    return needToInsert == 1 || i == n1 ? true : false;
}

int longestStrChain(vector<string> &words)
{

    // To select length of longest string chain subsequence
    // we have to use indx and previous indx to chek isPredressor or not

    // first we have to sort the words based on the size in incresing order
    // We required the longest sequences not subsequecs so sequeces can be start from any words..
    // so sortting the words based on the size in incresing order..
    sort(words.begin(), words.end(), comp);

    // for(string st : words) cout<<st<<" ";

    int n = words.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int prevIndx = i - 1; prevIndx >= -1; prevIndx--)
        {
            int pick = 0, notPick = 0;
            if (prevIndx == -1 || isPredressor(words[prevIndx], words[i]))
            {
                // index shifting to avoid the -ve prevIndx
                pick = 1 + dp[i + 1][i + 1];
            }

            notPick = dp[i + 1][prevIndx + 1];

            dp[i][prevIndx + 1] = max(pick, notPick);
        }
    }

    return dp[0][-1 + 1];
}
int main()
{
    return 0;
}