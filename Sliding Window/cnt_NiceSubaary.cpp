#include <bits/stdc++.h>
using namespace std;

/*
//  5 3 2 1 4 2 1 5 7 k = 3
    // 0 1 2 2 3 3 3 4 5

    // [1,1,2,1,3]  k = 2
    // [1 1]  [1 1 2] [1 2 1] [2 1 3] [1 3]

    // 2 4 6 1 3 5 6 7 k = 2
    // output 9

Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.
*/
int numberOfSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();

    int currOddCnt = 0, subArrayCnt = 0;
    int i = 0, j = 0;
    // this will store all odd indices and from front we get starting index of first odd element
    queue<int> oddIndices;
    while (j < n)
    {
        if (nums[j] % 2 != 0)
            oddIndices.push(j);

        if (oddIndices.size() < k)
            j++;

        else
        {
            if (oddIndices.size() > k)
            {
                int firstOddIndex = oddIndices.front();
                oddIndices.pop();

                i = firstOddIndex + 1;
            }
            if (oddIndices.size() == k)
            {
                // from left add all possible subarray
                int possible = (oddIndices.front() - i) + 1;
                subArrayCnt += possible;
            }

            j++;
        }
    }

    return subArrayCnt;
}

int main()
{

    return 0;
}