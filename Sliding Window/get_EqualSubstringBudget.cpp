#include <bits/stdc++.h>
using namespace std;
/*
You are given two strings s and t of the same length and an integer maxCost.

You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).

Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.

Input: s = "abcd", t = "bcdf", maxCost = 3
Output: 3
Explanation: "abc" of s can change to "bcd".
That costs 3, so the maximum length is 3.

*/
int equalSubstring(string s, string t, int maxCost)
{
    // efgabcd   //abcbcdf

    int i = 0, j = 0, n = s.length();
    int currCost = 0, maxLen = 0;

    // Length of maximum size subarray whose sum is less than or equal to Target

    while (j < n)
    {
        currCost += abs(s[j] - t[j]);

        if (currCost <= maxCost)
        {
            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        else
        {
            while (currCost > maxCost)
            {
                currCost -= abs(s[i] - t[i]);
                i++;
            }
            j++;
        }
    }

    return maxLen;
}

int main()
{

    return 0;
}
