#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/reverse-pairs/description/

Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1

// Ex: [1,2,3,4, 0,1,7] output ---> 6
*/
int getReversePairCnt(vector<int> &arr, int si, int mid, int ei)
{
    int cnt = 0;
    int j = mid + 1;
    for (int i = si; i <= mid; i++)
    {
        while (j <= ei && arr[i] > 2LL * arr[j])
            j++;

        cnt += (j - (mid + 1));
    }
    return cnt;
}
int merge2SortedArrays(vector<int> &arr, int si, int mid, int ei)
{

    // Finding reverse paris counts from 2 sorted arrays
    int reverseCnt = 0;

    // Array1 : si to mid
    // Array2 : mid+1 to ei

    int i = si, j = mid + 1;
    vector<int> temp;
    reverseCnt += getReversePairCnt(arr, si, mid, ei);
    while (i <= mid && j <= ei)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        { // Array2 elemetn is greter

            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
        temp.push_back(arr[i++]);

    while (j <= ei)
        temp.push_back(arr[j++]);

    // copy temp array into origianl array:
    i = si;
    for (int ele : temp)
    {
        arr[i] = ele;
        i++;
    }

    return reverseCnt;
}

void divideArray(vector<int> &arr, int si, int ei, int &cnt)
{
    if (si >= ei)
        return;

    int mid = si + (ei - si) / 2;

    divideArray(arr, si, mid, cnt);
    divideArray(arr, mid + 1, ei, cnt);

    cnt += merge2SortedArrays(arr, si, mid, ei);
}

int reversePairs(vector<int> &arr)
{
    // Using the approach of merge sort
    int cnt = 0;

    divideArray(arr, 0, arr.size() - 1, cnt);

    return cnt;
}
