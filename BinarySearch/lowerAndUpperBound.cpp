#include <bits/stdc++.h>
using namespace std;

// Find first greter or equal element than target
int lowerBound(vector<int>&arr, int target)
{
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = -1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;

        if(target > arr[mid])
            low = mid + 1;
        
        else if(target <= arr[mid])
        {
            // Since target is less than or equal to mid, mid can be answer but 
            // search in left part for better answer
            ans = mid;
            high = mid-1;
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
    int ans = -1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;

        if(target >= arr[mid])
            low = mid+1;

        else if(target < arr[mid])
        {
            // since target is less than mid, mid can be answer but 
            // search in left part for better answer
            ans = mid;
            high = mid-1;
        }
    }
    // return low ;  //without ans varible our result is present in low
    return ans;
}

int main()
{
    vector<int> arr{2, 3, 7, 10, 11, 11, 25};
    // cout<<UpperBound(arr,11)<<endl;

    // inbuilt function.
    // auto it =  upper_bound(arr.begin(), arr.end(), 11);
    auto it =  lower_bound(arr.begin(), arr.end(), 11);
    int index = it - arr.begin();
    cout<<index<<endl;
    return 0;
}