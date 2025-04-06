#include <bits/stdc++.h>
using namespace std;

/*

Given an unsorted array arr of positive integers. One number a from the set [1, 2,....,n] is missing
and one number b occurs twice in the array. Find numbers a and b.

4 2 2 1
repeted 2 , missing 3
*/

// Array modifications
vector<int> findTwoElement_Approach1(vector<int> &arr)
{

    int repeted = -1, missing = -1;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int idx = abs(arr[i]) - 1;

        if (arr[idx] > 0)
        {
            // mark it as a visited
            arr[idx] = -arr[idx];
        }
        else
        { // if that index elemetn is alredy visited then arr[i] is repeting element
            repeted = arr[i];
        }
    }

    //  If at any index arr[i] > 0, that means, we don't find element to mark ith index element as positive
    // So , i+1, will be your misssing…

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            missing = i + 1;
            break;
        }
    }

    return {repeted, missing};
}

// Approach2 Using mathematics equations:
vector<int> findTwoElements(vector<int> &arr)
{
    long long n = arr.size();
    long long sn = n * (n + 1) / 2;
    long long ssq = (n * (n + 1) * (2 * n + 1)) / 6;

    for (int i = 0; i < n; i++)
    {
        sn -= arr[i];
        ssq -= (1LL * arr[i] * 1LL * arr[i]);
    }

    int missing = -1, repeted = -1;

    // solve the equations :  x-y = sn' , x^2 - y^2 = ssq'
    // And after solving 2 equations ,we get x = (ssq'/sn' + sn')/2 and y = x - sn'

    missing = (ssq / sn + sn) / 2;
    repeted = missing - sn;

    return {repeted, missing};
}

int main()
{

    return 0;
}