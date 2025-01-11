#include <bits/stdc++.h>
using namespace std;
//3,1,3,3,3 Target 1 True
//1,3,3,3 Target 1 True

bool search2(vector<int> &nums, int target)
{
    int n = nums.size();
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (nums[mid] == target)
            return true;

        if(nums[mid] == nums[s] && nums[mid] == nums[e]) // Handling edge case
        {
            s++;
            e--;
            continue;
        }

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
    return false;
}
int main()
{
    vector<int> arr = {3,1,3,3,3};
    int target = 1;

    cout << search2(arr, target) << endl;
}