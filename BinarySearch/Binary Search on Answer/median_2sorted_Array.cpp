#include <bits/stdc++.h>
using namespace std;

/*
 vector<int>nums1 = {1,3,5,8,12};
vector<int>nums2 = {2,3,4,6,7};
merged sorted array even length: 1 2 3 3 4 5 6 7 8 -->median --> (4+5)/2 = 4.5

 vector<int>nums1 = {1,3,5,8};
vector<int>nums2 = {2,3,4,6,7};
merged sorted array odd length: 1 2 3 3 4 5 6 7 8 -->median --> 4
*/
double binarySerachToGetMid(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();

    int leftPartLen = (n1 + n2) / 2;
    int rightPartLen = (n1 + n2) / 2;

    if ((n1 + n2) % 2 == 1)
        leftPartLen++; // odd number of elements

    double ans = 0.0;

    int low = 0, high = n1; // how many element we pick from array1

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
            if (leftPartLen == rightPartLen)
                ans = (max(l1, l2) + min(r1, r2)) / 2.0;
            else
                ans = max(l1, l2);

            return ans;
        }
    }

    return ans;
}
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    // Binary serach is applied on how many elements we can take from nums1 to make valid partition
    // on Left and right part , in left part some elements from nums1 and some from nums2
    // similarly in right part some elements from nums1 and some from nums2

    int n1 = nums1.size(), n2 = nums2.size();

    if (n1 > n2)
        return findMedianSortedArrays(nums2, nums1);

    return binarySerachToGetMid(nums1, nums2);
}

int main()
{

    vector<int>nums1 = {1,3,5,8,12};
    vector<int>nums2 = {2,3,4,6,7};

    // vector<int>nums1 = {7,8};
    // vector<int>nums2 = {2,3,4};
    vector<int> nums1 = {1};
    vector<int> nums2 = {};

    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}