#include <bits/stdc++.h>
using namespace std;

// k = 3, arr[][] = {{1,2,3},{3,5,6},{7,8,9}}
// Output: 1 2 3 4 5 6 7 8 9

vector<int> merge2SortedArray(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> temp;
    int n = arr1.size(), m = arr2.size();
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
            temp.push_back(arr1[i++]);
        else
            temp.push_back(arr2[j++]);
    }

    while (i < n)
        temp.push_back(arr1[i++]);
    while (j < m)
        temp.push_back(arr2[j++]);

    return temp;
}
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    // code here
    vector<int> mergedArray = arr[0];
    int  n = arr.size();
    for(int i  = 1; i<n; i++)
    {
       mergedArray = merge2SortedArray(mergedArray,arr[i]);
    }


    return mergedArray;
}

int main()
{

    return 0;
}