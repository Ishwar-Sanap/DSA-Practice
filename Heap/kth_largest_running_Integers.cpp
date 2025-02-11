#include <bits/stdc++.h>
using namespace std;
/*
You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth
 highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted
 list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element
in the pool of test scores so far.

Example 1:

Input:
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

Output: [null, 4, 5, 5, 8, 8]
*/

class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq; // min heap.
    int kth = 0;
    KthLargest(int k, vector<int> &nums)
    {
        kth = k;
        // min heap will maintain the size of kth largest element
        // it will be stored on top.
        for (int ele : nums)
        {
            pq.push(ele);
            if (pq.size() > k)
                pq.pop();
        }
    }

    int add(int val)
    {

        pq.push(val);

        if (pq.size() > kth)
            pq.pop();

        return pq.top();
    }
};
int main()
{

    return 0;
}