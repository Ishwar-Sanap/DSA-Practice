#include <bits/stdc++.h>
using namespace std;
/*
Input [2,1,1,5,8,3,1,4] k = 4
Output : 10
*/
int cntSubarrays(int arr[] ,  int n, int k)
{
    int subArrayCnt = 0,  CurrSum = 0;
    
    for(int i = 0, j = 0; j<n; j++)
    {
        CurrSum += arr[j];

        while(CurrSum > k)
        {
            CurrSum -= arr[i];
            i++;
        }

        subArrayCnt += (j - i + 1); 
    }

    return subArrayCnt;
}

int main()
{
    int arr[] = {2,1,1,5,8,3,1,4};
    cout<<cntSubarrays(arr,8 , 4 )<<endl;
    return 0;
}