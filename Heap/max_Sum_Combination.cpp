#include <bits/stdc++.h>
using namespace std;

/*
Given two integer array A and B of size N each.
A sum combination is made by adding one element from array A and another element of array B.
Return the maximum K valid sum combinations from all the possible sum combinations.

Note : Output array must be sorted in non-increasing order.
*/
vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> s; // to sotre unique indices

    int maxSum = A[N - 1] + B[N - 1];
    pq.push({maxSum, {N - 1, N - 1}});
    s.insert({N - 1, N - 1});

    vector<int> res;
    while (K--)
    {
        maxSum = pq.top().first;
        res.push_back(maxSum);

        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();

        if (s.find({i - 1, j}) == s.end()) // these indices not previously taken
        {
            int currSum = A[i - 1] + B[j];
            pq.push({currSum, {i - 1, j}});
            s.insert({i - 1, j});
        }

        if (s.find({i, j - 1}) == s.end()) // these indices not previously taken
        {
            int currSum = A[i] + B[j - 1];
            pq.push({currSum, {i, j - 1}});
            s.insert({i, j - 1});
        }
    }

    return res;
}
int main()
{

    return 0;
}