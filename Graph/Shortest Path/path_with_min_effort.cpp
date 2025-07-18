#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/path-with-minimum-effort/description/

typedef pair<int, int> pii;

int minimumEffortPath(vector<vector<int>> &heights)
{
    int n = heights.size(), m = heights[0].size();

    // starting source node as (0, 0) and destination node as (n-1, m-1)

    // Initially assigning the Infinite distance..
    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    // {dist, {ri, ci}} stored in priority queue
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

    // pushing the source node
    //{dist, {ri, ci}}
    pq.push({0,{0,0}});
    dist[0][0] = 0;

    // Prioirty queue will always make sure store on top the min efforts from all possible paths.

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int currEffort = it.first, ri = it.second.first, ci = it.second.second;

        if (ri == n - 1 && ci == m - 1)
            return currEffort;

        // Explore the neighbors , as each cell have 4 adjacent neighbors
        vector<pii> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto dir : dirs)
        {
            int nri = dir.first + ri;
            int nci = dir.second + ci;

            // If Valid adjacent neighbors
            if (nri >= 0 && nci >= 0 && nri < n && nci < m)
            {
                int adjEffort = abs(heights[nri][nci] - heights[ri][ci]);

                // On path we should take max effort
                int effort = max(currEffort, adjEffort);

                if (effort < dist[nri][nci])
                {
                    dist[nri][nci] = effort;
                    pq.push({effort, {nri, nci}}); ////{dist, {nri, nci}}
                }
            }
        }
    }

    return -1;
}
int main()
{
    return 0;
}