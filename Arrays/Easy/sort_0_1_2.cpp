#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sort-colors/
/*
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/
void sortColors(vector<int> &nums)
{
    int n = nums.size();
    // Three-Way Partitioning Algorithm
    int i = 0, ptr0 = 0, ptr2 = n - 1;

    while (i <= ptr2)
    {
        if (nums[i] == 0)
        {
            // placing 0 on left side
            swap(nums[i], nums[ptr0]);
            ptr0++;
            i++;
            // i incremented since, ptr0 will alwasy have 0, so no issue.
        }
        else if (nums[i] == 1)
        {
            i++;
        }
        else
        {
            // placing 2 on right side 
            swap(nums[i], nums[ptr2]);
            ptr2--;
            // here i is not incremented since, ptr2 may have either 0/1/2 after swap it comes on ith index..
        }
    }
}

int main()
{

    return 0;
}