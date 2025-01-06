#include <bits/stdc++.h>
using namespace std;
// You are given a string s of length n containing only four kinds of characters: 'Q', 'W', 'E', and 'R'.

// A string is said to be balanced if each of its characters appears n / 4 times where n is the length of the string.

// Return the minimum length of the substring that can be replaced with any other string of the same length to make s balanced. If s is already balanced, return 0.

// Input: s = "QWER"
//  Output: 0
//  Explanation: s is already balanced.

// Input s= WEQWWWWR
// Output 3

int balancedString(string s)
{
    int n = s.length();
    int minLen = n;
    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++)
        mp[s[i]]++;

    int k = n / 4;
    // if it is balanced return 0
    if (mp['Q'] == k && mp['E'] == k && mp['R'] == k && mp['W'])
        return 0;

    int i = 0, j = 0;
    while (j < n)
    {
        mp[s[j]]--;

        // check remainng characters aprart from widow can form balanced string
        while (mp['Q'] <= k && mp['E'] <= k && mp['R'] <= k && mp['W'] <= k)
        {
            // window size that needs to remove for making balanced string
            int removeWinSize = (j - i + 1);
            minLen = min(minLen, removeWinSize);

            // Slide window and add those characters that not part of window now
            mp[s[i]]++;
            i++;
        }
        j++;
    }

    return minLen;
}
int main()
{
    cout << balancedString("WEQWWWWR") << endl;
    return 0;
}