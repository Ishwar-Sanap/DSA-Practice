// User function Template for C++

#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution
{
public:
    vector<vector<int>> visited;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(int i, int j, int pi, int pj, vector<vector<int>> &grid, vector<pair<int, int>> &cordinates)
    {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] == 1 || grid[i][j] == 0)
            return;
        visited[i][j] = 1;

        cordinates.push_back({i - pi, j - pj});

        // Explore 4 neighbors
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto dir : dirs)
        {
            dfs(i + dir[0], j + dir[1], pi, pj, grid, cordinates);
        }
    }

    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // code here

        int n = grid.size(), m = grid[0].size();
        visited.assign(n, vector<int>(m, 0));

        // to store unique islands
        set<vector<pair<int, int>>> st;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j])
                {
                    vector<pair<int, int>> cordinates;
                    dfs(i, j, i, j, grid, cordinates);

                    if (cordinates.size() > 0)
                    {
                        st.insert(cordinates);
                    }
                }
            }
        }

        return st.size();
    }
};

int main()
{
    int grid[][5] = {{1, 1, 0, 1, 1},
                     {1, 0, 0, 0, 0},
                     {0, 0, 0, 0, 1},
                     {1, 1, 0, 1, 1}};

    return 0;
}