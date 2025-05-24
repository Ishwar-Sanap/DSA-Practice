#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/climbing-stairs/
/*
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/
// Space optimized, similar to the fibonacii number
int climbStairs(int n)
{

    if (n <= 1)
        return n;

    int prev1 = 2;
    int prev2 = 1;

    for (int i = 3; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{

    return 0;
}