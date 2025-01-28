#include <bits/stdc++.h>

/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. 

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
*/
using namespace std;

    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>res(n, 0);
        int k = n-1;

        stack<int>st;

        int i = n-1;
        // How may time you have to travel?
        // Let suppose the you have combine the nums array,
        // -->nums: [1 2 3 4] --> [1,2,3,4,1,2,3,4] 

        int cnt = 1;
        while(cnt <= 2*n)
        {
            while(!st.empty() && st.top() <= nums[ (i + n) % n] ) 
                st.pop();
            
            if(st.empty())
                res[(i + n) % n]  = -1;

            else 
                res[(i + n) % n] = st.top();

            st.push(nums[(i + n) % n]);

            cnt++;
            i--;
        }

        return res;
    }
int main()
{

    return 0;
}