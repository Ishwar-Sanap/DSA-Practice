#include <bits/stdc++.h>
using namespace std;

/*
Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 
Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

s = aabccabc
Output = 18
*/

int main()
{

    return 0;
}

bool isAll3Exist(vector<int> &freq)
{
    if (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
        return true;
    return false;
}
int numberOfSubstrings(string s)
{

    vector<int> freq(3, 0);
    int n = s.length(), i = 0, j = 0;
    int cnt = 0;
    while (j < n)
    {
        freq[s[j] - 'a']++;

        if (!isAll3Exist(freq))
        {
            j++;
        }
        else
        {
            while (isAll3Exist(freq))
            {
                cnt += (n - j); // from right till j all are valid

                freq[s[i] - 'a']--;
                i++;
            }
            j++;
        }
    }
    return cnt;
}