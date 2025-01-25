#include <bits/stdc++.h>
using namespace std;

// Using 2 queues
// T.C : O(N) S.C : O(N+N)
class MyStack2
{
public:
    queue<int> q1;

    MyStack2()
    {
    }

    void push(int x)
    {

        q1.push(x);
    }

    int pop()
    {
        // used another temporary queue to store poped elemetns.
        queue<int> q2;
        int ele = -1, q1size = q1.size();

        // pushed all elements except the last elemetn in another queue.
        // since last element we have to remove from stack.
        for (int i = 0; i < q1size - 1; i++)
        {
            ele = q1.front();
            q1.pop();
            q2.push(ele);
        }

        // the last element from queue is the first element that is poped from stack.
        ele = q1.front();
        q1.pop();

        // copying all elements to original queue.
        q1 = q2;
        return ele;
    }

    int top()
    {
        return q1.back();
    }

    bool empty()
    {
        return q1.empty();
    }
};

// using single queue
// TC : O(N) SC: O(N)
class MyStack
{
public:
    queue<int> q1;
    MyStack() {}

    void push(int x)
    {
        // While pushing element into the queue pushed elements in reverse order
        // so we can easily get the top elemnet and easily pop the elements
        q1.push(x);

        int q1Size = q1.size();
        for (int i = 0; i < q1Size - 1; i++)
        {
            int ele = q1.front();
            q1.pop();
            q1.push(ele);
        }
    }

    int pop()
    {
        int ele = q1.front();
        q1.pop();
        return ele;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    MyStack stObj;
    stObj.push(4);
    stObj.push(5);
    stObj.push(8);
    stObj.push(2);

    cout << stObj.pop() << endl; // 2
    cout << stObj.pop() << endl; // 8

    return 0;
}