#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

/*
https://www.naukri.com/code360/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION

    vector<int> arr = {1, 2, 1, 2};  , d = 2
    Output --> 3
    Since : S[ 1 , 2 , 1] - S[ 2] = 2  ,
    S[2, 2] - S[1, 1] = 2 ,
    S[1, 1 , 2] - S[2]   = 2

    3 possible partitions....

*/
// vector<int> cntSubsetWithSumk(int k, vector<int> &arr)
int cntSubsetWithSumk(int k, vector<int> &arr)
{
    int n = arr.size();
    vector<int> prevRow(k + 1, 0);
    vector<int> currRow(k + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int sum = 0; sum <= k; sum++)
        {
            // base case..
            // we have to go till the 0th index for counting all subsets...
            if (i == 0)
            {
                // try the both pick and non pick her
                int pick = (sum - arr[i] == 0) ? 1 : 0;
                int nonPick = (sum == 0) ? 1 : 0;

                currRow[sum] = pick + nonPick;
                continue;
            }

            int pick = 0, notPick = 0;

            if (arr[i] <= sum)
                pick = prevRow[sum - arr[i]];

            notPick = prevRow[sum];

            currRow[sum] = (pick + notPick) % mod;
        }
        prevRow = currRow;
    }

    // return prevRow;
    return prevRow[k];
}
/*
int countPartitions(int n, int d, vector<int> &arr)
{
    // Write your code here.
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    vector<int> possibleSumsSubsetCnt = cntSubsetWithSumk(totalSum, arr);

    int cntPartitions = 0;
    for (int sum = 0; sum <= totalSum / 2; sum++)
    {
        if (possibleSumsSubsetCnt[sum] > 0)
        {
            int s2 = totalSum - sum;

            if (s2 - sum == d)
            {
                cntPartitions = (cntPartitions + possibleSumsSubsetCnt[s2]) % mod;
            }
        }
    }

    return cntPartitions;
}
*/
// More optimized
int countPartitions(int n, int d, vector<int> &arr)
{
    // Write your code here.
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    /*
        totalSum = s1 + s2  ---> eq 1
        we, have given diff , i,e diff = s1 - s2 --> eq 1

        // by solving above 2 equations..
        s2 = (totalsum - diff)/2

        so now we have to find only no of subets with sum s2
    */
    // vector<int> possibleSumsSubsetCnt = cntSubsetWithSumk(totalSum, arr);

    // Edge cases
    if (totalSum - d < 0 || (totalSum - d) % 2)
        return 0;

    int s2 = (totalSum - d) / 2;
    int cntPartitions = cntSubsetWithSumk(s2, arr);

    return cntPartitions;
}

int main()
{
    vector<int> arr = {1, 2, 1, 2};
    cout << countPartitions(4, 2, arr);
    return 0;
}