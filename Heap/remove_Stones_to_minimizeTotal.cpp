#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/

/*
Input: piles = [4,3,6,7], k = 3
Output: 12
*/
int minStoneSum(vector<int> &piles, int k)
{
    // Choose the pile with the maximum number of stones each time.
    priority_queue<int> pq(piles.begin(), piles.end());

    while (k--)
    {
        int maxPile = pq.top();
        pq.pop();

        int op = (maxPile + 1) / 2;
        pq.push(op);
    }

    int minSum = 0;
    while (!pq.empty())
    {
        minSum += pq.top();
        pq.pop();
    }

    return minSum;
}

int main()
{

    return 0;
}