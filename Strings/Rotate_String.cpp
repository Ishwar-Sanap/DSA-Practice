#include <bits/stdc++.h>
using namespace std;

/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.

s  : ababcde // goal : abcdeab true
s : defdefdefabcabc // goal : defdefabcabcdef true
Input: s = "abcde", goal = "abced"
Output: false

*/
bool rotateString(string s, string goal)
{

    int n1 = s.length(), n2 = goal.length();

    if (n1 != n2)
        return false;

    s = s + s;
    int i = 0, j = 0;
    while (i < 2 * n1)
    {
        int curr = i, j = 0;
        while (curr < 2 * n1 && j < n1 && s[curr++] == goal[j++])

            if (j == n1)
                return true;
        i++;
    }

    return false;
}

int main()
{

    return 0;
}