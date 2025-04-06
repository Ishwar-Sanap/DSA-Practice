
#include <bits/stdc++.h>
using namespace std;

/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
*/
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    int n = nums.size();
    int i = 0;
    sort(nums.begin(), nums.end());

    while (i < n - 3)
    {
        // ignoring duplicates from ith index
        while (i > 0 && nums[i] == nums[i - 1])
            i++;

        int j = i + 1;
        while (j < n - 2)
        {
            // ignoring duplicates from j
            while (j > i + 1 && j < n && nums[j] == nums[j - 1])
                j++;

            // since 1st and 2nd element from quadruplets  is fixed ith, jth element is fixed
            // we can apply 2sum on remainnig 2 elements form quadruplets
            int s = j + 1, e = n - 1;
            while (s < e)
            {
                long long currSum = 1LL * nums[i] + nums[j] + nums[s] + nums[e];
                if (currSum == target)
                {
                    res.push_back({nums[i], nums[j], nums[s], nums[e]});

                    // ignoring duplicates from e index
                    while (e > s && nums[e - 1] == nums[e])
                        e--;

                    /// ignoring duplicates from s index
                    while (s < e && nums[s] == nums[s + 1])
                        s++;

                    // going to next elemetns for further after ignoring elements
                    e--;
                    s++;
                }

                else if (currSum > target)
                    e--;

                else
                    s++;
            }

            j++;
        }

        i++;
    }
    return res;
}

int main()
{

    return 0;
}