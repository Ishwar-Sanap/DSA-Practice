#include <bits/stdc++.h>
using namespace std;

/*
Given two arrays arr1 and arr2, the task is to find the maximum sum possible of a window in array arr2 such that elements of the same window in array arr1 are unique

Input: arr1 = [0, 1, 2, 0, 2], arr2 = [5, 6, 7, 8, 2]
Output: 21
Explanation: The maximum sum occurs for the window [6, 7, 8] in arr2, which corresponds to the window [1, 2, 0] in arr1. All elements within this window in arr1 are unique, and the sum is 6 + 7 + 8 = 21.
*/
long int returnMaxSum(vector<int> &arr1, vector<int> &arr2)
{
    // Code here

    int n = arr2.size();
    long currSum = 0;

    int i = 0, j = 0;
    long int maxSum = 0;
    unordered_map<int, int> mp; // sotre unique from arr1 and frequecy
    while (j < n)
    {
        mp[arr1[j]]++;
        currSum += arr2[j];

        // if we found duplicates shirnk window of unique and reduce sum from currSum
        while (mp.size() < (j - i + 1))
        {
            mp[arr1[i]]--;
            currSum -= arr2[i];

            if (mp[arr1[i]] == 0)
                mp.erase(arr1[i]);

            i++;
        }

        // Here alway mapSize == (j - i + 1) so we can directly maintain maxSum
        maxSum = max(maxSum, currSum);

        j++;
    }

    return maxSum;
}

int main()
{
    vector<int> arr1 = {0, 1, 2, 0, 2};
    vector<int> arr2 = {5, 6, 7, 8, 2};

    cout << returnMaxSum(arr1, arr2) << endl;
    return 0;
}