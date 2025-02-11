#include <bits/stdc++.h>
using namespace std;

/*
Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths. 

Examples:

Input: arr[] = [4, 3, 2, 6]
Output: 29

https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

*/
int minCost(vector<int> &arr)
{
    // code here

    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());

    int total_Cost = 0;
    while (pq.size() > 1)
    {
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();

        total_Cost += (min1 + min2);
        pq.push((min1 + min2));
    }

    return total_Cost;
}

int main()
{

    return 0;
}