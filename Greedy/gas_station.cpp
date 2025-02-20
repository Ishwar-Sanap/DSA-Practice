#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/gas-station/description/
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3

*/
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int totalGas = accumulate(gas.begin(), gas.end(), 0);
    int totalCost = accumulate(cost.begin(), cost.end(), 0);

    // not possible
    if (totalCost > totalGas)
        return -1;

    int n = cost.size();

    int currGas = 0, start = 0;
    for (int i = 0; i < n; i++)
    {
        currGas = currGas + gas[i] - cost[i];

        if (currGas < 0)
        {
            start = i + 1;
            currGas = 0;
        }
    }

    return start;
}

int main()
{

    return 0;
}