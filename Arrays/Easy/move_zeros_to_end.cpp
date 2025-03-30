#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
void moveZeroes(vector<int> &nums)
{

    int j = 0, n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            nums[j] = nums[i];
            j++;
        }
    }

    while (j < n)
    {
        nums[j] = 0;
        j++;
    }
}