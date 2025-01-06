#include <bits/stdc++.h>
using namespace std;

/*
You are given an array and integer k 
for each index i you can perform operation only once  : a[i] + x where x ==> [-k to k] range
You have to determine the length of longest subsequence of array having equal numbers
ex: arr = {5, 8, 10} k = 3
5+3 , 8+0, 10-2
8 , 8 , 8 ==>>  maxLen --> 3

Constraints: 
1<=N<=100000
1<=k<=100000
100000>= A[i] >= k+1
*/

int maxLength(vector<int>&arr, int k)
{
    int maxEle = *max_element(arr.begin() , arr.end());
    vector<int>PreSum(maxEle+k+2, 0);// creating laregest possible array
    int ans = 1;
    for(int num : arr)
    {
        //From num we can make possible number in range L-R
        int L = num - k;
        int R = num+ k;
        //Range update Trick
        PreSum[L] = PreSum[L]+1;
        PreSum[R+1] = PreSum[R+1]-1;
    }

    //Calculate prefixSum, max element from prefixSum is
    // maxLength where we can have equal elements
    for(int i = 1; i<PreSum.size(); i++)
    {
        PreSum[i] =  PreSum[i-1]+ PreSum[i];
        ans = max(ans, PreSum[i]);
    }

    return ans;
}
int main()
{
    vector<int>arr = {5, 8, 10};
    cout<<maxLength(arr,3)<<endl;
    return 0;
}