#include <bits/stdc++.h>
using namespace std;

int merge2SortedArrays(vector<int> &arr, int si, int mid, int ei)
{

    // Finding Inversion counts from 2 sorted arrays
    int inversionCount = 0;

    // Array1 : si to mid
    // Array2 : mid+1 to ei

    int i = si, j = mid + 1;
    vector<int> temp;

    while (i <= mid && j <= ei)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        { // Array2 elemetn is greter

            temp.push_back(arr[j]);
            // Inversion for arr[j] will be all elements from array1 ie. from [i to mid]

            inversionCount += (mid - i + 1);
            j++;
        }
    }

    while (i <= mid)
        temp.push_back(arr[i++]);

    while (j <= ei)
        temp.push_back(arr[j++]);

    // copy temp array into origianl array:
    i = si;
    for (int ele : temp)
    {
        arr[i] = ele;
        i++;
    }

    return inversionCount;
}

void divideArray(vector<int> &arr, int si, int ei, int &cnt)
{
    if (si >= ei)
        return;

    int mid = si + (ei - si) / 2;

    divideArray(arr, si, mid, cnt);
    divideArray(arr, mid + 1, ei, cnt);

    cnt += merge2SortedArrays(arr, si, mid, ei);
}

int getInversionCounts(vector<int> &arr)
{
    // Using the approach of merge sort
    int cnt = 0;

    divideArray(arr, 0, arr.size() - 1, cnt);

    return cnt;
}

int main()
{

    vector<int> arr = {2, 4, 1, 3, 5, 0, 7};

    cout << getInversionCounts(arr) << endl;

    // after sorting the array using merge sort...
    for(int ele : arr) cout<<ele<<" ";

    return 0;
}