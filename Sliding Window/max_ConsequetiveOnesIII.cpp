#include <bits/stdc++.h>
using namespace std;
/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/
int longestOnes(vector<int> &nums, int k)
{

    int n = nums.size();
    int flipCnt = 0, ans = 0;
    int i = 0, j = 0;
    while (j < n)
    {
        if (nums[j] == 0)
            flipCnt++;

        if (flipCnt <= k)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else
        {

            while (flipCnt > k)
            {
                if (nums[i] == 0)
                    flipCnt--;
                i++;
            }
            j++;
        }
    }
    return ans;
}
int main()
{
    vector<int>arr = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout<<longestOnes(arr,k)<<endl;
    return 0;
}