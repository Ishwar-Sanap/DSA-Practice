#include <bits/stdc++.h>
using namespace std;

bool canFinishAllPiles(vector<int> &piles, int h, int k)
{
    int n = piles.size();
    long cntHr = 0;
    for (int i = 0; i < n; i++)
    {
        cntHr += piles[i] / k;
        if (piles[i] % k != 0)
            cntHr++;
    }
    // if eating hour count is less that or equl to given h then koko can finished all piles
    return cntHr <= h;
}
int minEatingSpeed(vector<int> &piles, int h)
{

    // as koko needs to eat minimum banana's per hr and finished all piles,
    // at max she has to eat at speed of maxElemt/hr to finish all piles, Once search space identified
    // we can optimally reduce it using binary search

    int high = *max_element(piles.begin(), piles.end());
    int low = 1, ans = 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canFinishAllPiles(piles, h, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    // return low;
    return ans;
}

int main()
{

    return 0;
}