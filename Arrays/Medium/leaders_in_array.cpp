#include <bits/stdc++.h>
using namespace std;

/*
You are given an array arr of positive integers. Your task is to find all the leaders in the array. An element is considered a leader if it
 is greater than or equal to all elements to its right. The rightmost element is always a leader.

 Input: arr = [16, 17, 4, 3, 5, 2]
Output: [17, 5, 2]
*/
vector<int> leaders(vector<int> &arr)
{
    // Code here

    int n = arr.size();
    int rightMax = INT_MIN;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] >= rightMax)
        {
            ans.push_back(arr[i]);
            rightMax = arr[i];
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
int main()
{

    unordered_set<int>st {5,4,6,9,7};

    while(!st.empty())
    {
        int ele = *st.begin();
        cout<<ele<<" ";

        st.erase(ele);
    }

    return 0;
}