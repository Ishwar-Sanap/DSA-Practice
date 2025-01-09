#include <bits/stdc++.h>
using namespace std;

// Find first greter or equal element than target
int lowerBound(vector<int>&arr, int target)
{
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = n; // assinged ans to n since if we not found any element less or equal to target
    while(low <= high)
    {
        int mid = low + (high - low)/2;

        if(arr[mid] >= target)
        {
            // Since arr[mid] is greter than or equal to target, mid can be answer but 
            // search in left part for better answer
            ans = mid;
            high = mid-1;
        }
        else 
        {
            low = mid + 1;
        }
    }
    // return low ;  //without ans varible our result is present in low
    return ans;
    
}

//Find first striclty greter element than target
int UpperBound(vector<int>&arr, int target)
{
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = n;    // assinged ans to n since if we not found any element less  to target
    while(low <= high)
    {
        int mid = low + (high - low)/2;

         if(arr[mid] > target)
        {
            // Since arr[mid] is strictly greter than  target, mid can be answer but 
            // search in left part for better answer
            ans = mid;
            high = mid-1;
        }
        else 
        {
            low = mid + 1;
        }
    }
    // return low ;  //without ans varible our result is present in low
    return ans;
}

int main()
{
    vector<int> arr{2, 3, 7, 10, 11, 11, 25};
    cout<<UpperBound(arr,11)<<endl; // 6
    // cout<<UpperBound(arr,26)<<endl; // 7

    // inbuilt function.
    auto it1 =  upper_bound(arr.begin(), arr.end(), 26);
    auto it =  lower_bound(arr.begin(), arr.end(), 11);
    auto it2 =  lower_bound(arr.begin(), arr.end(), 26);
    // cout<<lowerBound(arr,26)<<endl;
    int index = it1 - arr.begin();
    cout<<index<<endl;
    return 0;
}