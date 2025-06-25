#include <bits/stdc++.h>
using namespace std;

// MCM  : matrix chain 
//https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1 
/*
let suppose ther are 3 matrix  ABC
possible ways to partition : 
1) A|BC      2) AB|C 
1) (A)(BC)   2) (AB)C

No of multpilication steps when you 2 matrices are multiplied
--> A(2*3) * B(3*4) 
--> = 2*3*4 = 24

*/

// T.C O(N*N*N) S.C --> O(N*N) + O(N) recursion stack space
// f(i,j) --> min operations to get the product of matrices ai...aj
int tryAllWays(int i, int j, vector<int> &arr,  vector<vector<int>>&dp)
{
    if (i == j)
        return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int minCost = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int steps = (arr[i - 1] * arr[k] * arr[j]);
        int leftPart = tryAllWays(i, k, arr,dp);
        int righPart = tryAllWays(k + 1, j, arr,dp);

        steps += leftPart + righPart;

        minCost = min(minCost, steps);
    }

    return dp[i][j] =  minCost;
}

// Tabulation : T.C O(N*N*N) S.C --> O(N*N) 
int matrixMultiplication_T(vector<int>&arr)
{
    int n = arr.size();
    vector<vector<int>>dp(n, vector<int>(n,0));

    for(int i = n-1; i>= 1; i--)
    {
        for(int j = i; j<n; j++ )
        {
            if(i == j) continue;

            int minCost = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int steps = (arr[i - 1] * arr[k] * arr[j]);
                int leftPart = dp[i][k];
                int righPart = dp[k+1][j];
        
                steps += leftPart + righPart;
        
                minCost = min(minCost, steps);
            }
        
             dp[i][j] =  minCost;
        }
    }

    return dp[1][n-1];
}

int matrixMultiplication(vector<int> &arr)
{
    // code here
    int n = arr.size();
    vector<vector<int>>dp(n, vector<int>(n,-1));
    // return tryAllWays(1, n - 1, arr,dp);
    return matrixMultiplication_T(arr);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 3};
    cout << matrixMultiplication(arr) << endl;

    return 0;
}