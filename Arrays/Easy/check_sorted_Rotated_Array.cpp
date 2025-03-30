#include <bits/stdc++.h>
using namespace std;

/*
We need to find how many times, the array is breaking the ascending order. If it is breaking just 
once then it or it does't break even once then it is sorted. So we can return true. Otherwise false.
*/
bool check2(vector<int> &nums)
{
    int i = 1, n = nums.size();

    int breakAsc = 0;
    while (i < n)
    {
        if (nums[i] < nums[i - 1])
            breakAsc++;

        i++;
    }

    if(nums[n-1] > nums[0]) breakAsc++;

    return breakAsc <= 1;
}

bool check(vector<int> &nums)
{

    int i = 1, n = nums.size();

    // IT willl check's initial roated sorted elements
    while (i < n)
    {
        if (nums[i - 1] <= nums[i])
        {
            i++;
        }
        else
        {
            break;
        }
    }

    if (i == n)
        return true;

    // once roated elements completed checking, then all elements should be lesse than equal to nums[0] and
    // they should be in sorted order..
    while (i < n)
    {
        if (i < n - 1 && nums[i] <= nums[0] && nums[i + 1] >= nums[i])
            i++;
        else if (i == n - 1 && nums[i] <= nums[0])
            i++;
        else
            return false;
    }

    return true;
}

int main()
{

    return 0;
}
