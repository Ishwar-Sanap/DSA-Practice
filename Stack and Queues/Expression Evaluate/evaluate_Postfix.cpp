#include <bits/stdc++.h>
using namespace std;

// string exp = "231*+9-"; given postfix
//  output --> -4
// Limitations: 
//The allowed operands are only single-digit operands

bool isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}
int performOperation(int op1, int op2, char ch)
{
    if (ch == '+')
        return op1 + op2;
    else if (ch == '-')
        return op1 - op2;
    else if (ch == '*')
        return op1 * op2;
    else if (ch == '/')
        return op1 / op2;

    return -1;
}
int evaluatePostfix(string exp)
{
    stack<int> st; // will store the digits

    for (char ch : exp)
    {
        if (isDigit(ch))
        {
            st.push(ch - '0');
        }
        else
        {
            // pop top 2 operands from stak
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            int ans = performOperation(op1, op2, ch);
            st.push(ans);
        }
    }

    return st.top();
}

int main()
{
    string exp = "231*+9-";
    return 0;
}