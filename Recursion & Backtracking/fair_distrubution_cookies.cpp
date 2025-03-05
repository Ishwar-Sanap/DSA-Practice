#include <bits/stdc++.h>
using namespace std;

int solve(int index, vector<int> &cookies, vector<int> &childrens, int k)
{
    if (index == cookies.size())
    {
        int unfairness = *max_element(childrens.begin(),childrens.end());
        return unfairness;
    }

    int minUnfairness = INT_MAX;
    for (int i = 0; i < k; i++)
    {
        childrens[i] += cookies[index]; // giving curret cooki to ith children
       int unfairness =  solve(index + 1, cookies, childrens, k);
       minUnfairness = min(minUnfairness , unfairness);

        childrens[i] -= cookies[index]; // backtrack
    }

    return minUnfairness;
}

int distributeCookies(vector<int> &cookies, int k)
{
    vector<int> childrens(k, 0);

    return solve(0,cookies,childrens,k);
}

int main()
{

    return 0;
}