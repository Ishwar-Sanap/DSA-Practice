// Find number of subarray whose distinct elements count is less than or equal to k
#include <bits/stdc++.h>
using namespace std;
/*
Input [1, 2, 3, 2, 2, 4, 1, 1] k = 2
Output : 20
*/
int cntSubarrays(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    int cnt = 0;

    for (int i = 0, j = 0; j < n; j++)
    {
        mp[arr[j]]++;
        while (mp.size() > k)
        {
            mp[arr[i]]--;

            if (mp[arr[i]] == 0)
                mp.erase(arr[i]);

            i++;
        }

        cnt += (j - i + 1);
    }
    return cnt;
}

int main()
{
    int arr[] = {1, 2, 3, 2, 2, 4, 1, 1};
    cout << cntSubarrays(arr, 8, 2) << endl;
    return 0;
}