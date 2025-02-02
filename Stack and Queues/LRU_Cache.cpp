/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache.
If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *next{NULL};
    Node *prev{NULL};
    int key;
    int val;
    Node(int k, int v)
    {
        key = k;
        val = v;
    }
};

class LRUCache
{
private:
    Node *front{NULL};
    Node *rear{NULL};
    int maxCap{0};

    unordered_map<int, Node *> mpKeyToNode;

    // get the node key from the map and attached it to the last of LL
    void updateLeastRecentlyUsed(int key)
    {
        Node *currNode = mpKeyToNode[key];

        // If it's already the most recently used, no need to move it
        if (currNode == rear)
            return;

        if (currNode == front) // deleting first
        {
            front = front->next;
            front->prev = NULL;

            // current node ready to attach at last
            currNode->next = NULL;
            currNode->prev = NULL;

            rear->next = currNode;
            currNode->prev = rear;

            rear = rear->next;
        }
        else
        {
            // arranging teh prev and next node to current
            Node *prevNode = currNode->prev;
            prevNode->next = currNode->next;
            currNode->next->prev = prevNode;

            // current node ready to attach at last
            currNode->next = NULL;
            currNode->prev = NULL;

            rear->next = currNode;
            currNode->prev = rear;

            rear = rear->next;
        }
    }

    // As we have maintined the doubly linked list the front node will be always least recently used
    void removeLeastRecenltyUsed()
    {

        // deleted previouse
        if (front->prev)
        {
            delete front->prev;
            front->prev = NULL;
        }

        // move to next pointer
        int key = front->key;
        front = front->next;

        // remove that keys from the map also
        mpKeyToNode.erase(key);
    }

    void insertNodeAtLast(int key, int value)
    {
        Node *newNode = new Node(key, value);
        // Inserting new nodes in ll
        if (front == NULL)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            newNode->prev = rear;
            rear = rear->next;
        }

        // Updating the map key to Node
        mpKeyToNode[key] = rear;
    }

public:
    LRUCache(int capacity)
    {
        maxCap = capacity;
    }

    int get(int key)
    {
        if (mpKeyToNode.find(key) != mpKeyToNode.end())
        {
            // UPDATE THE LEAST RECENTLY USED
            updateLeastRecentlyUsed(key);

            return mpKeyToNode[key]->val;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if (mpKeyToNode.find(key) != mpKeyToNode.end())
        {
            updateLeastRecentlyUsed(key);
            // updating the latest value
            mpKeyToNode[key]->val = value;
        }
        else
        {
            if (mpKeyToNode.size() < maxCap)
            {
                insertNodeAtLast(key, value);
            }
            else
            {
                // size is exceeded and key is not found then we have to delete the least recently used cache
                removeLeastRecenltyUsed();
                insertNodeAtLast(key, value);
            }
        }
    }
    void printLL(){}
};
int main()
{
    
    LRUCache *obj = new LRUCache(4);

    cout << obj->get(11) << endl;

    obj->put(1, 11);
    obj->put(2, 21);
    obj->put(3, 51);
    obj->put(4, 101);
    obj->printLL(); // 1 2 3 4

    cout << obj->get(2) << endl;
    obj->printLL(); // 1 3 4 2

    obj->put(5, 151);
    obj->printLL(); // 3 4 2 5

    obj->put(6, 166);
    obj->printLL(); // 4 2 5 6

    cout << obj->get(3); 

    return 0;
}
