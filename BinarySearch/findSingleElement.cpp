// You are given a sorted numsay consisting of only integers where every element appears exactly twice,
// except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

// Example 1:

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2

#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

/*
mid^1 trick:
For odd numbers (e.g., 1, 3, 5, 7, 9), mid^1 equals to mid - 1
For example: 3 ^ 1 = 0011 ^ 0001 = 0010 = 2

For even numbers (e.g., 2, 4, 6, 8, 10), mid^1 equals to mid + 1
For example: 6 ^ 1 = 0110 ^ 0001 = 0111 = 7
*/

int singleNonDuplicate(vector<int> &nums)
{

    int low = 0, high = nums.size() - 1;
    int n = nums.size();
    if (n == 1)
        return nums[0];

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (mid % 2 != 0) // odd index
        {
            if (nums[mid] == nums[mid - 1])
                low = mid + 1;
            else
                high = mid - 1;
        }
        else
        { // even index
            if (nums[mid] == nums[mid + 1])
                low = mid + 1;
            else
                high = mid - 1;
        }

        /* Simplified form of above conditions
        
            // if(nums[mid] == nums[mid ^1]) // simplified of below

            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
                (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
                low = mid + 1; // even odd sequence continue so go right part for ans
            else
                high = mid - 1;

            /*


        */
    }

    return nums[low];
}