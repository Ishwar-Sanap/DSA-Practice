// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

#include <bits/stdc++.h>
using namespace std;

int numberOfSubarrays(vector<int> &nums, int k)
{

    // exactly Same as no of subarry having sum k

    unordered_map<int, int> mp;
    mp[0] = 1; // Initially 0 odd count

    int subArrayCnt = 0;
    int currOddCnt = 0;
    for (int num : nums)
    {
        if (num % 2 == 1)
            currOddCnt++;

        int reqOddCnt = currOddCnt - k;

        if (mp.find(reqOddCnt) != mp.end())
            subArrayCnt += mp[reqOddCnt];

        mp[currOddCnt]++;
    }
    return subArrayCnt;
}
int main()
{

    return 0;
}