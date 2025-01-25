#include <bits/stdc++.h>
using namespace std;
class MyQueue
{
public:
    stack<int> st;
    MyQueue()
    {
    }

    // pushing new elemetn at begining of stack using loops
    void push(int x)
    {
        stack<int> st2;
        int stSize = st.size();

        // Remove all element from original stack.
        for (int i = 0; i < stSize; i++)
        {
            int ele = st.top();
            st.pop();
            st2.push(ele);
        }

        // Push new element at begin
        st.push(x);

        // pushed element from st2 itno original stack.
        stSize = st2.size();
        for (int i = 0; i < stSize; i++)
        {
            int ele = st2.top();
            st2.pop();
            st.push(ele);
        }
    }

    // Pusing new element at beginign of the stack using recursion...
    void push2(int x)
    {
        if(st.empty())
        {
            st.push(x);
            return;
        }

        int currTop = st.top();
        st.pop();

        push2(x); // recursive call

        st.push(currTop);
    }
    int pop()
    {
        int ele = st.top();
        st.pop();
        return ele;
    }

    int peek()
    {
        return st.top();
    }

    bool empty()
    {
        return st.empty();
    }
};

int main()
{

    MyQueue qobj;
    qobj.push2(10);
    qobj.push2(11);
    qobj.push2(21);

    cout<<qobj.pop()<<endl;
    return 0;
}