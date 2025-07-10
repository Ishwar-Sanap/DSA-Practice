
//https://leetcode.com/problems/number-of-enclaves/
// Can be solved using BFS or DFS


class Solution
{
public:
    vector<vector<int>> visited;
    bool isSafe(int sr, int sc, vector<vector<int>> &board)
    {
        int n = board.size(), m = board[0].size();
        if (sr < 0 || sc < 0 || sr >= n || sc >= m)
            return false;
        return true;
    }

    void dfs(int sr, int sc, vector<vector<int>> &board)
    {
        visited[sr][sc] = 1;
        if (board[sr][sc] == 0)
            return;

        // Explore 4 directions

        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; i++)
        {
            int nri = dir[i][0] + sr;
            int nci = dir[i][1] + sc;

            if (isSafe(nri, nci, board) && !visited[nri][nci])
            {
                dfs(nri, nci, board);
            }
        }
    }

    void bfs(vector<vector<int>> &board)
    {
        int n = board.size(), m = board[0].size();
        queue<pair<int, int>> q;

        // Multi sources BFS

        // Horizontal boundaries
        for (int j = 0; j < m; j++)
        {
            if (board[0][j] == 1)
            {
                q.push({0, j});
                visited[0][j] = 1;
            }

            if (board[n - 1][j] == 1)
            {
                q.push({n - 1, j});
                visited[n - 1][j] = 1;
            }
        }

        // vertical boundaries
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 1)
            {
                visited[i][0] = 1;
                q.push({i, 0});
            }

            if (board[i][m - 1] == 1)
            {
                visited[i][m - 1] = 1;
                q.push({i, m - 1});
            }
        }

        while (!q.empty())
        {
            int sr = q.front().first;
            int sc = q.front().second;
            q.pop();
            // Explore 4 directions

            vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (int i = 0; i < 4; i++)
            {
                int nri = dir[i][0] + sr;
                int nci = dir[i][1] + sc;

                if (isSafe(nri, nci, board) && board[nri][nci] == 1 && !visited[nri][nci])
                {
                    q.push({nri, nci});
                    visited[nri][nci] = 1;
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>> &board)
    {

        int n = board.size(), m = board[0].size();
        visited.assign(n, vector<int>(m, 0));
        int cnt = 0;
        // Traverse through the every boundry and mark  1 as visited, as depth we can go..

        bfs(board);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && board[i][j] == 1)
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}