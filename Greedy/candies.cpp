#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/candy/

[1 ,2 ,10, 10, 10 ,2  ,1]
Output --> 13

*/

int candyApproch1(vector<int> &ratings)
{

    // 1 2 10 10 10 2  1

    int n = ratings.size();
    vector<int> givenCandies(n, 1);

    // Traveseing Left to Right
    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
            givenCandies[i] = 1 + givenCandies[i - 1]; // giving more candies than neighbour
    }

    // Traversing Right to left
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
            givenCandies[i] = max(givenCandies[i], 1 + givenCandies[i + 1]); // giving more candies than neighbour
    }

    int minCandiesToGive = 0;
    for (int i = 0; i < n; i++)
    {
        minCandiesToGive += givenCandies[i];
    }

    return minCandiesToGive;
}

// T.C O(N)
// S.C O(1)

int candyApproach2(vector<int> &ratings)
{
    int n = ratings.size();

    int minCandiesToGive = n; // giving 1 candy to each child
    int i = 1;

    while (i < n)
    {
        if (ratings[i] == ratings[i - 1])
        {
            i++;
            continue;
        }

        int peek = 0;
        while (i < n && ratings[i] > ratings[i - 1])
        {
            peek++;
            minCandiesToGive += peek;
            i++;
        }

        int deep = 0;
        while (i < n && ratings[i] < ratings[i - 1])
        {
            deep++;
            minCandiesToGive += deep;
            i++;
        }

        minCandiesToGive -= min(deep, peek); // removing duplicates added
    }

    return minCandiesToGive;
}

int main()
{

    return 0;
}