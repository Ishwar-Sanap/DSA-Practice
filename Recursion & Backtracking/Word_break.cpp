#include <bits/stdc++.h>
using namespace std;

bool breakIntoAllSegements(int indx, string s, unordered_set<string> &dict, vector<int> &dp)
{
    if (indx == s.length())
        return true;

    if (dp[indx] != -1)
        return dp[indx];

    for (int i = indx; i < s.length(); i++)
    {
        string str = s.substr(indx, i - indx + 1);

        if (dict.find(str) != dict.end())
        {
            cout<<"found word : "<<str<<endl;
            
            // check for remaining part of string if it's return true, then no need to go for further calls..
            bool res = breakIntoAllSegements(i + 1, s, dict, dp);
            dp[indx] = res;

            if (res) return true;
        }
    }

    return  dp[indx] = false;
}
bool wordBreak(string s, vector<string> &wordDict)
{

    int n = s.size();
    vector<int> dp(n + 1, -1);
    unordered_set<string> dict(wordDict.begin(), wordDict.end());

    return breakIntoAllSegements(0, s, dict, dp);
}

int main()
{
    string str = "catsanddog";
    vector<string>Worddict =  {"cats", "cat", "and" , "dog"};

 
    cout << wordBreak(str, Worddict);

    return 0;
}