#include <bits/stdc++.h>
using namespace std;
/*
Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]
*/
vector<string> commonChars(vector<string> &words)
{

    int n = words.size();
    vector<vector<int>> arrFreq;
    vector<string> res;
    for (string word : words)
    {
        vector<int> freq(26, 0);

        for (char ch : word)
            freq[ch - 'a']++;

        arrFreq.push_back(freq);
    }

    for (int i = 0; i < 26; i++)
    {
        int minFreq = 101;
        for (int j = 0; j < arrFreq.size(); j++)
        {
            minFreq = min(minFreq, arrFreq[j][i]);
        }
        arrFreq[0][i] = minFreq;

        for (int cnt = 0; cnt < arrFreq[0][i]; cnt++)
        {
            string str = "";
            str += char('a' + i);
            res.push_back(str);
        }
    }
    return res;
}