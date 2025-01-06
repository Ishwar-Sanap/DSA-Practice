#include <bits/stdc++.h>
using namespace std;
/*
Given a string S consisting of N characters and a positive
integer K, the task is to count the number of substrings
having at least K distinct characters.

// abccda
// output 8
abc
abcc
abccd
abccda
4 subarray from a
bccd
bccda
2 subarray from b
ccda
1 subarray from c
cda
1 subarray from next c
Total ==> 8

abcca k = 4
output ==> 0
*/

int getCntAtLeastKDistinct(string str, int k)
{
    int i = 0, j = 0, n = str.length();
    int cnt = 0;
    unordered_map<char, int> mp;
    while (j < n)
    {
        mp[str[j]]++;

        if (mp.size() < k)
            j++;

        else
        {
            while (mp.size() >= k)
            {
                cnt += n - j; // we can make these no subarray

                mp[str[i]]--;

                if (mp[str[i]] == 0)
                    mp.erase(str[i]);
                i++;
            }

            j++;
        }
    }
    return cnt;
}
int main()
{
    cout << getCntAtLeastKDistinct("abccdaf", 3) << endl;
    cout << getCntAtLeastKDistinct("abccda", 3) << endl;
    return 0;
}