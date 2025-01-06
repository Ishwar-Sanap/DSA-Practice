#include <bits/stdc++.h>
using namespace std;
/*
ind the count. of subarray of shortest length whose sum==k
A = {10,5,2,7,1,9,8,7}   k = 15
Subarrays having sum = 15 , {10,5} , {5,2,7,1} , {8,7}
Smallest length of subarray having sum 15 is 2 and there are two such subarrays :
{10,5} | {8,7}
Hence the count and output is 2.

10 5 2 3  10  -10  k = 10

*/

// Initially find the shoretest length subarray having sum k
// store all subarray length has sum k
// cnt subarray whose len == shoretest length subarray having sum k
int getCnt(vector<int> &arr, int k)
{
    int n = arr.size() , cnt = 0;
    unordered_map<int, int> preFixSum;
    vector<int> SumKSubarrayLengths;

    preFixSum[0] = -1;
    int shortestLen = n + 1;

    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        int req = currSum - k;

        if (preFixSum.find(req) != preFixSum.end())
        {
            int len = i - preFixSum[req];
            SumKSubarrayLengths.push_back(len); // push all subarray having length k

            shortestLen = min(shortestLen, len);
        }

        preFixSum[currSum] = i; // As we want Shortest subarray so update currSum every time
    }

    for(int length : SumKSubarrayLengths)
    {
        if(length == shortestLen)
        cnt++;
    }
    return cnt;
}

int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, 9, 8, 7};
    int k = 15;

    cout << getCnt(arr, k) << endl;
    return 0;
}