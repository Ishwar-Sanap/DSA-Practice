#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/middle-of-the-linked-list/
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

///The Tortoise and Hare algorithm
int getMiddleElement(Node *head)
{
    /*
     1->2->3->4   we have 2 and 3 are  mid in this 
     case but if we want first one i.e 2 then only we can go till sinle node from list

    For getting first middle i.e 2 :  assign slow = head, fast = head->next

    For getting second middle i.e 3 : assign slow = head, fast  = head
    
     1->2->3->4->5 : middle-> 3
    In case of Odd no of elements both will work fine as there is only one middle
    */
    // Code here
    Node *slow = head;
    Node *fast = head;

    //Once fast reaches to end slow will poins to the middle element, 
    //since it will traverse the half nodes  than Fast pointer..
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

    }
    return slow->data;
}

int main()
{

    return 0;
}