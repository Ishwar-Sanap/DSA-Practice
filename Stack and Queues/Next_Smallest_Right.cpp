#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr)
{
    // code here

    int n = arr.size();
    vector<int> ans(n, 0);

    stack<int> st;

    // iterating from Right to left since we want Smallest element store at top of stack..
    // Monotonically incresing stack
    int i = n - 1;
    while (i >= 0)
    {
        while (!st.empty() && st.top() >= arr[i])
            st.pop();

        if (st.empty())
            ans[i] = -1;

        else
            ans[i] = st.top();

        st.push(arr[i]);

        i--;
    }
    return ans;
}

int main()
{

    vector<int>arr = {4,8,5,2,25};  // 2 5 2 -1 -1
    vector<int>res = nextSmallerElement(arr);

    for(int ele: res) cout<<ele<<" ";

    return 0;
}