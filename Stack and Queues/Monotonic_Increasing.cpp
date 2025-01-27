/*
A Monotonically Increasing Stack is a stack where elements are placed in increasing order from
the bottom to the top. Each new element added to the stack is greater than or equal to the one
below it.If a new element is smaller, we remove elements from the top of the stack until we find
one that is smaller or equal to the new element, or until the stack is empty. This ensures that
the stack always stays in increasing order.

Arr[] = {1, 7, 9, 5}
Monotonic Incresing stack step : 1 , 7 , 9
since 5 is smaller that 9, 7 pop those elements

Final Monotonic Incresing stack 1 5

Complexity Analysis:

Time Complexity: O(N), each element from the input array is pushed and popped from the stack exactly once. Therefore, even though there is a loop inside a loop, no element is processed more than twice.
Auxiliary Space: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> monotonicInresing(vector<int> &arr)
{
    int n = arr.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        // make space for smaller or equal elemnt than top
        while (!st.empty() and st.top() > arr[i]) 
            st.pop();

        st.push(arr[i]);
    }

    // store results
    vector<int>res;
    while(!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    reverse(res.begin(), res.end());   
    return res;
}

int main()
{
    // vector<int>arr = {1, 7, 9, 5}; // 1 5
    vector<int>arr = {3, 1, 4, 1, 5, 9, 2, 6};  // 1 1 2 6
    vector<int>res = monotonicInresing(arr);

    for(int ele: res) cout<<ele<<" ";
    return 0;
}