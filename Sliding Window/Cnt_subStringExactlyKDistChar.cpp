#include <bits/stdc++.h>
using namespace std;
/*
Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that has exactly k distinct characters.

Input: abc, k = 2
Output: 2
Possible substrings are {“ab”, “bc”}

Input: aba, k = 2
Output: 3
Possible substrings are {“ab”, “ba”, “aba”}

Input: aa, k = 1
Output: 3
Possible substrings are {“a”, “a”, “aa”}



abc
at most k distinct
a ab
b bc
c

Logic Using at lest k distinct
abc
at lest k distinct 2
n1 = 3 => ab bc abc

at lest k+1 disticnt
n2 = 1 => abc

ExactDist = n1 - n2 = 3-1 = 2


Logic Using at most k distinct
abc
at most k distinct 2
n1 = 5 ==> a b c ab bc

at most k-1 dist  1
n2 = 3 ==> a b c

ExactDist = n1 - n2 = 5-3 = 2

*/

int getCntAtMostKDistinct(string str, int k)
{
    int i = 0, j = 0, n = str.length();
    int cnt = 0;
    unordered_map<char, int> mp;
    while (j < n)
    {
        mp[str[j]]++;

        while (mp.size() > k)
        {
            mp[str[i]]--;

            if (mp[str[i]] == 0)
                mp.erase(str[i]);
            i++;
        }

        cnt += j - i + 1;
        j++;
    }
    return cnt;
}
int main()
{
    string str = "abc";
    int k = 2;

    int subStringWithKDist = getCntAtMostKDistinct(str, k) - getCntAtMostKDistinct(str, k - 1);
    cout << subStringWithKDist << endl;

    return 0;
}