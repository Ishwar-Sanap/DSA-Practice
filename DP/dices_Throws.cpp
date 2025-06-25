#include <bits/stdc++.h>
using namespace std;

/*
Given n dice each with m faces. Find the number of ways to get sum x which is the summation of values on each face when all the dice are thrown.

Example:

Input: m = 6, n = 3, x = 12
Output: 25
Explanation: There are 25 total ways to get the Sum 12 using 3 dices with faces from 1 to 6.

https://www.geeksforgeeks.org/problems/dice-throw5349/1?page=1&sortBy=submissions
*/

class Solution
{
public:
    long long dp[51][51];
    int solve(int m, int n, int sum)
    {

        if (sum == 0 && n == 0)
            return 1;
            // if dices becomes 0 no ways to make sum
        if (n == 0 || sum <= 0)
            return 0;

        if (dp[n][sum] != -1)
            return dp[n][sum];
            long long cnt = 0;
            
        // for each dice possible faces try all values
        for (int i = 1; i <= m; i++)
        {
            cnt += solve(m, n - 1, sum - i);
        }

        return dp[n][sum] = cnt;
    }
    int noOfWays(int m, int n, int x)
    {
        // code here
        // cout<<sizeof(dp)<<endl;
        memset(dp, -1, sizeof(dp));
        return solve(m, n, x);
    }
};

int main()
{

    return 0;
}