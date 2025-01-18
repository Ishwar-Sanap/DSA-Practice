#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array.

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Input: arr = [1,2,3,4], k = 2
Output: 6
Input arr = [5, 7, 8, 9] k = 4
Explanation: The missing positive integers are [1,2,3,4,6....]. 4th missing 4
             5th missing will be 6, since 5 elements comes in between
*/
int findKthPositive(vector<int> &arr, int k)
{
    int n = arr.size();
    int i = 0;
    // As array is sorted, we can shif k elements which <= k
    while (i < n)
    {
        if (arr[i] <= k)
            k++;
        else
            break;

        i++;
    }
    return k;
}
int findKthPositive2(vector<int> &arr, int k)
{
    int n = arr.size();
    int i = 0;

    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int missed = arr[mid] - (mid + 1);

        if (missed >= k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low + k;
}
int main()
{
    vector<int> arr = {5, 7, 8, 9};
    cout << findKthPositive2(arr, 5) << endl;
    return 0;
}