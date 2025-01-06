#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}
/*
Given an array arr[] of integers and an integer k, your task is to find the maximum value for each contiguous subarray of size k. The output should be an array of maximum values corresponding to each contiguous subarray.

Input: arr[] = [8, 5, 10, 7, 9, 4, 15, 12, 90, 13], k = 4
Output: [10, 10, 10, 15, 15, 90, 90]
*/
vector<int> maxOfSubarrays(vector<int> &arr, int k)
{
    // code here
    vector<int> res;
    priority_queue<pair<int, int>> pq;
    int n = arr.size(), i = 0, j = 0;
    while (j < n)
    {
        pq.push({arr[j], j});

        if ((j - i + 1) < k)
            j++;

        else
        {

            res.push_back(pq.top().first);

            while (pq.size() > 0 && pq.top().second <= i)
            {
                pq.pop();
            }

            i++;
            j++;
        }
    }
    return res;
}
