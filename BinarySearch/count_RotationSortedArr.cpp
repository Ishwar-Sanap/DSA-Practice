#include<bits/stdc++.h>
using namespace std;
/*
Given an increasing sorted rotated array arr of distinct integers. The array is right-rotated k times. Find the value of k.
Let's suppose we have an array arr = [2, 4, 6, 9], so if we rotate it by 2 times so that it will look like this:
After 1st Rotation : [9, 2, 4, 6]
After 2nd Rotation : [6, 9, 2, 4]
*/
int findKRotation(vector<int> &arr)
{
    // Find the index of larget element, index+1 will be rotations.
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= arr[0])
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans == n - 1 ? 0 : ans + 1;
}