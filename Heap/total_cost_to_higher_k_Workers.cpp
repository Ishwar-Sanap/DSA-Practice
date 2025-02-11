#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/total-cost-to-hire-k-workers/

/*
Input: costs = [17,12,10,2,7,2,11,20,8], k = 3, candidates = 4
Output: 11

*/
long long totalCost(vector<int> &costs, int k, int candidates)
{

    priority_queue<int, vector<int>, greater<int>> pqLeft, pqRight;

    long long total = 0;
    int n = costs.size();
    int i = 0, j = n - 1;
    while (k-- > 0)
    {

        while (pqLeft.size() < candidates && i <= j)
            pqLeft.push(costs[i++]);

        while (pqRight.size() < candidates && i <= j)
            pqRight.push(costs[j--]);

        int leftMin = pqLeft.empty() ? INT_MAX : pqLeft.top();
        int rightMin = pqRight.empty() ? INT_MAX : pqRight.top();

        if (leftMin <= rightMin)
        {
            total += leftMin;
            pqLeft.pop();
        }
        else
        {
            total += rightMin;
            pqRight.pop();
        }
    }

    return total;
}
int main()
{

    return 0;
}