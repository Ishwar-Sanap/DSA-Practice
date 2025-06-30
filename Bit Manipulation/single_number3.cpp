#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
Find the two elements that appear only once. You can return the answer in any order.

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
*/
vector<int> singleNumber(vector<int> &nums)
{

    // Take XOR of all elements

    int totalXOR = 0;

    for (int num : nums)
    {
        totalXOR = totalXOR ^ num;
    }
    //[1,2,1,3,2,5]
    // Only distinict elements XOR will be remaining in the totalXOR
    // totalXOR = (3 ^ 5)

    // now we have to split array elements into 2 groups such that, 3 and 5 shold be in different group

    // so we will check, which Right most bit is set in totalXOR, (this bit helps to differtiate 3 and 5)

    int bitIndx = 0;
    while (totalXOR != 0)
    {
        if ((totalXOR & 1) == 1)
            break;

        bitIndx++;
        totalXOR = totalXOR >> 1;
    }

    // bitIndx represent's that this bit is different in 3 & 5

    int group1 = 0, group2 = 0;
    for (int num : nums)
    {
        // if nums bitIndx is ON, then add into grop1 , elese into group2

        int mask = 1 << bitIndx;
        if ((num & mask) == 0) // nums bitIndx is OFF
            group2 = group2 ^ num;
        else
            group1 = group1 ^ num;
    }

    return {group1, group2};
}