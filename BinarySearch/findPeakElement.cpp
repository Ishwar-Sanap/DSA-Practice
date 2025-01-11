#include <bits/stdc++.h>
using namespace std;

/*
 find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
 A peak element is an element that is strictly greater than its neighbors.

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
*/
int main()
{

    return 0;
}

int findPeakElement(vector<int> &nums)
{

    int n = nums.size();
    int s = 0, e = n - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (mid + 1 < n && nums[mid + 1] > nums[mid])
            s = mid + 1;
        else
            e = mid - 1;
    }
    return s; 
    // sine above condition we are saying num[mid+1]> num[mid] s = mid+1
    // so at final s will be your answer that will have any of pick element index from array.
}