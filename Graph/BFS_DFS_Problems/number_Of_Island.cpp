#include <bits/stdc++.h>
using namespace std;

/*
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid)
consisting of 'W's (Water) and 'L's (Land). Find the number of islands.

https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1
*/

class Solution
{
public:
    vector<vector<int>> visited;

    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] == 1)
            return;
        if (grid[i][j] == 'W')
            return;

        visited[i][j] = 1;

        // Vertical
        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);

        // diagonally
        dfs(i - 1, j - 1, grid);
        dfs(i - 1, j + 1, grid);

        dfs(i + 1, j - 1, grid);
        dfs(i + 1, j + 1, grid);

        // Horizantally
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }

    bool isvalidMove(int i, int j, vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] == 1 || grid[i][j] == 'W')
            return false;

        return true;
    }
    void bfs(int i, int j, vector<vector<char>> &grid)
    {
        queue<pair<int, int>> qNodes;
        qNodes.push({i, j});
        visited[i][j] = 1;

        while (!qNodes.empty())
        {
            i = qNodes.front().first;
            j = qNodes.front().second;

            qNodes.pop();

            // Explore all 8 possible directions neighbours for i and j
            for (int m1 = -1; m1 <= 1; m1++)
            {
                for (int m2 = -1; m2 <= 1; m2++)
                {
                    if (isvalidMove(i + m1, j + m2, grid))
                    {
                        qNodes.push({i + m1, j + m2});
                        visited[i + m1][j + m2] = 1;
                    }
                }
            }
        }
    }
    int countIslands(vector<vector<char>> &grid)
    {
        // Code here

        int n = grid.size(), m = grid[0].size();
        visited.assign(n, vector<int>(m, 0));
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'L' && !visited[i][j])
                {
                    cnt++;
                    // dfs(i, j, grid);
                    bfs(i, j, grid);
                }
            }
        }

        return cnt;
    }
};
int main()
{
    return 0;
}