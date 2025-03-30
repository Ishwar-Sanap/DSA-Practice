#include <bits/stdc++.h>
using namespace std;

/*
For example, for arr = [1,2,3], the following are all the
permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.


*/

void reverse(int si, int ei, vector<int> &nums)
{
    while (si < ei)
        swap(nums[si++], nums[ei--]);
}

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();

    int index = -1;
    // finding the deep index, i.e breakpoint
    for (int i = n - 1; i >= 0; i--)
    {
        if (i > 0 && nums[i - 1] < nums[i])
        {
            index = i - 1;
            break;
        }
    }

    // if condition not occured,
    // i.e nums is last permutation, we have to go back to first 1 for next ... so reverse entire array
    if (index == -1)
    {
        reverse(0, n - 1, nums);
        return;
    }

    // From right find the just next greter element that nums[index]
    for (int j = n - 1; j > index; j--)
    {
        if (nums[j] > nums[index])
        {
            // placing the jth element into current position, where deep if found
            swap(nums[j], nums[index]);

            // reverse the righ part , since we want the next permutation , after reversing right part element comes closure
            reverse(index + 1, n - 1, nums);

            return;
        }
    }
}
int main()
{

    return 0;
}