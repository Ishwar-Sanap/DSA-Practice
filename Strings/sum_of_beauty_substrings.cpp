#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/
/*
The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

Example 1:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
Example 2:

Input: s = "aabcbaa"
Output: 17

*/
int beautySum(string s)
{

    int ans = 0, n = s.length();
    for (int i = 0; i < n; i++)
    {
        vector<int> freqs(26, 0);
        for (int j = i; j < n; j++)
        {
            int maxF = 0, minF = n;
            freqs[s[j] - 'a']++;

            for (int freq : freqs)
            {
                maxF = max(maxF, freq);
                minF = freq == 0 ? minF : min(minF, freq);
            }

            ans += (maxF - minF);
        }
    }

    return ans;
}
