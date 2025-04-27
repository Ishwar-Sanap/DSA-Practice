#include <bits/stdc++.h>
using namespace std;

/*
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

https://leetcode.com/problems/sort-characters-by-frequency/description/ 
*/
static bool comp(pair<char, int> &it1, pair<char, int> &it2)
{
    // sort by frequencies in descending order..
    return it1.second > it2.second;
}
string frequencySort(string s)
{

    vector<pair<char, int>> freq(128, {0, 0});
    for (char ch : s)
    {
        int cnt = freq[ch].second;
        freq[ch] = {ch, cnt + 1};
    }
    string ans = "";

    sort(freq.begin(), freq.end(), comp);

    for (auto &it : freq)
    {
        for (int i = 1; i <= it.second; i++)
            ans += it.first;
    }
    return ans;
}
int main()
{

    return 0;
}