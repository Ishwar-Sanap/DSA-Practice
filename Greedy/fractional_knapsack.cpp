#include <bits/stdc++.h>
using namespace std;

/*
https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
Output: 240.000000
*/
static bool comp(pair<int, int> it1, pair<int, int> it2)
{
    // sorting based on val/wt , in decresing order

    double div1 = (double)it1.first / it1.second;
    double div2 = (double)it2.first / it2.second;

    if (div2 > div1)
        return false;
    else if (div2 == div1)
    {
        // based on weights, smaller weights should be at first
        return it2.second > it1.first;
    }

    return true;
}

double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
{

    double ans = 0.0;

    // Your code here
    int n = wt.size();
    vector<pair<int, int>> items;

    for (int i = 0; i < n; i++)
    {
        items.push_back({val[i], wt[i]});
    }

    sort(items.begin(), items.end(), comp);

    for (auto item : items)
    {
        // cout<<item.first<< "  "<<item.second<<endl;

        if (item.second <= capacity)
        {
            // take whole value of curretn weight
            ans += item.first;
            capacity -= item.second;
        }
        else
        {

            // curretn weight is larger than capacity, so take in fraction
            if (capacity >= 0)
                ans += (((double)item.first / item.second) * capacity);

            break;
        }
    }

    return ans;
}

int main()
{

    return 0;
}