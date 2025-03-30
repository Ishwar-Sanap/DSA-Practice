#include <bits/stdc++.h>
using namespace std;

/*
    Input: nums = [1,2,3,4,5,6,7], k = 3

    Output: [5,6,7,1,2,3,4]


    What if k < 0, ???
     nums = [1,2,3,4,5,6,7], k = -1, output : --> [2,3,4,5,6,7,1]
        - From left side it was roated 1 time
        - We can obsereve that it is eqivalent to rotate 6 times from right.. So we can convert k to positive
i.e k = (n - abs(k) ) , now use same approach as above.. :)
*/

void reverse(int si, int ei, vector<int> &nums)
{
    while (si < ei)
    {
        swap(nums[si++], nums[ei--]);
    }
}
void rotate(vector<int> &nums, int k)
{

    int n = nums.size();

    k = k % n;

    // reverese part1
    reverse(0, n - k - 1, nums);

    // reverse part2
    reverse(n - k, n - 1, nums);

    /// reverse whole array
    reverse(0, n - 1, nums);
}

// T.C O(N), S.C O(N)
void rotate_usingSpace(vector<int> &nums, int k)
{

    int cnt = 0;
    int n = nums.size();

    vector<int> temp(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        nums[(i + k) % k] = temp[i];
    }
}
int main()
{

    return 0;
}