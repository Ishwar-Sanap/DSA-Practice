#include <bits/stdc++.h>
using namespace std;

//Given 2 array A and B check if array B is subsequence of array A
/*
Array A = [1 2 5 8 8 6 5 4 3] 

Array B = [5 5]

O/P - True; 

*/
bool areSubsequences(vector<int>A, vector<int>B)
{
    int cnt = 0;
    int i = 0, j = 0;

    while(i < A.size() and j < B.size())
    {
        if(A[i] != B[j])
        i++;
        else
        {
            i++;
            j++;
        }
    }
    return j == B.size();
}

int main()
{

    vector<int> A = {1, 2, 5, 8, 8, 6 ,5, 4 ,3};
    vector<int> B = {5,5, 7};
    
    cout<<areSubsequences(A,B)<<endl;
    return 0;
}