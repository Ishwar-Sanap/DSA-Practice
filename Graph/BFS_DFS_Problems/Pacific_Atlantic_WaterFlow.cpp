#include <bits/stdc++.h>
using namespace std;

// Explore 4 directions
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// https://leetcode.com/problems/pacific-atlantic-water-flow/
void dfs(int ri, int ci, int prevHeight, vector<vector<int>> &heights, vector<vector<int>> &visited)
{
    int n = heights.size(), m = heights[0].size();
    if (ri < 0 || ci < 0 || ri >= n || ci >= m || visited[ri][ci] == 1)
        return;
    if (heights[ri][ci] < prevHeight)
        return; // water can't flow

    visited[ri][ci] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nri = ri + dr[i];
        int nci = ci + dc[i];

        dfs(nri, nci, heights[ri][ci], heights, visited);
    }
}
vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{

    int n = heights.size(), m = heights[0].size();

    vector<vector<int>> visitedPacific(n, vector<int>(m, 0));
    vector<vector<int>> visitedAtlantic(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        // Left Pacific Ocean
        if (!visitedPacific[i][0])
            dfs(i, 0, -1, heights, visitedPacific);

        // Right Atlacntic
        if (!visitedAtlantic[i][m - 1])
            dfs(i, m - 1, -1, heights, visitedAtlantic);
    }

    for (int j = 0; j < m; j++)
    {
        // Up Pacific ocean
        if (!visitedPacific[0][j])
            dfs(0, j, -1, heights, visitedPacific);

        // down Atlantic ocean
        if (!visitedAtlantic[n - 1][j])
            dfs(n - 1, j, -1, heights, visitedAtlantic);
    }

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visitedPacific[i][j] && visitedAtlantic[i][j])
                ans.push_back({i, j});
        }
    }

    return ans;
}

int main()
{
    return 0;
}