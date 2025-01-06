#include <bits/stdc++.h>
using namespace std;
/*
ou are Given an integer array A of size N. Your task is to select exactly B elements from either the left end or the right end of the array A in order to maximize the sum of the selected elements.

Here are the details of the problem:

You are given an integer array A of size N where 1 <= N <= 10^5.
You need to select exactly B elements from either the left end or the right end of the array A.
The goal is to find and return the maximum possible sum of elements you can pick.

[5, -2, 3, 1, 2], 3
output : 8

4 5 8 1 2 5 4 1 3 2 10
*/

int maxSum(vector<int>arr , int B)
{
    int n = arr.size();
    int totalSum = 0;
    int maxSum = INT_MIN;

    unordered_map<int,int>preFixSum;
    for(int i = 0; i<n; i++)
    {
        totalSum += arr[i];
        preFixSum[i] = totalSum;
    }

    //You can choose some element from front and some from back, but some should be maximum
    for(int i = 0; i<n; i++) //[5, -2, 3, 1, 2], 3
    {
        int leftSum = INT_MIN, rightSum = INT_MIN;
        if(i < B) // we can choose[1 to B] elements from left and remaining from right
        {
            leftSum = preFixSum[i];
            int indx = (n - B + i); // from this index we can pick right elements
           
            if(preFixSum.find(indx) != preFixSum.end())
            {
                rightSum = totalSum - preFixSum[indx];
           
            }

            if(rightSum != INT_MIN)
                maxSum = max(maxSum , leftSum+rightSum);
            else
                maxSum = max(maxSum,leftSum);
        }
        
        if(B>= (n-i)) // we can choose [B to 1] element from right and remaining from left
        {
            leftSum = INT_MIN, rightSum = INT_MIN;
            rightSum = totalSum - preFixSum[i-1];

            int indx = (B -(n - i))-1;
            if(preFixSum.find(indx) != preFixSum.end())
            {
                leftSum = preFixSum[indx];
            }

            if(leftSum != INT_MIN)
                maxSum = max(maxSum , leftSum+rightSum);
            else
                maxSum = max(maxSum,rightSum);

        }
    }
    return maxSum;

}

int approch2(vector<int>arr, int B)
{
    int n = arr.size();
    int totalSum = 0;
    int prefixSum = 0;

    unordered_map<int,int>suFixSum;
    suFixSum[n-1] = arr[n-1];
    for(int i = 1; i<n; i++)
    {
        suFixSum[n-i-1] = suFixSum[n-i-1]+suFixSum[n-i];
    }

    int maxSum = suFixSum[n-B]; // Initilized maxSum with right picked elements
    for(int i  = 0; i<B; i++)
    {   
        prefixSum += arr[i];
        int indx = (n - B + i + 1); // from this index we can pick right elements
        
        maxSum = max( maxSum , prefixSum+suFixSum[indx]);
        
    }
    return maxSum;
}
int main()
{
    vector<int>arr = {4 ,5 ,8 ,1 ,2 ,5, 4, 1, 3 ,2, 10};
    int B = 3;
    cout<<approch2(arr,B)<<endl;
    return 0;
}