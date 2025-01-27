/*
Given an array arr[ ] of integers, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1

Input: arr[] = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement(vector<int> &arr)
{
    // code here

    int n = arr.size();
    vector<int> ans(n, 0);

    stack<int> st;

    // iterating from Right to left since we want largest element store at top of stack..
    int i = n - 1;
    while (i >= 0)
    {
        while (!st.empty() && st.top() <= arr[i])
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

    return 0;
}