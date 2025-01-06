// Find number of pairs whose difference  is less than or equal to k
#include <bits/stdc++.h>
using namespace std;
/*
Input [2 ,4, 3 , 5 , 1, 6 ,8] k = 3
sorting : 1 2 3 4 5 6 8 
Output : 
*/
int cntPairs(int arr[], int n, int k)
{
   sort(arr, arr+n);
    int cnt = 0;

    for (int i = 0, j = 0; j < n; j++)
    {
       int diff = arr[j] - arr[i];
        while (diff > k)
        {
            i++;   
            diff = arr[j] - arr[i];
        }

        cnt += (j - i + 1);
    }

    cnt = cnt - n; // since we want pairs so we can't take same index as pair but this formula(j - i + 1);
                    // add all single elemens also so we substract n pairs.
    return cnt;
}

int main()
{
    int arr[] = {2 ,4, 3 , 5 , 1, 6 ,8};
    cout << cntPairs(arr, 7, 3) << endl;
    return 0;
}