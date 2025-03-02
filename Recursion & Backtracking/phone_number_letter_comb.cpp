#include <bits/stdc++.h>
using namespace std;

void tryAllPossibleWays(int indx, string &digits, string &temp, vector<string> &mapping, vector<string> &ans)
{

    if (indx == digits.length() && temp.size() > 0)
    {
        ans.push_back(temp);
        return;
    }

    int num = digits[indx] - '0';
    string comb = mapping[num - 2];

    for (int i = 0; i < comb.length(); i++)
    {
        temp.push_back(comb[i]);
        tryAllPossibleWays(indx + 1, digits, temp, mapping, ans);
        temp.pop_back(); // backtrack
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    if (digits.length() == 0)
        return ans;

    string temp = "";
    vector<string> mapping = {"abc", "def",
                              "ghi", "jkl", "mno",
                              "pqrs", "tuv", "wxyz"};

    tryAllPossibleWays(0, digits, temp, mapping, ans);

    return ans;
}

int main()
{
    string digits = "234";
    vector<string> ans = letterCombinations(digits);

    for (string str : ans)
    {
        cout << str << endl;
    }

    return 0;
}