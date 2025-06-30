#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums where every element appears three times except for one, which appears exactly once.
Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

https://leetcode.com/problems/single-number-ii/description/

EX: arr = [2,3,2,4,4,2,4]
Output : 3
*/

bool isBitSet(int num, int i)
{
    int mask = 1 << i;
    if ((num & mask) == 0)
        return false;
    return true;
}

//T.C O(N*32) S.C O(1)
int singleNumber(vector<int> &nums)
{
    // for each element of nums, count the how many numbers have ith bit set
    // Integer have 32 bits so check each bits

    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        int cnt = 0;
        for (int num : nums)
        {
            if (isBitSet(num, i))
                cnt++;
        }

        // Cnt is not multiple of 3 then ith bit of single number is must be set...
        if ((cnt % 3) != 0)
        {
            ans = (ans | (1 << i)); // setting the ith bit of the answer
        }
    }

    return ans;
}

int main()
{
    return 0;
}