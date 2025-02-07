#include <bits/stdc++.h>
using namespace std;

/*
Why std::priority_queue Needs operator() overloding (Why Function Pointer Alone Doesn’t Work)
std::priority_queue is not a one-time operation like std::sort. It is a data structure that maintains order over multiple insertions and deletions.

It stores elements in a binary heap and needs a comparator that persists to maintain the heap property.

Unlike std::sort, the comparator is stored as part of the priority queue and used repeatedly whenever elements are inserted or removed.

Key Constraint
std::priority_queue expects a "callable" type (such as a functor, lambda, or function pointer).
But function pointers alone don’t work well because:
    std::priority_queue is a template class.
    The function pointer's type needs to be known at compile time.
    A function pointer does not carry state, whereas a functor (struct with operator()) can.

How operator() in a Struct Helps
    A functor (a struct with operator()) is a callable object that can be passed as a type to std::priority_queue.  
    The functor's operator() defines the comparison logic.
    Why does this work? The functor becomes part of the template type, so std::priority_queue can instantiate a comparator instance inside it.

*/

// Functor with overloaded () operator
struct Compare
{
    //. Which Two Elements Are Compared?
    // When a new element is pushed, it is compared against its parent.
    // The comparator is called with the parent and the newly inserted element
    bool operator()(int a, int b)
    {
        // since a > b, we need to swap
        return a > b; // min heap
    }
};

int main()
{
    // min heap using custom comparator
    priority_queue<int, vector<int>, Compare> pq;

    // Why we need custom comparator??
    /*
        Let suppose you want to store list node address in priority queue, but you
        want the order of lisnode according to the value inside the node, in that case
        you can't use below inbuid structure to maintain the priority_queue order..
    */

    // min heap using inbuild comparator
    priority_queue<int, vector<int>, greater<int>> pqMinHeap;

    // During push(x), the comparator is called with:
    // (parent, newly inserted element)
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    // pq will store as : 5 10 20 30

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}