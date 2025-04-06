#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
Example 1

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
*/
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    int n = nums.size();
    int i = 0;
    sort(nums.begin(), nums.end());

    while (i < n - 2)
    {
        // ignoring duplicates at ith indexes

        while (i > 0 && i < n && nums[i - 1] == nums[i])
            i++;

        int j = i + 1, k = n - 1;

        // since 1st element from triplet is fixed ith element is fixed
        // we can apply 2sum on remainnig 2 elements form triplet
        while (j < k)
        {
            int currSum = nums[i] + nums[j] + nums[k];
            if (currSum == 0)
            {
                res.push_back({nums[i], nums[j], nums[k]});

                // ignoring duplicates from kth index
                while (k > j && nums[k - 1] == nums[k])
                    k--;

                /// ignoring duplicates from jth index
                while (j < k && nums[j] == nums[j + 1])
                    j++;

                // going to next elemetns for further after ignoring elements
                k--;
                j++;
            }

            else if (currSum > 0)
                k--;

            else
                j++;
        }

        i++;
    }
    return res;
}
