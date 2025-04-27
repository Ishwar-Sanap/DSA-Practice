#include <bits/stdc++.h>
using namespace std;

/*
Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

https://leetcode.com/problems/remove-outermost-parentheses/description/ 
*/
string removeOuterParentheses(string s)
{
    string ans = "";
    int i = 0, n = s.length(), opCnt = 0;

    while (i < n)
    {
        if (s[i] == '(')
        {
            opCnt++;

            if (opCnt > 1)
                ans += s[i];
        }
        else
        {

            if (opCnt > 1)
                ans += s[i];

            opCnt--;
        }

        i++;
    }

    return ans;
}