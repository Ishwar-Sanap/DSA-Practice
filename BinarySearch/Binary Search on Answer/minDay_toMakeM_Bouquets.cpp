/*You are given an integer array bloomDay, an integer m and an integer k.
You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here is the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3
*/

#include <bits/stdc++.h>
using namespace std;

bool canMakeMbouquets(vector<int> &bloomDay, int m, int k, int day)
{
    int bqCnt = 0;
    int flowerCnt = 0;
    for (int bd : bloomDay)
    {
        // counting the consequetive flowers bloom at given day.
        if (day >= bd)
            flowerCnt++;
        else
            flowerCnt = 0;

        if (flowerCnt == k)
        {
            bqCnt++;
            flowerCnt = 0;
        }
    }

    return bqCnt >= m;
}
int minDays(vector<int> &bloomDay, int m, int k)
{

    // maxDay you have to wait to bloom all flower is maxElemnt from bloom day
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    int low = 1;

    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - mid) / 2;

        if (canMakeMbouquets(bloomDay, m, k, mid))
        {
            // if we can make bouquet at day mid, try to minimize serach space for minimum day
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main()
{

    return 0;
}