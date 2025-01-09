#include <bits/stdc++.h>
using namespace std;

int getFirstGreterEqual(vector<int> &nums, int target)
{
    // It is same as Lower_bound function
    // it will return index of first greter of equal element than target...
    int n = nums.size();
    int s = 0, e = n - 1;
    int ans = n;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (nums[mid] >= target)
        {
            // store current ans, and serach for better result.
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }

    return ans;
}

vector<int> searchRange(vector<int> &nums, int target)
{

    int n = nums.size();
    int firstOccuredIndx = getFirstGreterEqual(nums, target);

    if (firstOccuredIndx == n || nums[firstOccuredIndx] != target) // Handling case of target not found.
        return {-1, -1};

    // Here we are finding index of target+1 since
    // our function getFirstGreterEqual return index of first element that is
    // greter or equal to target, so we change target to (target+1) and trying to geting
    // index of new target. and it's guarntee that our original target last index is previous to new target index.
    // And we had already handled case of target not found above so we getting correct result....
    
    int lastOccuredIndex = getFirstGreterEqual(nums, target + 1) - 1;

    return {firstOccuredIndx, lastOccuredIndex};
}
int main()
{
    vector<int> arr{3, 4, 6, 7, 16, 16, 16, 17};
    vector<int>res = searchRange(arr,16);
    cout<<res[0] << " " <<res[1]<<endl;
    return 0;
}