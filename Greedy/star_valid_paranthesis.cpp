#include <bits/stdc++.h>
using namespace std;

/*

https://leetcode.com/problems/valid-parenthesis-string/

//"((*))()*" true
// ((*))(  false
*/
bool checkValidString(string s)
{

    int openCnt = 0, closeCnt = 0;
    int n = s.length();

    int j = n - 1;
    // travesing the string in both direction simaltaneoulsy
    for (int i = 0; i < n; i++, j--)
    {
        // it will ensure the ) not exceeded the ( and *
        if (s[i] == '(' || s[i] == '*')
            openCnt++;
        else
            openCnt--;

        // ensuring the ( bracket not exceeded the ) and *
        if (s[j] == ')' || s[j] == '*')
            closeCnt++;
        else
            closeCnt--;

        if (openCnt < 0 || closeCnt < 0)
            return false;
    }

    return true;
}

int main()
{

    return 0;
}