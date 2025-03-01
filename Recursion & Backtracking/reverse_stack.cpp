#include <bits/stdc++.h>
using namespace std;

// T.C --> O(N^2)
void insertAtBottom(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }

    int currTop = st.top();
    st.pop();

    insertAtBottom(st, ele);

    st.push(currTop);
}

// This below approache works since we firstly made stack empty.
// and inserted top element at bottom.
void reverse(stack<int> &st)
{
    if (st.empty())
        return;

    int ele = st.top();
    st.pop();

    reverse(st);

    insertAtBottom(st, ele);
}

/// @brief reversing based, on taking each time one element and adding into bottom
/// @param st : stack
/// @param ele : element ot insert bottom
/// @param cnt : it helps to determine how many elements alredy placed in correct order
/// @param n : size of stack
void helper(stack<int> &st, int ele, int cnt, int n)
{
    if (st.empty() || cnt >= n) // to handle repetation of poping
    {
        st.push(ele);
        return;
    }

    int top = st.top();
    st.pop();

    helper(st, ele, cnt + 1, n);

    st.push(top);
}
void Reverse2(stack<int> &st)
{

    int n = st.size();

    for (int i = 0; i < n; i++)
    {
        int ele = st.top();
        st.pop();
        helper(st, ele, i + 1, n);
    }
}

int main()
{

    return 0;
}