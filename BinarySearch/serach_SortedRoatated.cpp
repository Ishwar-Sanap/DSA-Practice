#include <bits/stdc++.h>
using namespace std;

/*
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/
int search(vector<int> &nums, int target)
{

    int n = nums.size();
    int ans = -1;
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        // check in which line mid is present
        if (nums[mid] >= nums[0]) // line1
        {
            if (target > nums[mid] || target < nums[0])
                low = mid + 1;
            else
                high = mid - 1;
        }
        else // line 2
        {
            if (target < nums[mid] || target > nums[n - 1])
                high = mid - 1;
            else
                low = mid + 1;
        }
    }

    return -1;
}

int search2(vector<int> &nums, int target)
{
    int n = nums.size();
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[mid] >= nums[s]) // left part soreted
        {
            if (target >= nums[s] && target <= nums[mid]) // If target is in this range
                e = mid - 1;
            
            else
                s = mid + 1;
        }
        else // right part sorted
        {
            if (target >= nums[mid] && target <= nums[e]) // If target is in this range
                s = mid + 1;
            else
                e = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {4, 5, 6, 7, 8, 1, 2, 3};
    int target = 7;

    cout << search2(arr, target) << endl;
}