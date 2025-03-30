#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that
each unique element appears only once. The relative order of the elements should be kept the same.
Then return the number of unique elements in nums.
*/
int main()
{

    return 0;
}
int removeDuplicates(vector<int> &nums)
{

    int n = nums.size();

    int k = 0;
    int i = 1;
    while (i < n)
    {
        if (nums[i] == nums[k])
        {
            i++;
        }
        else
        {
            nums[k + 1] = nums[i];
            k++;
            i++;
        }
    }
    return k + 1;
}