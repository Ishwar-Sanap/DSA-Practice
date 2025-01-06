#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.



Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
*/

int atLestKDistinct(vector<int> &nums, int k)
{
    int n = nums.size();
    int i = 0, j = 0, cnt = 0;

    unordered_map<int, int> mp;
    while (j < n)
    {
        mp[nums[j]]++;

        if (mp.size() < k)
            j++;
        else
        {

            while (mp.size() >= k)
            {
                cnt += (n - j);

                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            j++;
        }
    }
    return cnt;
}

int atMostKDistinct(vector<int> &nums, int k)
{
    int n = nums.size();
    int i = 0, j = 0, cnt = 0;

    unordered_map<int, int> mp;
    while (j < n)
    {
        mp[nums[j]]++;

        if (mp.size() <= k)
        {
            cnt += (j - i + 1);
            j++;
        }
        else
        {
            while (mp.size() > k)
            {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            cnt += (j - i + 1);
            j++;
        }
    }
    return cnt;
}
int subarraysWithKDistinct(vector<int> &nums, int k)
{

    // 1 1 1 2 2 3 3 4 4 4 , k = 3

    // at lest 3 distinct elemetn subarry count --> 21
    // at least 4 disticnt element subarray count --> 9

    // subarray with exactly k distinct element == 21 - 9 = 12

    // Counting at least K distinct elements.
    //  return atLestKDistinct(nums,k) - atLestKDistinct(nums,k+1);

    // another approch using counting At most k distinct elements.
    return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
}

int main()
{

    return 0;
}