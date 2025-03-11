#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.
A good subarray is a subarray where:
its length is at least two, and
the sum of the elements of the subarray is a multiple of k.

Trick:

We need a subarray say from i to j such that sum of all elements is divisible by k.

sum_j means prefix sum from 0 to j

sum_i means prefix sum from 0 to i

 => (sum_j - sum_i) % k = 0
 => sum_j % k - sum % k = 0
 => sum_j % k = sum_i % k    <Relation derived !!!>

Thus for some prefix_sum(0,j)%k , we need to check if there exist some prefix_sum(0,i)% such that both are equal.
If yes then return true.
Otherwise check for some other j
*/
bool checkSubarraySum(vector<int> &nums, int k)
{
    // map will store, modulo opeartion with k, of currSum..

    //          Remider and Indices
    unordered_map<int, int> mp;
    mp[0] = -1;
    int n = nums.size();
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += nums[i];
        int req = currSum % k;

        if (mp.find(req) != mp.end())
        {
            // As we want subarray whose length >=2
            if (i - mp[req] >= 2)
                return true;
        }
        else
            mp[req] = i; // store remider, in the map and it's index.
    }

    return false;
}

int main()
{

    return 0;
}