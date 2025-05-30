#include <bits/stdc++.h>
using namespace std;

/*
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

https://leetcode.com/problems/partition-equal-subset-sum/description/
*/
bool subsetSumK(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> prevRow(k + 1, 0);
    vector<int> currRow(k + 1, 0);

    // base case for, sum 0
    prevRow[0] = currRow[0] = 1;

    // for single element
    if (nums[0] <= k)
        prevRow[nums[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int sum = 1; sum <= k; sum++)
        {
            int nonPick = prevRow[sum];
            int pick = 0;
            if (nums[i] <= sum)
                pick = prevRow[sum - nums[i]];

            currRow[sum] = pick || nonPick;
        }
        prevRow = currRow;
    }

    return prevRow[k];
}
bool canPartition(vector<int> &nums)
{

    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    // if the totalSum is odd then it is not possible that only two
    // subsets will have equal sum
    if (totalSum % 2 == 1)
        return false;

    // else then check is there  subset whose sum(k) equal to totalSum/2,
    // then another subset is also exitst
    // since s = s1 + s2  , if s1 = k , then s2 will definately also k

    int k = totalSum / 2;

    return subsetSumK(nums, k);
}

int main()
{

    return 0;
}