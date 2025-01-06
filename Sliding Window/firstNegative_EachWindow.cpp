#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

Note: If a window does not contain a negative integer, then return 0 for that window.

Input: arr[] = [12, -1, -7, 8, -15, 30, 16, 28] , k = 3
Output: [-1, -1, -7, -15, -15, 0]


*/
vector<int> FirstNegativeInteger(vector<int> &arr, int k)
{
    // write code here

    int n = arr.size();
    int i = 0, j = 0;
    vector<int> res;
    // queue to store indices of negative elemetns
    queue<int> qu;
    while (j < n)
    {
        if (arr[j] < 0)
            qu.push(j);

        if (j - i + 1 < k)
            j++;
        else
        {
            if (qu.size() > 0)
                res.push_back(arr[qu.front()]);
            else
                res.push_back(0);

            while (qu.size() > 0 && qu.front() <= i)
                qu.pop();

            i++;
            j++;
        }
    }
    return res;
}
int main()
{

    return 0;
}