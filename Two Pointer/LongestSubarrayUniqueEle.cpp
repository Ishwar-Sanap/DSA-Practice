#include <bits/stdc++.h>
using namespace std;

// 1, 2, 3, 4, 5, 1, 2, 3 output = 5
// 1 2 2 4 2 2 3 4 5      output = 4

// 1 2 3 4 3 5 4 3 1 6  output = 5
int getLengthOfLongestSubarray(vector<int> &arr)
{
    int maxLen = 0, n = arr.size();
    int i = 0, j = 0;

    unordered_map<int, int> mp;
    while (j < n)
    {
        mp[arr[j]]++;
        if (mp[arr[j]] == 1)
            maxLen = max(maxLen, j - i + 1);

        else
        {
            while (i <n and mp[arr[i]] >= 1)
            {
                mp[arr[i]]--;
                 // by reducing frequecning we still have one it means we remove duplicat from window
                if(mp[arr[i]] == 1)
                {
                    i++;
                    break;
                }
                
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }

        j++;
    }

    return maxLen;
}

int main()
{   
    vector<int>arr= {1, 2, 4, 4, 5, 6, 7, 8, 3, 4, 5, 3, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4};
    cout<<getLengthOfLongestSubarray(arr)<<endl;
    return 0;
}