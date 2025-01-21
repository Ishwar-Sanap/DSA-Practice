#include <bits/stdc++.h>
using namespace std;

/*
You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).
Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
[12] and [34, 67, 90] Maximum Pages = 191
[12, 34] and [67, 90] Maximum Pages = 157
[12, 34, 67] and [90] Maximum Pages = 113.
Therefore, the minimum of these cases is 113, which is selected as the output.



*/
bool canAllocatePages(vector<int> &arr, int k, int pages)
{
    int studentCnt = 1;
    int i = 0, n = arr.size();
    int sumPages = 0;
    while (i < n)
    {
        sumPages += arr[i];
        if (sumPages > pages)
        {
            sumPages = 0;
            studentCnt++;
            continue;
        }
        i++;
    }

    // then current pages are maximum pages and we can allocates them to k students
    return studentCnt <= k;
}

int findPages(vector<int> &arr, int k)
{

    int ans = -1;

    if (k > arr.size())
        return -1;

    /*
    Observations:

    Minimum possible answer: We will get the minimum answer when we give n books of the array to n students(i.e. Each student will receive 1 book). Now, in this case, the maximum number of pages will be the maximum element in the array. So, the minimum possible answer is max(arr[]).

    Maximum possible answer: We will get the maximum answer when we give all n books to a single student. The maximum no. of pages he/she will receive is the summation of array elements i.e. sum(arr[]). So, the maximum possible answer is sum(arr[]).
    From the observations, it is clear that our answer lies in the range [max(arr[]), sum(arr[])].
    */
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // if we can allocates thease max pages then try to minimize pages
        if (canAllocatePages(arr, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    // return ans;
    return low;
}

int main()
{

    return 0;
}
