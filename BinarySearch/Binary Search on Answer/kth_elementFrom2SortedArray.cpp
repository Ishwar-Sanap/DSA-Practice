#include <bits/stdc++.h>
using namespace std;

/*
Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.

Examples :

Input: aarray1[] = [2, 3, 6, 7, 9], array2[] = [1, 4, 8, 10], k = 5
Output: 6
Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.

*/
int binarySerachToGetkth(vector<int> &nums1, vector<int> &nums2, int k)
{
    int n1 = nums1.size(), n2 = nums2.size();

    int leftPartLen = k; // left part must have k elements

    int ans = 0;

    //Here we have to identify the left search space effectively.
    /*
    Let suppose k is 8, then from array1 if you taken 0 elements, then from array2 you have to take 8 elements
    but array2 have maximum 4 elements you can't take 8 :(,so from array1 you minimum have to take : max(0, k - n2) elemetns

    As k is 8, at max you can take n1 from array1  high = min(k, n1)
    */
    int low = max(0, k - n2), high = min(k, n1); // how many element we pick

    while (low <= high)
    {
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        int mid = low + (high - low) / 2;

        // indx1 and indx2 will point to the ending index of left parts elemens from nums1 and nums2 respectively
        int indx1 = mid - 1;
        int indx2 = leftPartLen - mid - 1;

        l1 = indx1 >= 0 ? nums1[indx1] : l1;
        l2 = indx2 >= 0 ? nums2[indx2] : l2;
        r1 = (indx1 + 1 < n1) ? nums1[indx1 + 1] : r1;
        r2 = (indx2 + 1 < n2) ? nums2[indx2 + 1] : r2;

        if (l1 > r2) // decrease the count of no of elements from nums1
            high = mid - 1;

        else if (l2 > r1) // increse the count of no of elements from nums1
            low = mid + 1;

        else if (l1 <= r2 && l2 <= r1) // partitions is correct
        {
            return max(l1, l2);
        }
    }

    return -1;
}

int kthElement(vector<int> &nums1, vector<int> &nums2, int k)
{
    // code here
    int n1 = nums1.size(), n2 = nums2.size();

    if (n1 > n2)
        return kthElement(nums2, nums1, k);

    return binarySerachToGetkth(nums1, nums2, k);
}

int main()
{

    return 0;
}