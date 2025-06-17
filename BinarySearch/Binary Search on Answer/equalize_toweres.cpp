#include <bits/stdc++.h>
using namespace std;

/*
https://www.geeksforgeeks.org/problems/equalize-the-towers2804/1

You are given an array heights[] representing the heights of towers and another array cost[] where each element represents the cost of modifying the height of respective tower.

The goal is to make all towers of same height by either adding or removing blocks from each tower.
Modifying the height of tower (add or remove) 'i' by 1 unit costs cost[i].
Return the minimum cost to equalize the heights of all towers.

Input: heights[] = [7, 1, 5], cost[] = [1, 1, 1]
Output: 6
Explanation: The minimum cost to equalize the towers is 6, achieved by setting all towers to height 5
*/

/*
Logic:
    - Binary Search on answer where, condition is not there to decide on which part of the search space should move..

-In this problem we have make heights of all towers equal but what height we should choose to make all other equal
 can't be decide.. So we will try going all heights [0 max(heights)]  i.e [1 7] is our search space..

-We will apply BS on given search space and using mid find the what cost will it required to make all heights equal to mid

- Here for each mid associated cost is plotted 
1 -> 10 , 2 -> 9, 3->8 ,4->7, 5->6, 6->7, 7->8
	
If we compare cost assosited with mid and mid+1 then 
We can decide on which serach space we should go.. 
If mid+1 cost < mid cost then s = md+1 , else e = mid-1

*/
int getCostToMakeHeightMid(vector<int> &heights, vector<int> &cost, int ht)
{
    int n = heights.size();

    int costT = 0;
    for (int i = 0; i < n; i++)
    {
        costT += (abs(ht - heights[i]) * cost[i]);
    }

    return costT;
}
int minCost(vector<int> &heights, vector<int> &cost)
{
    // code here

    // 1 2 3
    // 90 90 100 --> 270 (90*2 + 90 + 0)
    // 90+ 100 --> 190  (90 + 0 + 100)

    int s = 0, e = *max_element(heights.begin(), heights.end());

    int ans = INT_MAX;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        int cost1 = getCostToMakeHeightMid(heights, cost, mid);
        int cost2 = getCostToMakeHeightMid(heights, cost, mid + 1);

        ans = min({ans, cost1, cost2});

        if (cost2 < cost1)
            s = mid + 1;
        else
            e = mid - 1;
    }

    return ans;
}

int main()
{

    return 0;
}