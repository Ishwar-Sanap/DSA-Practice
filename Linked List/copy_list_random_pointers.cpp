#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Approach 1: T.C --> O(N) S.C --> O(N)
Node *copyRandomList(Node *head)
{

    if (!head)
        return NULL;

    // map : key is old nodes and value : new node of lists
    unordered_map<Node *, Node *> oldToNewNodeMapping;

    Node *curr = head;
    while (curr)
    {
        oldToNewNodeMapping[curr] = new Node(curr->val);
        curr = curr->next;
    }

    curr = head;

    while (curr)
    {
        oldToNewNodeMapping[curr]->next = oldToNewNodeMapping[curr->next];
        oldToNewNodeMapping[curr]->random = oldToNewNodeMapping[curr->random];
        curr = curr->next;
    }

    return oldToNewNodeMapping[head];
}

// Appraoch2 : Optimal  T.C --> O(N) S.C --> O(1)

void insertNodes(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        // making copy of curr node
        // For every old node ther is copy of it in it's next pointer
        Node *newNode = new Node(curr->val);
        newNode->next = curr->next;
        curr->next = newNode;

        // moving to next node of original list
        curr = curr->next->next;
    }
}

void linkRandomPointers(Node *head)
{
    Node *curr = head;
    while (curr)
    {   
        // updating random pointers of copied nodes
        curr->next->random = curr->random ? curr->random->next : NULL;
        curr = curr->next->next;
    }
}

void detachedTheNodes(Node * head)
{
    Node *curr = head;
    Node *newCurr = head->next;

    while(curr && newCurr)
    {
        curr->next = curr->next? curr->next->next : NULL;
        newCurr->next = newCurr->next? newCurr->next->next : NULL;

        curr = curr->next;
        newCurr = newCurr->next;
    }
}

Node *copyRandomList2(Node *head)
{
    if (!head)
        return NULL;

    Node *newHead = NULL;

    // step1 : insert new nodes in between
    insertNodes(head);

    // step2 : liking the random pointers of copied nodes
    linkRandomPointers(head);

    //storing the new list head
    newHead = head->next;

    //step3 : detaching the inserted nodes for making 2 seperate list
    detachedTheNodes(head);

    return newHead;
}

int main()
{

    return 0;
}