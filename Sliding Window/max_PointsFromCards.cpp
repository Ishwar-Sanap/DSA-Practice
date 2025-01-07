#include <bits/stdc++.h>
using namespace std;
/*
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12

 cardPoints = [3 1 4 5  1  6  2] , k = 3
 output : 11
*/

int main()
{

    return 0;
}

int maxScore(vector<int> &cardPoints, int k)
{

    // 3 1 4 5  1  6  2
    // total sum == 22
    //
    // Think of inversly
    /*
    - As you only have choice to pick either from front or back of array
    - You have to optimally choose element from front and back but we cna't
        decide, based on current elemetn what will be further elments max of min that will increse sum
    - But what if we figured out the sub array that need to remove and remaining element sum will be max
    - i.e we have to find subarray of size (n - k) which has minimum sum, if we remove that sum from total sum
       you will get the maxSocre that can be achieved by selecing element from front or back.
    - Make sure to handle case for when k == n, in this case total sum is maxScore.

    */
    int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
    int n = cardPoints.size(), i = 0, j = 0;

    if (k == n)
        return totalSum; // Corner case when n == k
    int currSum = 0, minSum = INT_MAX;
    // find the minimum sum of subarray having size n-k
    while (j < n)
    {
        currSum += cardPoints[j];

        if (j - i + 1 < (n - k))
            j++;

        else
        {
            minSum = min(minSum, currSum);
            currSum -= cardPoints[i];

            i++;
            j++;
        }
    }

    return totalSum - minSum;
}