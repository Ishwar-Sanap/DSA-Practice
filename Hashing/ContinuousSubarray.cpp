#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.
A good subarray is a subarray where:
its length is at least two, and
the sum of the elements of the subarray is a multiple of k.

Trick:
	Let say we have number y and number x and we perform modulo with k give number z
	(y + x )% k = z
	(y + multipleof x  ) % k = z   (for every multiple of x ) you get the same reminder as z  
	Ex: (23 + 6 ) % 6 = 5  (23 + 12) %6 = 5  (23 + 18) % 6 = 5

*/
bool checkSubarraySum(vector<int> &nums, int k)
{

    // Remider and Indices
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
            mp[req] = i;
    }

    return false;
}

int main()
{

    return 0;
}