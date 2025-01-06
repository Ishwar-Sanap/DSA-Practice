#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1, mid = 0;
    // To avoid integer overflow we calculated mid
    // using  mid = low + (high - low)/2;
    while (low <= high)
    {
        mid = low + (high - low) / 2; // or mid =  (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        else if (target > nums[mid])
            low = mid + 1; // find target in Right half
        else
            high = mid - 1; // find target in Left half
    }
    return -1;
}

int binarySearchRecursive(vector<int> &nums, int low, int high, int target)
{
    // base case
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (nums[mid] == target)
        return mid;

    else if (target > nums[mid])
        return binarySearchRecursive(nums, mid + 1, high, target); // find in right part

    else
        return binarySearchRecursive(nums, low, mid - 1, target); // find in left part
}
int searchTarget(vector<int> &nums, int target)
{
    int n = nums.size();
    return binarySearchRecursive(nums, 0, n - 1, target);
}
int main()
{
    vector<int> arr{3, 4, 6, 7, 9, 12, 16, 17};
    cout << searchTarget(arr, 22) << endl;
    return 0;
}