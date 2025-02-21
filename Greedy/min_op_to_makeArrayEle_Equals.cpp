#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/description/

You are also given an integer array queries of size m. For the ith query, you want to make all of the elements of nums equal to queries[i]. You can perform the following operation on the array any number of times:

Increase or decrease an element of the array by 1.
Return an array answer of size m where answer[i] is the minimum number of operations to make all elements of nums equal to queries[i].

Input: nums = [3,1,6,8], queries = [1,5]
Output: [14,10]

*/

int lowerBound(vector<int> &nums, int target)
{
    int s = 0, e = nums.size() - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (nums[mid] > target)
            e = mid - 1;
        else
            s = mid + 1;
    }

    return e;
}
vector<long long> minOperations(vector<int> &nums, vector<int> &queries)
{

    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<long long> prefixSum(n, 0);
    vector<long long> res;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            prefixSum[i] = nums[i];

        else
            prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    for (int q : queries)
    {
        int index = lowerBound(nums, q);
        // After getting index, divide into 2 parts left and right

        long long suffixSum = prefixSum[n - 1];
        if (index >= 0)
        { // totalSum - leftSum
            suffixSum = prefixSum[n - 1] - prefixSum[index];
        }
                                     // target*n(n--> no of elements in left part) - Leftsum
        long long leftPart = index >= 0 ? ((long long)q * (index + 1)) - prefixSum[index] : 0;

                                     // rightSum - target*n (n --> no of elemetns in right part)
        long long rightPart = suffixSum - ((long long)q * (n - index - 1));

        res.push_back(leftPart + rightPart);
    }
    return res;
}
int main()
{

    return 0;
}