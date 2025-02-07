#include <bits/stdc++.h>
using namespace std;

// Input: nums = [3,2,1,5,6,4], k = 2
//  Output: 5

int findKthLargest(vector<int> &nums, int k)
{

    priority_queue<int> pq; // max heap
    int n = nums.size();
    int reqSize = n - k + 1;

    for (int num : nums)
    {
        pq.push(num);

        if (pq.size() > reqSize)
            pq.pop(); // remove top elememt
    }

    return pq.top();

    // Another way to do the same, is push all ements into Priority queue
    //  and pop top most k-1 elements, after that top will be your kth largetst element
}


// Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
// Output:  7
// Explanation: 3rd smallest element in the given array is 7
int kthSmallest(vector<int> &arr, int k)
{
    // code here

    int n = arr.size();
    int reqSize = n - k + 1;

    priority_queue<int, vector<int>, greater<int>> pq; // Min Heap
    for (int ele : arr)
    {
        pq.push(ele);
        if (pq.size() > reqSize)
            pq.pop();
    }
    return pq.top();
}

bool comp(int ele1, int ele2)
{
    return ele1 >= ele2;
}
int main()
{
    vector<int> arr = {4, 2, 3, 1, 8};
    sort(arr.begin(), arr.end(), comp);

    for (int ele : arr)
        cout << ele << " ";

    return 0;
}