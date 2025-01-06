#include <bits/stdc++.h>
using namespace std;

/*
Amazon Delivery agent want to deliver packages store in warehouse in minimum trips :
In single trip he can choose :
    - two packages with same weight
    - three packages with same weight
Determine the min of trips required to deliver all packages If it is not possible return -1

Ex: packageWeights = {2,4,6,6,4,2,4} output : 3
2->2
4->3
6->2
*/

int minTrips(vector<int> &weights)
{
    unordered_map<int, int> mp;
    for (int w : weights)
        mp[w]++;

    int ans = 0;
    for (auto it : mp)
    {
        int freq = it.second;
        if (freq == 1) // Not possible
            return -1;
        else
        {
            // ex: freq 6 , 11 , 15 , 16
            ans += freq/3;
            if(freq %3 != 0)
                ans++;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 5, 5, 1, 1, 8, 8, 10, 10};
    cout << minTrips(arr) << endl;
    return 0;
}