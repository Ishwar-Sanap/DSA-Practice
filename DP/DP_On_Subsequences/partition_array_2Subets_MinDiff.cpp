#include <bits/stdc++.h>
using namespace std;

/*
https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?source=youtube&campaign=striver_dp_videos&leftPanelTab=0&leftPanelTabValue=PROBLEM
*/
// Check the subset with sum k
vector<int> subSetSumk(vector<int> &nums, int k)
{
    vector<int> prevRow(k + 1, 0);
    vector<int> currRow(k + 1, 0);

    prevRow[0] = currRow[0] = 1;
    if (nums[0] <= k)
        prevRow[nums[0]] = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        for (int sum = 1; sum <= k; sum++)
        {
            int pick = 0, nonPick = 0;

            if (nums[i] <= sum)
                pick = prevRow[sum - nums[i]];

            nonPick = prevRow[sum];

            currRow[sum] = pick || nonPick;
        }

        prevRow = currRow;
    }

    return prevRow;
}
int minSubsetSumDifference(vector<int> &nums, int n)
{
    long long totalSum = 0;
    for (int ele : nums)
    {
        totalSum += ele;
    }


    vector<int> isPossibleSum = subSetSumk(nums, totalSum);

    int minDiff = INT_MAX;
    for (int sum = 0; sum <= totalSum; sum++)
    {
        int partition2Sum = totalSum - sum;

        if (isPossibleSum[sum] && isPossibleSum[partition2Sum])
        {
            minDiff = min(minDiff, abs(partition2Sum - sum));
        }
    }

    return minDiff;
}
int main()
{
    // vector<int> arr = {3, 2, 1};    , part1 = {3}  part2 = {1,2} --> abs(3 - 3) = 0
    // cout << minSubsetSumDifference(arr,3) << endl;
    
    vector<int> arr = {8,6,5};
    cout << minSubsetSumDifference(arr,3) << endl;

    return 0;
}
