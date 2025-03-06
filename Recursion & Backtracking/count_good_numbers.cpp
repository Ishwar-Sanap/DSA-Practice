#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
/*
https://leetcode.com/problems/count-good-numbers/description/

*/

/* Recursion Approach : */
// T.C O(n) --> TLE since n is very large
bool isPrimeDigit(int digit)
{
    // only we have to check single digit prime numbers
    if (digit == 2 || digit == 3 || digit == 5 || digit == 7)
        return true;

    return false;
}
int solve(long long idx, vector<int> &dp, long long n)
{
    if (idx == n)
    {
        return 1;
    }

    if (dp[idx] != -1)
        return dp[idx];

    int cnt = 0;
    for (int i = 0; i <= 9; i++)
    {
        if (idx % 2 == 0)
        {
            if (i % 2 == 0)
            {
                // integer overflow happens when, we add cnt to function call.. so perform modulo
                cnt = (cnt + solve(idx + 1, dp, n)) % mod;
            }
        }
        else
        {
            if (isPrimeDigit(i))
            {
                // integer overflow happens when, we add cnt to function call.. so perform modulo
                cnt = (cnt + solve(idx + 1, dp, n)) % mod;
            }
        }
    }

    return dp[idx] = cnt;
}



long long getPower(long long x, long long y) // power = x ^ y
{
    if (y == 0)
        return 1;

    long long halfPow = 1;

    halfPow = getPower(x, y / 2);

    halfPow = (halfPow * halfPow) % mod; // make the squre , (x ^ y) * (x ^ y)

    if (y % 2 != 0) // y is odd, multiply x also
        halfPow = (x * halfPow) % mod;

    return halfPow;
}

int countGoodNumbers(long long n)
{

    // vector<int> dp(n + 1, -1);

    // return solve(0, dp, n);

    /*
        ex; n = 2

        even numbers --> {0,2,4,6,8}
        prime number --> {2,3,5,7}
        - -
        at empty space at 0th index we have 5 choice to place even numbers
        at empty space at 1st index we have 4 choices to place prime numbers

        so total good numbers ==> 5 * 4 = 20

        ex : n = 3
        - - -
        5 * 4 * 5 ==> 100
    */

    int ans = 0;
    long long cnt = n / 2;

    // if given number 'n' is even
    if ((n & 1) == 0)
    {
        ans = (getPower(5, cnt) * getPower(4, cnt)) % mod;
        return ans;
    }
    else
    {
        ans = (getPower(5, cnt + 1) * getPower(4, cnt)) % mod;
        return ans;
    }
}

int main()
{

    cout << countGoodNumbers(3) << endl;
    // cout << getPower(10, 40) << endl;
    return 0;
}