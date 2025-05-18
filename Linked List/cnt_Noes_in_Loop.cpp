#include <bits/stdc++.h>
using namespace std;
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
int countNodesinLoop(Node *head)
{
    // Code here
    Node *slow = head;
    Node *fast = head;

    int cnt = 0;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        // Loop found
        if (slow == fast)
        {
            Node *temp = slow->next;
            cnt++;
            // count the loop len
            while (temp != slow)
            {
                cnt++;
                temp = temp->next;
            }

            return cnt;
        }
    }

    return cnt;
}

int main()
{

    return 0;
}