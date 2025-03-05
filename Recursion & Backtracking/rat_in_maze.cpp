#include <bits/stdc++.h>
using namespace std;

/*
T.C --> O(4^(N×M)) because each cell can explore up to 4 different directions recursively.
s.C -->  O(N × M) The maximum recursion depth is (if we traverse all cells in a single path).
*/
void tryAllPossiblePaths(int rowIndx, int colIndx, string path, vector<vector<int>> &mat, vector<string> &ans)
{
    
    // check boundaries
    if (rowIndx < 0 || colIndx < 0 || rowIndx >= mat.size() || colIndx >= mat[0].size() ||
        mat[rowIndx][colIndx] == 0 || mat[rowIndx][colIndx] == 2)
        return;
    
    if (rowIndx == mat.size()-1 && colIndx == mat[0].size()-1)
    {
        ans.push_back(path);
        return;
    }


    int temp = mat[rowIndx][colIndx];
    mat[rowIndx][colIndx] = 2; // mark as visited

    // try all possible directions
    tryAllPossiblePaths(rowIndx + 1, colIndx, path + 'D', mat, ans);
    tryAllPossiblePaths(rowIndx, colIndx + 1, path + 'R', mat, ans);
    tryAllPossiblePaths(rowIndx, colIndx - 1, path + 'L', mat, ans);
    tryAllPossiblePaths(rowIndx - 1, colIndx, path + 'U', mat, ans);

    mat[rowIndx][colIndx] = temp; // umarked
}
vector<string> findPath(vector<vector<int>> &mat)
{
    // code here
    string path = "";
    vector<string> ans;

    tryAllPossiblePaths(0, 0, path, mat, ans);
    return ans;
}
int main()
{
    vector<vector<int>> mat = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans = findPath(mat);

    for(string path: ans)
        cout<<path<<endl;

    return 0;
}