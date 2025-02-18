#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/jump-game/
jump game :

    Input: nums = [2,3,0,1,4]
    Output: true
    Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
    Example 2:

    Input: nums = [3,2,1,0,4]
Output: false
*/

bool canJump(vector<int> &nums)
{

    int n = nums.size();

    int maxReach = 0;
    for (int i = 0; i < n; i++)
    {
        // while jumping we max reached at 0 and it is not last index then can't possible to jump further
        if (i != n - 1 && nums[i] == 0 && maxReach <= i)
            return false;

        maxReach = max(maxReach, nums[i] + i);
    }

    return true;
}

int main()
{

    return 0;
}