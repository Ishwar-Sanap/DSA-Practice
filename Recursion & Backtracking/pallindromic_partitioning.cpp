#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/palindrome-partitioning/description/
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
*/
bool isPallindrome(string &str)
{
    int i = 0, j = str.length() - 1;
    while (i <= j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }

    return true;
}
void tryAllPossibleWays(int indx, string &s, vector<string> &temp, vector<vector<string>> &res)
{

    if(indx == s.length())
    {
        res.push_back(temp);
        return;
    }

    // try to make partition at every index...
    for (int i = indx; i < s.length(); i++)
    {
        string str = s.substr(indx, i- indx + 1);
        // cout<<str<<endl;
        if (isPallindrome(str))
        {
            temp.push_back(str);
            tryAllPossibleWays(i+1,s,temp,res);
            temp.pop_back(); // backtrack.
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> temp;

    tryAllPossibleWays(0,s,temp,res);

    return res;
}

int main()
{
    vector<vector<string>> res =  partition("aab");


    return 0;
}