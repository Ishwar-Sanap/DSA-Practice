#include <bits/stdc++.h>
using namespace std;

/*
Example 1:
Input: s = "babad"   // odd length pallindrom
Output: "bab"

Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"  // even length pallindrom
Output: "bb"

https://leetcode.com/problems/longest-palindromic-substring/description/

*/

string expandFromCenter(string &s, int i, int j)
{
    int n = s.length();
    string pallindrome = "";
    while (i >= 0 && j < n)
    {
        if (s[i] == s[j])
        {
            pallindrome = s.substr(i, (j - i) + 1);
            i--;
            j++;
        }
        else
            break;
    }

    return pallindrome;
}
string longestPalindrome(string s)
{

    int n = s.length();
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        // Odd Length Pallindrome
        string palindrome = expandFromCenter(s, i, i);

        if (palindrome.length() > ans.length())
            ans = palindrome;
        else
        {

            if (i > 0)
            {
                // Even length pallindrome
                palindrome = expandFromCenter(s, i - 1, i);

                if (palindrome.length() > ans.length())
                    ans = palindrome;
            }
        }
    }

    return ans;
}
