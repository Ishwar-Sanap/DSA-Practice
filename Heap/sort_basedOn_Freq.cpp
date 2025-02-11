#include <bits/stdc++.h>
using namespace std;

/*
https://www.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0

Given an array A[] of integers, sort the array according to frequency of elements. That is elements 
that have higher frequency come first. If frequencies of two elements are same, then smaller number
comes first.
*/
struct comp
{
    bool operator()(pair<int, int> &ele1, pair<int, int> &ele2)
    {
        if (ele2.second > ele1.second)
            return true; // do swap
        else if (ele2.second == ele1.second)
        {
            return ele2.first < ele1.first; // do swap
        }

        return false;
    }
};

void sortBasedOnFreq(vector<int> &arr)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

    unordered_map<int, int> mp;

    for (int ele : arr)
        mp[ele]++;

    for (auto it : mp)
        pq.push({it.first, it.second});

    while (!pq.empty())
    {
        int ele = pq.top().first;
        int freq = pq.top().second;

        pq.pop();

        while (freq-- > 0)
        {
            cout << ele << " ";
        }
    }
    cout << endl;
}
int main()
{
    // code
    int tc = 0;
    cin >> tc;

    while (tc-- > 0)
    {
        int n = 0;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sortBasedOnFreq(arr);
    }
    return 0;
}