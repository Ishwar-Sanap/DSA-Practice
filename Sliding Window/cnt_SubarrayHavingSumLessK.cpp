#include <bits/stdc++.h>
using namespace std;
/*
Given an array of non-negative numbers and a non-negative number k, find the number of subarrays having sum less than k. We may assume that there is no overflow.

Input : arr[] = {1, 11, 2, 3, 15}
        K = 10
Output : 4
{1}, {2}, {3} and {2, 3}
 */

int getCntSubarray(vector<int> arr, int k)
{
    int n = arr.size();
    int i = 0, j = 0, cnt = 0;
    long sum = 0;
    while (j < n)
    {
        sum += arr[j];

        if (sum < k)
        {
            cnt += (j - i) + 1;
            j++;
        }
        else
        {
            while (sum >= k)
            {
                sum -= arr[i];
                i++;
            }
            // after removing element from window we can still form subarray having lesser sum
            cnt += (j - i) + 1;
            j++;
        }
    }
    return cnt;
}

int main()
{
    // vector<int> arr = {1, 11, 2, 3, 15};
    vector<int> arr = {2, 5, 6};
    cout << getCntSubarray(arr, 10) << endl;
    return 0;
}