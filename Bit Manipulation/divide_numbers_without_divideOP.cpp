#include <bits/stdc++.h>
using namespace std;

/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 
would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.
*/
int divide(int dividend, int divisor)
{

    // ex: dividend = 22, divisor = 3
    long ans = 0;
    bool isNegativeRes = 0;

    // Corner cases
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    if (dividend == INT_MIN && divisor == 1)
        return INT_MIN;

    if (dividend < 0 && divisor > 0)
        isNegativeRes = 1;
    else if (dividend >= 0 && divisor < 0)
        isNegativeRes = 1;

    long n = abs((long)dividend), d = abs((long)divisor);

    while (n >= d)
    {
        // Finding the largest multiple of divisor that can be reduced from dividend
        int powerIndx = 0;
        // 3 * 2^powerIndx = equivalents to 3 << powerIndx
        while ((d << powerIndx) <= n)
        {
            powerIndx++;
        }

        powerIndx--; // reduce one extra increment

        ans += (1 << (powerIndx));

        n = n - (d << powerIndx);
    }

    if (isNegativeRes)
        return -1 * ans;
    return ans;
}
int main()
{
    return 0;
}