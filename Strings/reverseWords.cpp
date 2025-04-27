#include <bits/stdc++.h>
using namespace std;

/*
Input: s = "  hello     world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
*/
string reverseWords(string s)
{
    stringstream ssObj(s);

    vector<string> tokens;
    string tk = "";
    /*
     When you use the extraction operator (>>) with stringstream obj, it automatically extracts the next word (token)
    separated by whitespace (spaces, tabs, or newlines).
    */
    while (ssObj >> tk)
    {
        tokens.push_back(tk);
    }

    string ans = "";
    for (int i = tokens.size() - 1; i > 0; i--)
    {
        ans += tokens[i] + " ";
    }

    ans += tokens[0];

    return ans;
}

int main()
{
    string s = "  hello     world  ";
    reverseWords(s);
    return 0;
}