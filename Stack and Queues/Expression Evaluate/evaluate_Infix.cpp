#include <bits/stdc++.h>
using namespace std;

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

int evaluateInfix(string exp)
{
    stack<int> operands; // store numbers
    stack<char> operators; // store operators

    int n = exp.size();
    int i = 0;
    while (i < n)
    {
        if (exp[i] == ' ')
        {
            i++;
            continue;
        }

        if (isDigit(exp[i]))
        {
            // store all digits of number
            int num = 0;
            while (i < n && isDigit(exp[i]))
            {
                num = (num * 10) + (exp[i] - '0');
                i++;
            }

            /// push number into operands stack.
            operands.push(num);
            
            // As i is alredy incremented in above loop just continue don't increment i twice
            continue;
        }
        else if (exp[i] == '(')
            operators.push(exp[i]);

        else if (exp[i] == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                int num2 = operands.top();
                operands.pop();
                int num1 = operands.top();
                operands.pop();

                int res = performOperation(num1, num2, operators.top());
                operands.push(res);

                operators.pop();
            }

            operators.pop(); // pop opening bracket.
        }
        else // current is operator
        {
            while (!operators.empty() && getPrecedance(operators.top()) >= getPrecedance(exp[i]))
            {
                int num2 = operands.top();
                operands.pop();
                int num1 = operands.top();
                operands.pop();

                int res = performOperation(num1, num2, operators.top());
                operands.push(res);

                operators.pop();
            }
            
            // push current operator to stack.
            operators.push(exp[i]);
        }

        i++;
    }

    while (!operators.empty())
    {
        int num2 = operands.top();
        operands.pop();
        int num1 = operands.top();
        operands.pop();

        int res = performOperation(num1, num2, operators.top());
        operands.push(res);

        operators.pop();
    }

    return operands.top();
}

int main()
{
    string exp = "100 * ( 2 + 12 ) / 14";

    cout << evaluateInfix(exp) << endl;
    return 0;
}