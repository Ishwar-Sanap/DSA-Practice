#include <bits/stdc++.h>
using namespace std;

void helper(stack<int> &st, int minEle)
{
    if (st.empty())
    {
        st.push(minEle);
        return;
    }

    int currTop = st.top();
    if (currTop < minEle)
    {
        int temp = minEle;
        minEle = currTop;
        currTop = temp;
    }
    st.pop();
    helper(st, minEle);
    st.push(currTop);
}

void sort(stack<int> &st)
{
    int n = st.size();
    for (int i = 0; i < n; i++)
    {
        int minEle = st.top();
        st.pop();
        helper(st, minEle);
    }
}

void printStack(stack<int> &st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> st;

    st.push(41);
    st.push(3);
    st.push(32);
    st.push(2);
    st.push(11);

    // 11 2 32 3 41
    //  printStack(st);

    sort(st);

    // 41 32 11 3 2
    printStack(st);

    return 0;
}