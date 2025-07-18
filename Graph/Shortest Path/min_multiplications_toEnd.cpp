#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

/*
Input:
arr[] = {2, 5, 7}
start = 3, end = 30
Output:
2
Explanation:
Step 1: 3*2 = 6 % 100000 = 6
Step 2: 6*5 = 30 % 100000 = 30
*/
class Solution
{
public:
    int mod = 100000;
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        // code here

        // mod will be applicable for mutiplilcations greter than 100000

        vector<int> visited(99999, 0);

        // {steps, multi)
        queue<pair<int, int>> q;
        q.push({0, start});
        visited[start] = 1;

        while (!q.empty())
        {
            int steps = q.front().first;
            int multi = q.front().second;
            q.pop();

            if (multi == end)
                return steps;

            for (int num : arr)
            {
                int newStart = (multi * num) % mod;

                if (!visited[newStart])
                {
                    visited[newStart] = 1;
                    q.push({steps + 1, newStart});
                }
            }
        }

        return -1;
    }
};

int main()
{
    return 0;
}