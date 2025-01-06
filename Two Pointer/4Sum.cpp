#include <bits/stdc++.h>
using namespace std;

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin() , nums.end());

        vector<vector<int>>ans;
        int n = nums.size();
        // Fixing 2 number i and j and applying Two pointer for remaining two

        for(int i = 0; i<n-3; i++)
        {
            if(i > 0 && nums[i-1] == nums[i] ) continue; // when i is not first element.
            for(int j = i+1; j<n-2; j++)
            {
                if(j != i+1 && nums[j-1] == nums[j] ) continue; // when j is not first element 
                int left = j+1;
                int right = n-1;

                while(left < right)
                {
                    long long currSum = ((long long)nums[i] + nums[j] + nums[left] + nums[right]);

                    if(currSum == target)
                    {
                        ans.push_back({nums[i] ,nums[j] , nums[left] , nums[right]});
                        left++;
                        right--;

                        while(left < right && nums[right] == nums[right+1]) right--;
                        while(left < right && nums[left] == nums[left-1]) left++;
                    }
                    else if(currSum > target) right--;
                    else left++;
                }
            }
        }
        return ans;
    }

int main()
{

    return 0;
}