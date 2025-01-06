/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Input: nums = [-1,0,1,2,-1,-4]
Output: [ [-1,-1,2], [-1,0,1] ]

Input : nums = [3 3 -2 -1 -4 1]
output --> [[-4 1 3] , [-1 -1 2]]

Algorithm: 
- Sort the input array so we can apply two pointers approach
- We have to fix one element (ith) and check there are other two elemets 
- Two find other two element apply two pointer
- As array is sorted we user propery i.e sum = nums[i] + nums[left] + nums[right];
    sum > 0 , right-- to decrease sum
    sum < 0 , left++   to increase sum
    sum == 0 we found the triplet store in ans.
    but make sure to remove consecutive duplicates from [left to right range]  for further process
- One more condition required to handle when fixed (ith) elements having consecutive duplicates make sure to remove it as well
- by following these steps you will get all unique tripltes...
*/
vector<vector<int>> threeSum(vector<int> &nums)
{
    // a[i] + a[j] + a[k] == 0
    //  a[k] = 0 - (a[i] + a[k])
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    for (int i = 0; i < n - 2; i++)
    {
        // Handling duplicates at ith fixed index.
        if (i > 0 && nums[i - 1] == nums[i])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0)
            {
                // Got triplet
                ans.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;
                // Now task to remove duplicates in present in range [left -- Right]

                while (right > left && nums[right] == nums[right + 1])
                    right--;
                while (right > left && nums[left] == nums[left - 1])
                    left++;
            }
            else if (sum > 0)
                right--;
            else
                left++;
        }
    }

    return ans;
}
int main()
{

    return 0;
}
