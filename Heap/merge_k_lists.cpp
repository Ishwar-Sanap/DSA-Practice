#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *mergeTwoSortedList(ListNode *l1, ListNode *l2)
    {
        ListNode *mergeHead = new ListNode(-1);
        ListNode *temp = mergeHead;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }

            temp = temp->next;
        }

        if (l1)
            temp->next = l1;

        if (l2)
            temp->next = l2;

        return mergeHead->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &arr)
    {

        int n = arr.size();
        if (n == 0)
            return NULL;

        else if (n == 1)
            return arr[0];

        ListNode *ansNode = new ListNode(-1);
        ListNode *temp = ansNode;

        for (int i = 0; i < n; i++)
        {
            temp->next = mergeTwoSortedList(temp->next, arr[i]);
        }

        return ansNode->next;
    }

    // Solutation using priority queue,

    struct comp
    {
        bool operator()(ListNode *l1, ListNode *l2)
        {
            return l1->val > l2->val; // min heap
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &arr)
    {
        priority_queue<ListNode *, vector<ListNode *>, comp> pq; // min heap , based on value of node

        int n = arr.size();
        if (n == 0)
            return NULL;

        else if (n == 1)
            return arr[0];

        // storing all head node of list in pq in incresing order of their values.
        for (ListNode *node : arr)
        {
            if (node)
                pq.push(node);
        }

        ListNode *ansNode = new ListNode(-1);
        ListNode *temp = ansNode;

        while (!pq.empty())
        {
            temp->next = pq.top();
            pq.pop();
            temp = temp->next;

            if (temp->next) // after adding top node there might be next node present add it to pq
                pq.push(temp->next);
        }

        return ansNode->next;
    }
};

int main()
{

    return 0;
}