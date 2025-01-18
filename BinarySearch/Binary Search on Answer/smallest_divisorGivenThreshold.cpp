#include <bits/stdc++.h>
using namespace std;

bool isSumLesserThanThreshold(vector<int> &nums, int T, int D)
{
    long sum = 0;
    long sum2 = 0;
    for (int ele : nums)
    {
        sum += ele / D;
        if (ele % D != 0)
            sum++;

        // another way to get result of the division is rounded to the nearest integer greater than or equal to that element. 
        sum2 += (ele + D - 1) / D;
    }
    return sum2 <= T;
}
int smallestDivisor(vector<int> &nums, int threshold)
{

    int low = 1;
    int high = *max_element(nums.begin(), nums.end());

    int ans = 1;
    while (low <= high)
    {
        int mid = low + (high - mid) / 2;

        if (isSumLesserThanThreshold(nums, threshold, mid)) // then try for getting minimum ans
        {
            ans = mid;
            high = mid - 1;
        }
        else // sum is greter then we have to increase divisor
            low = mid + 1;
    }
    // return ans;
    return low;

    /*
    - Now in ans varible you got the result, but if you look at the low member it will also has the same result.
	This is due to the opposite polarity concept , where initially low is pointing to not possible answer, and high is pointing to 
	Possible answer , but when Binary search finishes it' execution then the pole get's  changed and low will pointing to best possible answer and high points to not possible answer.

    */
}
int main()
{
    vector<int> nums = {1, 2, 5, 9};
    cout << smallestDivisor(nums, 6) << endl;
    return 0;
}