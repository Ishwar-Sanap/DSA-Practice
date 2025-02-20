#include <bits/stdc++.h>
using namespace std;

/*
    https://www.geeksforgeeks.org/problems/shortest-job-first/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-job-first


    Ex: 
         p1 p2 p3 p4
    bt = [6,8,7,3]
    output --> 7

    Avg. Waiting time = 
    (p4 wait time + p1 wait time + p3 wait time + p2 wait time)/4 = 
    ( 0 + 3 + 9 + 16)/4 = 28/7 = 4
*/
long long solve(vector<int> &bt)
{
    // code here

    //Sort the array, of burst time in incresing order, so minimum execution time process will be select at first.
    sort(bt.begin(), bt.end());

    int n = bt.size();

    long long totalWt = 0;
    long long wt = 0;

    for (int i = 1; i < n; i++)
    {
        wt += bt[i - 1];
        totalWt += wt;
    }

    return totalWt / n;
}
int main()
{

    return 0;
}