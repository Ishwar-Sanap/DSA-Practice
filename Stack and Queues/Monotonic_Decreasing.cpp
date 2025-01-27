/*
Monotonic Decreasing Stack:
A Monotonically Decreasing Stack is a stack where elements are placed in decreasing order from the
bottom to the top. Each new element added to the stack must be smaller than or equal to the one
below it. If a new element is greater than top of stack then we remove elements from the top of
the stack until we find one that is greater or equal to the new element, or until the stack
is empty. This ensures that the stack always stays in decreasing order.

Arr[] = {1, 7, 9, 5}
Monotonic Decreasing stack step : stack -->1 
Since current 7 is greater than 1 pop 1, and store 7 stack --> 7
since current 9 is greate than 7 pop 7, and store 9 stack --> 9
since 5 is smaller that 9 pushe it, stack --> 9 5

Final Monotonic Incresing stack 1 5
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> monotonicDecreasing(vector<int> &arr)
{
    int n = arr.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        // Make space for large element than top
        while (!st.empty() and st.top() < arr[i]) 
            st.pop();

        st.push(arr[i]);
    }

    // store results
    vector<int> res;
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int>arr = {1, 7, 9, 5}; // 9 5
   // vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6}; //9 6
    vector<int> res = monotonicDecreasing(arr);

    for (int ele : res)
        cout << ele << " ";
    return 0;
}