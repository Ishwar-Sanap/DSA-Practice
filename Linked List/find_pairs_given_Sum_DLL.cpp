#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

//https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1 

//Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list 
//whose sum is equal to given value target.
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    // code here

    vector<pair<int, int>> ans;
    if (!head)
        return ans;

    // using two pointers approach in DLL since LL is sorted

    Node *left = head;
    Node *right = head;

    while (right->next)
        right = right->next;

    while (left->data < right->data)
    {
        int sum = left->data + right->data;
        if (sum == target)
        {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }

        else if (sum < target)
            left = left->next;
        else
            right = right->prev;
    }

    return ans;
}