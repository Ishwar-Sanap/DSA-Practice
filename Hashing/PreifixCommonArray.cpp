#include <bits/stdc++.h>
using namespace std;

/*
You are given two 0-indexed integer permutations A and B of length n.

A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.

Return the prefix common array of A and B.

A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

Input: A = [1,3,2,4], B = [3,1,2,4]
Output: [0,2,3,4]
*/
vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    vector<int> prefixCommon(n, 0);

    unordered_map<int, int> mp;
    int commonCnt = 0;
    for (int i = 0; i < n; i++)
    {
        mp[A[i]]++;
        if (mp[A[i]] == 2)
            commonCnt++;

        mp[B[i]]++;
        if (mp[B[i]] == 2)
            commonCnt++;

        prefixCommon[i] = commonCnt;
    }
    return prefixCommon;
}
int main()
{

    return 0;
}