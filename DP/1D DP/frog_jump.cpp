#include <bits/stdc++.h>
using namespace std;

/*
https://www.geeksforgeeks.org/problems/geek-jump/1

Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts
from the first stair and wants to reach the top. From any stair i, the frog has two options: it can
either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in
 height between the two stairs. Determine the minimum total cost required for the frog to reach the top
*/
// Recursion Approach
int tryAllWays_Recursive(int indx, int n, vector<int> &height)
{
    if (indx == 0)
        return 0;

    int c1 = abs(height[indx] - height[indx - 1]) + tryAllWays_Recursive(indx - 1, n, height);

    int c2 = INT_MAX;
    if (indx > 1)
        c2 = abs(height[indx] - height[indx - 2]) + tryAllWays_Recursive(indx - 2, n, height);

    return min(c1, c2);
}

// Memoization
int tryAllWays(int indx, int n, vector<int> &height, vector<int> &dp)
{
    if (indx == 0)
        return 0;

    if (dp[indx] != -1)
        return dp[indx];

    int c1 = abs(height[indx] - height[indx - 1]) + tryAllWays(indx - 1, n, height, dp);

    int c2 = INT_MAX;
    if (indx > 1)
        c2 = abs(height[indx] - height[indx - 2]) + tryAllWays(indx - 2, n, height, dp);

    return dp[indx] = min(c1, c2);
}

// tabulation
int minCost_T(vector<int> &height)
{
    int n = height.size();
    if (n <= 1)
        return 0;

    vector<int> dp(n + 1, -1);
    // assigning values using base cases
    dp[0] = 0;
    dp[1] = abs(height[0] - height[1]);

    for (int i = 2; i < n; i++)
    {
        int c1 = abs(height[i] - height[i - 1]) + dp[i - 1];
        int c2 = abs(height[i] - height[i - 2]) + dp[i - 2];
        dp[i] = min(c1, c2);
    }

    return dp[n - 1];
}

// space optimization
int minCost_optimal(vector<int> &height)
{
    int n = height.size();
    if (n <= 1)
        return 0;

    // assigning values using base cases
    int prev2 = 0;
    int prev1 = abs(height[0] - height[1]);

    for (int i = 2; i < n; i++)
    {
        int c1 = abs(height[i] - height[i - 1]) + prev1;
        int c2 = abs(height[i] - height[i - 2]) + prev2;

        int curr = min(c1, c2);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int minCost(vector<int> &height)
{
    vector<int> dp(height.size() + 1, -1);
    // Code here
    // return tryAllWays(0, height.size(), height, dp);
}

int main()
{
    // vector<int> heights = {20, 30, 40, 20};
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    // cout << minCost(heights) << endl;
    cout << minCost_T(heights) << endl;

    return 0;
}