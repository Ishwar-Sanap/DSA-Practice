#include <bits/stdc++.h>
using namespace std;
/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

s: "[()[]{}]" true; 
s : "(})"
*/
bool isValidPair(char top, char curr)
{
    if ((top == '(' && curr == ')') || (top == '[' && curr == ']') || (top == '{' && curr == '}'))
        return true;

    return false;
}
bool isValid(string s)
{
    stack<char> st;

    for (char ch : s)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }
        else
        {

            if (st.empty())
                return false; // closing bracket and empty stack :(

            if (isValidPair(st.top(), ch)) //(){} valid pairs
                st.pop();
            
            else  // "(})"  Not valid pair
                return false;
        }
    }

    return st.empty();
}

int main()
{

    return 0;
}