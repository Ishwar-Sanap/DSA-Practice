#include <bits/stdc++.h>
using namespace std;

// Infix : a + b (operand operator operand)
// postfix : ab+ (operand operand operator)

// Input: s = "a+b*(c^d-e)^(f+g*h)-i"
// Output: abcd^e-fgh*+^*+i-

// Input :  h^m^q^(7-4)
// Output : hm^q^74-^

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

string infixToPostfix(string &str)
{
    stack<char> st;
    string res = "";

    for (char ch : str)
    {
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
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            // remove all operator until we not got opening bracket in top of stack
            while (!st.empty() && st.top() != '(')
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

    return res;
}

int main()
{

    string str = "a+b*(c^d-e)^(f+g*h)-i";
    cout << infixToPostfix(str) << endl;

    return 0;
}