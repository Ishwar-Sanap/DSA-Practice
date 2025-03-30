#include <bits/stdc++.h>
using namespace std;

/*
You should return the array of nums such that the the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
*/
vector<int> rearrangeArray(vector<int> &nums)
{

    int n = nums.size();
    vector<int> ans(n, 0);

    int posIndx = 0, negIndx = 1;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            ans[posIndx] = nums[i];
            posIndx += 2;
        }
        else
        {
            ans[negIndx] = nums[i];
            negIndx += 2;
        }
    }

    return ans;
}


int main()
{

    return 0;
}
