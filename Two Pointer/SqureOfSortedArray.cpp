#include <bits/stdc++.h>
using namespace std;
/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
*/

int main()
{

    return 0;
}
vector<int> sortedSquares(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n, 0);

    int i = 0, j = n - 1;
    int indx = n - 1;
    while (i < n && j >= 0)
    {
        // As we want squares of each number sorted in non-decreasing order.
        //  so we will use 2 pointer approach to choose element from left or right part of array

        int squre1 = nums[i] * nums[i];
        int squre2 = nums[j] * nums[j];

        if (squre1 > squre2)
        {
            if (indx >= 0)
                res[indx] = squre1;
            i++;
            indx--;
        }
        else
        {
            if (indx >= 0)
                res[indx] = squre2;
            j--;
            indx--;
        }
    }

    return res;
}