#include <bits/stdc++.h>
using namespace std;

//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
class MinStack
{
public:
    stack<int> st;
    stack<int> stMinEle; //This stack will maintain the minimum element.
    MinStack()
    {
    }

    void push(int val)
    {

        st.push(val);

        if (stMinEle.empty())
            stMinEle.push(val);

        else if (val <= stMinEle.top())
            stMinEle.push(val);
    }

    void pop()
    {

        int ele = st.top();
        st.pop();

        if (ele == stMinEle.top())
            stMinEle.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return stMinEle.top();
    }
};
int main()
{

    return 0;
}
