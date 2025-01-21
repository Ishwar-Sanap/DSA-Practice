#include <bits/stdc++.h>
using namespace std;

/*
You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Input: stalls[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows, in this case, is 4, which also is the largest among all possible ways.

You have to find all possible ways to place all k cows. And from each way takes the minimum distances between any two stalls, and find the maximum for all possible minimum distances..

C1 : 10 , C2 : 1 , C2 : 2 --> Way1 min distance = 1
C1 : 10, C2 : 1 , C3 : 7 --> Way2 min distance = 3
C1 : 10, C2 : 1 C3 : 5 --> way3 min distacne = 4
………..
There can be many ways to place k cows you have to find the maximum of min distances, 
In above case 4 is the only maximum answer possible

*/
bool canPlaceCows(vector<int> &stalls, int k, int dist)
{
    int n = stalls.size();
    int cowPlaced = 1, lastPlaceIndex = 0;
    // since array is sorted the minimum distance between any two stallas will be consequetive elements
    // best possible way to place 1cow is at first place since array is sorted.
    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - stalls[lastPlaceIndex] >= dist)
        {
            lastPlaceIndex = i;
            cowPlaced++;
        }

        if (cowPlaced == k)
            return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{

    // Write your code here
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 1;
    int high = stalls[n - 1];
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, k, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    // return ans;
    return high;
}
int main()
{

    return 0;
}