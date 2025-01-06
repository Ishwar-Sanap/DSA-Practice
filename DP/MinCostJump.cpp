#include <bits/stdc++.h>
using namespace std;

/*You are standing at index 0 of the array. You have to reach the last index N of the array 
in minimum cost ; you can only make 1 step or 2 step jumps. 
If you are jumping from index i to index j cost will be-> abs(b[i] - b[j]) 
Return the minimum cost to reach index N
*/

/*
    0  1  2   3  4  5
    10 30 20 20 50 40 

    dp[0] = 0  // you are at index 0, best cost to reach at 0 is ==> 0
    //At index 1 best cost to reach is 
    dp[1] = abs(arr[1] - arr[0]) = (30 - 10) ==> 20
    //At index 2 best cost to reach is
    we have 2 options : 
    op1 = we had came from single step jump (i.e abs(arr[i] - arr[i-1])+ dp[i-1])
    op2 = we had came form two step jump (i.e abs(arr[i] - arr[i-2] + dp[i-2]) )
    dp[2] = min(op1, op2) ==> 10  index(0 2)
    dp[3] = 10 ==> index(0 2 3)
    dp[4] = 40 ==> index(0 2 4 or 0 2 3 4)
    dp[5] = 30 ==> index(0 2 3 5)

*/ 
int minCost(vector<int>&arr)
{
    int n = arr.size();
    vector<int>dp(n , 0);

    dp[0] = 0 , dp[1] = abs(arr[0] - arr[1]);

    for(int i = 2; i<n; i++)
    {
        int op1 = abs(arr[i] - arr[i-1]) + dp[i-1];
        int op2 = abs(arr[i] - arr[i-2]) + dp[i-2];
        dp[i] =  min(op1 , op2);
    }
    return dp[n-1];
}

int minCostKjumps(vector<int>&arr , int k)
{
    int n = arr.size();
    vector<int>dp(n , 0);

    dp[0] = 0 , dp[1] = abs(arr[0] - arr[1]);

    for(int i = 2; i<n; i++)
    {
        int best_ans_Until = INT_MAX;
        
        int j = i-1;
        int cnt = 0;
        while(j>=0 && cnt < k)
        {
            best_ans_Until = min(best_ans_Until , abs(arr[i]-arr[j] + dp[j]));
            j--;
            cnt++;
        }
        dp[i] = best_ans_Until;
    }
    return dp[n-1];
}
int main()
{                   // 0   1  2   3   4   5
    vector<int>arr = {10 ,30, 20, 20, 50, 40 };
    cout << minCostKjumps(arr,2)<<endl;
    return 0;   
}