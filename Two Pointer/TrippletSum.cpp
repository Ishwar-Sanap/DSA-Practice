#include <bits/stdc++.h>
using namespace std;
bool hasTripletSum(vector<int> &arr, int target)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++)
    {
        int left = i + 1;
        int right = n - 1; //Note 
        while (left < right)
        {
            long long currSum = ((long long)arr[left] + arr[right] + arr[i]);

            if (currSum == target)return true;
        
            else if (currSum < target) left++;

            else right--;
        }
    }
    return false;
}

int main()
{

    // vector<int>arr = {1,6,8,9,23,56,74,78,80,81,87,101,124,127,134};
    // vector<int>arr = {1,6,8,9,23,80,81,87,134};
    vector<int> arr = {1, 6, 8, 9, 23, 56, 74, 78, 80, 81, 87, 101, 124, 127, 134};

    cout << hasTripletSum(arr, 192) << endl;
    return 0;
}