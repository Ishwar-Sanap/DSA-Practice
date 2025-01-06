#include <bits/stdc++.h>
using namespace std;

/*
Given two strings s and t of lengths m and n respectively, return the minimum window
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.
Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Input  : s = "aa", t = "aa"
Output : aa

- The crucs of this problem is to identify how we can effiecienlty check that, for any taken substring of s whether the all element are Part of string t or not.
- This can be checked using the ++ and -- concept, for ex: s = acba  t = baa
if we store all 't' elements and their frequencies in map and traverese s and reduce frequency of those character while traversing s. , If at j = 0 index, we reduce frequency of a from map, now freq[a] = 1 , freq >= 0 means we have found one matching element in s , so increment count++
When count reaches to size of t, then we say that we have found the substring from I - j has all equal element from t
*/
string minWindow(string s, string t)
{

    unordered_map<char, int> mp;
    for (char ch : t)
        mp[ch]++;

    int m = s.length(), n = t.length();
    int i = 0, j = 0;
    int cnt = 0, minLen = INT_MAX, sIndex = -1;
    while (j < m)
    {
        mp[s[j]]--;
        if (mp[s[j]] >= 0) // charter found in both s and t
            cnt++;

        if (cnt == n) // all chracters from t found in s
        {
            // Get the length of minimum window
            if ((j - i + 1) < minLen)
            {
                minLen = (j - i + 1);
                sIndex = i;
            }

            // shrik window and try to get minimum ans
            while (i <= j && cnt == n)
            {
                // Increse count of that character that means, we remove that
                // from current window, we need that charcter again in furthrer window to have all characters of t in s
                mp[s[i]]++;

                if (mp[s[i]] > 0)
                    cnt--;
                else
                { // calculate minimum possible ans from shirked window
                    if ((j - i) < minLen)
                    {
                        minLen = (j - i);
                        sIndex = i + 1;
                    }
                }

                i++;
            }
        }

        j++;
    }

    return sIndex == -1 ? "" : s.substr(sIndex, minLen);
}

int main()
{

    return 0;
}