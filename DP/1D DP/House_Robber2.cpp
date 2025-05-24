#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/house-robber-ii/
/*
nput: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Ex2 : nums = { 9,12,8,1,2}  output : 17

*/
int getMaxMoney(vector<int> &nums, int si, int n)
{

    int prev2 = nums[si];
    int prev1 = max(nums[si], nums[si + 1]);

    for (int i = si + 2; i < n; i++)
    {
        int pickMoney = nums[i] + prev2;
        int nonPickMoney = 0 + prev1;

        int curr = max(pickMoney, nonPickMoney);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int rob(vector<int> &nums)
{

    int n = nums.size();

    if (n == 1)
        return nums[0];

    else if (n == 2)
        return max(nums[0], nums[1]);

    // first and last both can't be possible to add into answer

    int excludeLast = getMaxMoney(nums, 0, n - 1);
    int excludeFirst = getMaxMoney(nums, 1, n);

    return max(excludeLast, excludeFirst);
}

int main()
{

    return 0;
}
