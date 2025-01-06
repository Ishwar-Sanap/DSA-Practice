#include <bits/stdc++.h>
using namespace std;

// Given a string you need to print longest possible substring that has exactly k unique characters. If there is more than one substring of longest possible length, then print any one of them.

// aabbcc, k = 2  --> 4
// abcdcbcd, k = 3  --> 7
int longestSubstringKUnique(string str, int k)
{
    unordered_map<char, int> mp;
    int n = str.size();

    int i = 0, j = 0;
    int maxLen = 0, currLen = 0;
    while (j < n)
    {
        mp[str[j]]++;

        if (mp.size() < k)
            j++;

        else if (mp.size() >= k)
        {
            while (mp.size() > k)
            {
                mp[str[i]]--;

                if (mp[str[i]] == 0)
                    mp.erase(str[i]);

                i++;
            }

            if (mp.size() == k)
            {
                currLen = j - i + 1;
                maxLen = max(maxLen, currLen);
            }
            j++;
        }
    }

    return maxLen;
}

int main()
{
    // cout<<longestSubstringKUnique("aabbcc",2)<<endl;
    cout << longestSubstringKUnique("abcdcbcd", 3) << endl;
    return 0;
}