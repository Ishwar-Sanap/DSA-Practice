#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/01-matrix/description/ 

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> ans(n, vector<int>(m, 0));
    vector<vector<int>> visited(n, vector<int>(m, 0));

    // BFS Traversal
    queue<pair<pair<int, int>, int>> qNodes; // queue will store, the position and nearest 0's count

    // we will start from 0's as source nodes to finding the nearest 1's

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                visited[i][j] = 1;
                qNodes.push({{i, j}, 0});
            }
        }
    }

    while (!qNodes.empty())
    {
        int ri = qNodes.front().first.first;
        int ci = qNodes.front().first.second;
        int steps = qNodes.front().second;

        qNodes.pop();

        // store the ans
        ans[ri][ci] = steps;

        // Explore adjacent neighbors in 4 direction
        int deltaRow[] = {-1, 1, 0, 0};
        int deltaCol[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int nri = ri + deltaRow[i];
            int nci = ci + deltaCol[i];

            if (nri >= 0 && nci >= 0 && nri < n && nci < m)
            {
                if (!visited[nri][nci])
                {
                    qNodes.push({{nri, nci}, steps + 1}); // steps + 1, means (nri, nci) node postion belongs to next level..
                    visited[nri][nci] = 1;
                }
            }
        }
    }

    return ans;
}
int main()
{
     vector<vector<int>>dir ={{-1,0}, {1,0}, {0,-1}, {0,1} };
        
    return 0;
}