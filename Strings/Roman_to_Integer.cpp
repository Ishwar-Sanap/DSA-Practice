
#include <bits/stdc++.h>
using namespace std;


int getValue(char ch)
{
    if (ch == 'I')
        return 1;
    else if (ch == 'V')
        return 5;
    else if (ch == 'X')
        return 10;
    else if (ch == 'L')
        return 50;
    else if (ch == 'C')
        return 100;
    else if (ch == 'D')
        return 500;
    else if (ch == 'M')
        return 1000;

    return 0;
}
int romanToInt(string s)
{
    // 13-> XIII 14-> XIV 15 -> XV
    int n = s.length(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && getValue(s[i]) > getValue(s[i - 1]))
        {
            // remove previous index addition
            ans -= getValue(s[i - 1]);

            // add difference
            ans += (getValue(s[i]) - getValue(s[i - 1]));
        }

        else
        {
            ans += (getValue(s[i]));
        }
    }

    return ans;
}