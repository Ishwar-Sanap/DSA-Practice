#include <bits/stdc++.h>
using namespace std;
// We are given an array of integers(a[n]) . We are given multiple queries of the form : (0, i) 
//which means we need to output the sum of all numbers from index- ‘0’ to index ‘i’ of the array.
void getSum(vector<int>&arr, vector<int>&query)
{
    int n = arr.size();

    vector<int>dp(n,-1);
    dp[0] = arr[0];

    for(int i =1; i<n; i++)
        dp[i] = arr[i] + dp[i-1];

    for(int q : query)
        cout<<dp[q]<< " ";
}

int main()
{
    vector<int>arr = {2,3,2,2,1,1,2};
    vector<int>query = {2,5,3}; // indexing 0 based

    getSum(arr,query);
    return 0;
}