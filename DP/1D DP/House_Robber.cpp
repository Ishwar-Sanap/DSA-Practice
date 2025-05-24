#include <bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/house-robber/description/

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

Input: nums = [2,7,9,13,1]
Output: 20

*/

// Tabulation : T.C O(N) , S.C O(N)
int rob(vector<int> &nums)
{

    int n = nums.size();
    if (n == 1)
        return nums[0];

    vector<int> dp(n + 1, -1);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        int pickMoney = nums[i] + dp[i - 2];
        int nonPickMoney = 0 + dp[i - 1];

        dp[i] = max(pickMoney, nonPickMoney);
    }

    return dp[n - 1];
}

// space optimization  T.C O(N) , S.C O(1)
int rob_Optimized(vector<int> &nums)
{

    int n = nums.size();
    if (n == 1)
        return nums[0];

    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        int pickMoney = nums[i] + prev2;
        int nonPickMoney = 0 + prev1;

        int curr = max(pickMoney, nonPickMoney);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{

    return 0;
}