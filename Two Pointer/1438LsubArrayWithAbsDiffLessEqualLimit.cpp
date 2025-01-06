
#include <bits/stdc++.h>
using namespace std;
/*

*/

/*
    If we get Max and Min element from each subarray then  calculate it's abs difference and if
    it is less than or equal limit then we can say that for every other elements from that subarray also
    satisfised the same condition.

    maxHeap and minHeap will maintain the maximum and minimum element fromt the window
    so we can easily check the abs difference between any two element
*/
int LenlongesSubarray(vector<int> arr, int limit)
{
    int n = arr.size();
    int ans = 0;

    int i = 0, j = 0;
    priority_queue<pair<int, int>> maxHeap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (j = 0; j < n; j++)
    {
        maxHeap.push({arr[j], j});
        minHeap.push({arr[j], j});

        int diff = maxHeap.top().first - minHeap.top().first;
        while (diff > limit)
        { // Shift the window
        
            i = min(minHeap.top().second , maxHeap.top().second) + 1;

            while(minHeap.top().second < i )
                minHeap.pop();

            while(maxHeap.top().second < i)
                maxHeap.pop();
            
            diff = maxHeap.top().first - minHeap.top().first;
        }
        // after shifting window check updated ans
        int len = (j - i + 1);
        ans = max(ans, len);
    }
    
    return ans;
}

int main()
{
    // vector<int> arr{10, 1, 2, 4, 7, 2};
    // cout << LenlongesSubarray(arr, 6) << endl;
    vector<int> arr{4,2,2,2,4,4,2,2};
    cout << LenlongesSubarray(arr, 0) << endl;
    return 0;
}