/*
Task given in problem is to Find Number of Pairs in array A, i and j ( i <j )
such that A[A[A[i]]] == A[A[A[j]]]
1<= A[i] <= N

arr ={4,2,1,2} 
*/

#include <bits/stdc++.h>
using namespace std;


int main()
{
    int cnt = 0;
    // added -1 dummy to consider 1 based indexing
    vector<int>arr = {-1,4,2,1,2}; 
    unordered_map<int,int>mp; 
    int j = 1; 
    while(j < arr.size())
    {
        int curr = arr[arr[arr[j]]];
        cnt += mp[curr];

        mp[curr]++;

        j++;
    }
    cout<<cnt<<endl;
    return 0;
}