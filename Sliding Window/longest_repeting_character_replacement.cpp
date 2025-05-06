#include <bits/stdc++.h>
using namespace std;

/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.

https://leetcode.com/problems/longest-repeating-character-replacement/description/ 
*/
int characterReplacement(string s, int k)
{

    int n = s.length();
    int i = 0, j = 0, maxLen = 0, maxFreq = 0;

    vector<int> mp(26, 0);
    while (j < n)
    {
        mp[s[j] - 'A']++;

        maxFreq = max(maxFreq, mp[s[j] - 'A']);
        int len = j - i + 1;

        if ((len - maxFreq) <= k)
        {
            maxLen = max(maxLen, len);
            j++;
        }
        else
        {
            while (((j - i + 1) - maxFreq) > k)
            {
                mp[s[i] - 'A']--;

                // Getting maximum frequency after sliding window from left
                int maxF = 0;
                for (int freq : mp)
                    maxF = max(maxF, freq);

                maxFreq = maxF;

                i++;
            }

            maxLen = max(maxLen, j - i + 1);

            j++;
        }
    }
    return maxLen;
}

int main()
{

    return 0;
}