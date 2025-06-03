#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/target-sum/description/

/*
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target

*/

// Recusive solution T.C O(2^n)  S.C O(n)
int tryAllways(int indx, int target, vector<int> &nums)
{
    if (indx == 0)
    {
        int plus = 0, minus = 0;

        if (nums[indx] - target == 0)
            plus = 1;

        if (nums[indx] + target == 0)
            minus = 1;

        return plus + minus;
    }

    int plus = 0, minus = 0;
    plus = tryAllways(indx - 1, target - nums[indx], nums);

    minus = tryAllways(indx - 1, target + nums[indx], nums);

    return plus + minus;
}

// since there can be -ve target so it causing the issue for memoizing the recusive solution
// so using unordered map<string, int> to represent the state and value..
// T.C O(n*target)  S.C O(n) + O(n*target)
int tryAllways(int indx, int target, vector<int> &nums, unordered_map<string, int> &mp)
{
    if (indx == 0)
    {
        int plus = 0, minus = 0;

        if (nums[indx] - target == 0)
            plus = 1;

        if (nums[indx] + target == 0)
            minus = 1;

        return plus + minus;
    }

    // here 2 staes of varibale are required so use the _ as seperator for generating unique keys
    string key = to_string(indx) + "_" + to_string(target);
    if (mp.find(key) != mp.end())
        return mp[key];

    int plus = 0, minus = 0;
    plus = tryAllways(indx - 1, target - nums[indx], nums, mp);

    minus = tryAllways(indx - 1, target + nums[indx], nums, mp);

    return mp[key] = plus + minus;
}

// Tabulations for above case:
int findTargetSumWays_Tabulation(vector<int> &nums, int target)
{
    // using map as dp to avoid the -ve indices issues..
    unordered_map<string, int> dp;
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    for (int i = 0; i < n; i++)
    {   
        // possible ranges of target 
        for (int currTarget = -totalSum; currTarget <= totalSum; currTarget++)
        {
            string key = to_string(i) + "_" + to_string(currTarget);

            if (i == 0)
            {
                int plus = 0, minus = 0;

                if (nums[i] - currTarget == 0)
                    plus = 1;

                if (nums[i] + currTarget == 0)
                    minus = 1;

                dp[key] = plus + minus;
                continue;
            }

            int plus = 0, minus = 0;
            string kp = to_string(i - 1) + "_" + to_string(currTarget - nums[i]);
            plus = dp[kp];

            string km = to_string(i - 1) + "_" + to_string(currTarget + nums[i]);
            minus = dp[km];

            dp[key] = plus + minus;
        }
    }

    string key = to_string(n - 1) + "_" + to_string(target);
    return dp[key];
}

int findTargetSumWays(vector<int> &nums, int target)
{

    int n = nums.size();

    // return tryAllways(n - 1, target, nums);

    // map is now working as DP array
    // unordered_map<string, int> mp;
    // return tryAllways(n - 1, target, nums, mp);

    return findTargetSumWays_Tabulation(nums, target);
}

int main()
{

    vector<int> arr = {1, 1, 1, 1, 1};
    cout << findTargetSumWays(arr, 3);

    return 0;
}