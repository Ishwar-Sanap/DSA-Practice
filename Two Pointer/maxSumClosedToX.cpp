#include <bits/stdc++.h>
using namespace std;

/*
You are given two sorted arrays both arrays were of size N you have to find a pair of numbers such that sum of those numbers <=x and as close as possible to x

x = 32

A = 10 20 30 40
B = 1 4 5 7

Output : 31 (31(1 + 30) is only sum is as close as possible to x)

*/

int getClosedPossibleSum(vector<int> &arr1, vector<int> &arr2, int x)
{
    int ans = INT_MIN;
    int n = arr1.size();
    int i = 0, j = n - 1;

    while (i < n && j >= 0)
    {
        int pairSum = arr1[i] + arr2[j];
        if (pairSum <= x)
        {
            ans = max(ans, pairSum);
            i++;
        }
        else
            j--;
    }

    return ans;
}

int main()
{
    vector<int>arr1 = {10 ,20, 30, 40};
    vector<int>arr2 = {1, 4, 5, 7};

    cout<<getClosedPossibleSum(arr1,arr2,32)<<endl;
    return 0;
}