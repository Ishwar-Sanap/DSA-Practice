#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
*/
string removeKdigits(string num, int k)
{

    int n = num.size();
    if (n == k)
        return "0";

    // Smallest number is only possible when at starting numbers are small..

    // The basic idea is to maintain monotonically increasing stack
    // so as we want to make smallest number we store smallest elemetn

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int curr = num[i] - '0';

        while (!st.empty() && k > 0 && st.top() > curr)
        {
            st.pop();
            k--;
        }

        st.push(curr);
    }

    if (st.empty())
        return "0";

    // nums --> 1 2 3 4 , k = 2
    while (!st.empty() && k > 0)
    {
        st.pop();
        k--;
    }

    string temp = "";
    while (!st.empty())
    {

        temp.push_back(st.top() + '0');
        st.pop();
    }

    reverse(temp.begin(), temp.end());
    // if there are leding 0 you have to skip that,
    int i = 0;
    while (i < temp.size() && temp[i] == '0')
    {
        i++;
    }

    return i == temp.size() ? "0" : temp.substr(i);
}