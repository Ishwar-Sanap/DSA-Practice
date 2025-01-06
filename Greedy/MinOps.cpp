#include <bits/stdc++.h>
using namespace std;
/*
Given an array of size N; and a target ->
    find the minimum number of operations needed to make all elements of array equal to target
    there are multiple target in order of Q; in one operation you can add 1 or sub 1 from arr[i]
*/

int getLowerBound(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int index = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (target <= arr[mid])
        {
            index = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return index;
}

int minimumOperations(vector<int> &arr, vector<int> targets)
{
    sort(arr.begin(), arr.end());

    int opCnt = 0, currSum = 0;
    int n = arr.size();
    // prefix sum
    unordered_map<int, int> preSum;

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        preSum[i] = currSum;
    }

    // Get lower bound of each target
    for (int target : targets)
    {
        int index = getLowerBound(arr, target);
        if (index < n)
        {
            if (target != arr[index])
                index--;

            // If target > all numbers in the array ->(target > max element of array
            // -> answer = target*n - sum; =>O(1)
            int len1 = index + 1, len2 = n - (index + 1);
            opCnt += (target * len1) - preSum[index]; // as we used lowerBound so till ith index all elements are <= target Left part

            // If target < all numbers in the array ->(target < min element of the array)
            // -> answer = sum - target*n;
            opCnt += (currSum - preSum[index]) - (target * len2); // Right part length = n - index+1
        }
        else
        {
            // Since all elements are lesser than target

            opCnt += target * n - preSum[index - 1];
        }

        cout << "Opearation cnt : " << opCnt << endl;
        opCnt = 0;
    }

    return opCnt;
}

int main()
{

    vector<int> arr = {3, 2, 6, 1, 5, 8, 7};
    vector<int> targets = {4, 6};

    minimumOperations(arr, targets);
    return 0;
}