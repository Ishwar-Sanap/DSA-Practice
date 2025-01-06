#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
/*
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

*/


int subarraysDivByK(vector<int> &nums, int k)
{

    int n = nums.size();
    unordered_map<int, int> mp;
    mp[0] = 1;
    int currSum = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += nums[i];
        int rem = (currSum) % k;
        if (rem < 0)
            rem += k;  // converting -ve remider to positive equivalent remider
        // if map has rem number that mean there is subarray whose sum divisible by k
        cnt += mp[rem];
        mp[rem]++;
    }
    return cnt;
}
int main()
{
    vector<int>arr = {2, -6 ,3, 1 ,2 ,8 ,2, 1};
    cout<<subarraysDivByK( arr, 7);
    return 0;
}