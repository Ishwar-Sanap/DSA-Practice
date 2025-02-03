#include <bits/stdc++.h>
using namespace std;

// Infix : a + b (operand operator operand)
// prefix : +ab (operator operand operand )

// Input: A * B + C / D
// Output: + * A B/ C D

// Input: (A – B/C) * (A/K-L)
// Output: *-A/BC-/AKL

// T.C --> O(N) + O(N) --> O(2N) --> O(N)
// S.C. --> O(N)
int getPrecedance(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

bool isOperand(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        return true;

    return false;
}

bool isOperator(char ch)
{
    if (ch == '^' || ch == '/' || ch == '*' || ch == '-' || ch == '+')
        return true;

    return false;
}

string infixToPrefix(string &str)
{
    int n = str.length();
    stack<char> st;
    string res = "";

    // Move from Right to left
    for (int i = n-1; i>= 0; i--)
    {
        char ch = str[i];

        if (isOperand(ch))
        {
            res.push_back(ch);
        }
        else if (isOperator(ch))
        {
            while (!st.empty() && getPrecedance(st.top()) >= getPrecedance(ch))
            {
                res.push_back(st.top()); // add higher precedence operator to resut
                st.pop();
            }

            st.push(ch); // store operators in stack
        }
        else if (ch == ')') // since we are travesring from right to left 
        {
            st.push(ch);
        }
        else if (ch == '(')
        {
            // remove all operator until we not got closing bracket in top of stack
            while (!st.empty() && st.top() != ')')
            {
                res.push_back(st.top()); // add higher precedence operator to result
                st.pop();
            }

            // pop ( remaining opening bracket from stack
            st.pop();
        }
    }

    // remove remaining operator from stack and add to resuts
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    reverse(res.begin(), res.end());
    return res;
}

int main()
{

    string str = "(A-B/C)*(A/K-L)";
    cout << infixToPrefix(str) << endl;

    return 0;
}