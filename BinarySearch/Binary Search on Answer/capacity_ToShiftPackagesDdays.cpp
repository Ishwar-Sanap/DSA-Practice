#include <bits/stdc++.h>
using namespace std;

/*
A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.



Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15

Input: weights = [1,2,3,1,1], days = 4
Output: 3
*/
int coutnDayToPackgesShipped(vector<int> &weights, int days, int capacity)
{
    int currWt = 0, n = weights.size();
    int daysToShipped = 1;

    int i = 0;
    while (i < n)
    {
        currWt += weights[i];
        if (currWt > capacity)
        {
            daysToShipped++;
            currWt = 0;
            continue;
        }
        i++;
    }

    return daysToShipped;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    int ans = 1;
    while (low <= high)
    {
        int mid = low + (high - mid) / 2;
        int daysToShipped = coutnDayToPackgesShipped(weights, days, mid);
        if (daysToShipped <= days) // then try for getting minimum ans
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    // return ans;
    return low;
}
int main()
{

    return 0;
}