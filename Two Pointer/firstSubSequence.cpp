#include <bits/stdc++.h>
using namespace std;

//A = daabe
//B = abe
//A = paabe
//B = ade
int firstSubsequenceIndex(string A, string B)
{
    int n1 = A.length() , n2 = B.length() , ans = -1; 
    if(n2 > n1)
        return -1;

    int i = 0, j = 0, equalCnt = 0;

    while(i < n1 && A[i] != B[j])
    {
        i++;
    }

    if(i == n1)
        return -1;
    
    ans = i+1;

    while(i< n1 && j < n2)
    {
        if(A[i] != B[j])
            i++;
        else
        {
            i++;
            j++;
            equalCnt++;
        }
    }
    

    
    return equalCnt >= n2-1 ?ans : -1;
}

int main()
{
    string A = "abcbc";
    string B = "cba";
    cout<<firstSubsequenceIndex(A,B);
    return 0;
}