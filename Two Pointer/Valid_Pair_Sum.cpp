#include <bits/stdc++.h>
using namespace std;

/*
Given an array of size N, find the number of distinct pairs {i, j} (i != j) in the array such that the sum of a[i] and a[j] is greater than 0.
 */
// 	-1 -1 -1 0 0 2 4   // out 11
// 	-2 -1 2 2 3 4      // 12

long long ValidPairApproach1(int a[], int n)
{
    long long cnt = 0;

    sort(a, a + n);

    // Handle -ve
    /*
        All negative elements are at starts and in asending order
        let i = 0 and j = 5  (a[0] + a[5] = 2 >0 )
                      j = 4  a[0] + a[4] = 1 >0 )
                      j = 3  a[0] + a[4] = 0

        for current i index we got 2 indices j = 5 and j = 4 satisfied condtion
        cnt = 2

        for index j = 3, increment i
        As current ith element is greter or equal to previous ith index element
        so using this ith element all previous jth index pairs also possible to add those to ans
        cnt += (n - j -1);  //4

        i = 1 and j = 3   (a[1] + a[3] = 1 > 0)
                 j = 2    (a[1] + a[2] = 1 > 0)

        cnt = 6
    */
    int i = 0, j = n - 1;
    while (i < n && j >= 0)
    {
        if (a[i] <= 0)
        {
            cnt += (n - j - 1); // adding previous results

            while (i < j && (a[i] + a[j]) > 0)
            {
                cnt++;
                j--;
            }

            i++;
        }
        /*
     // Handle +ve
    //If you found the index from where all positive element starts
    // then from remaing all right side element you can make valid pairs

        from i = 2 all greter than 0
        so remaining element are 4  possible pairs ==> (3 * (3+1))/2 ==> 6
        cnt = 6 + 6 ==> 12 output

        */
        else if (a[i] > 0)
        {
            // calculating all +ve elements pairs onces
            long long reminingEle = n - i - 1;
            cnt += (reminingEle * (reminingEle + 1)) / 2; // sum of n numbers
            break;
        }
    }
    return cnt;
}

/*
// 	-1 -1 -1 0 0 2 4   // out 11
// 	-2 -1 2 2 3 4      // 12

int i = 0, j= n-1;
since array is sorted 
By looking test cases, if ith and jth element sum is >0 then all elements from ith 
having valid pairs with j so, add that count  cnt += (j - i); and decremt j--

if sum is < 0 from ith index and jth index element no one index valid pair exist 
so increment i++ to increse the sum 
*/
long long ValidPairApproach2(int a[] , int n)
{
    long long cnt = 0;

    sort(a, a + n);

    int i = 0, j= n-1;
    while(i < j)
    {
        int sum = a[i] + a[j];
        if(sum > 0)
        {
            cnt += (j - i);
            j--;
        }
        else
            i++;
    }
    return cnt;
}
int main()
{

    return 0;
}