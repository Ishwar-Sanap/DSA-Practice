 #include <bits/stdc++.h>
 using namespace std;
 
 /*
 matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
true
 */
 
 int main()
 {
 
     return 0;
 }
 bool binarySearchMatrix(vector<int>&arr, int target) 
    {
        int low = 0 ,high = arr.size()-1;

        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(arr[mid] == target) return true;
            else if(arr[mid] > target ) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        

         int n = matrix.size(), m = matrix[0].size();

         for(int i = 0; i<n; i++)
         {
            if(target >= matrix[i][0] && target <= matrix[i][m-1])
                if(binarySearchMatrix(matrix[i],target)) 
                    return true;
         }

         return false;

    }