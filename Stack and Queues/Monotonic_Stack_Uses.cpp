#include <bits/stdc++.h>
using namespace std;

//All of the below functinos have T.C --> O(N) since only once element is pushed and poped from stack through out execution
//and S.C --> O(N)

// Find the next greater to right (NGR)
// EX: Arr --> {2, 3, 1, 5, 6, 4}
//     NGR --> {3, 5, 5, 6, -1, -1}
vector<int> nextGreaterRight(vector<int> &arr)
{
   int n = arr.size();

   // (storing number itself in stack, but for range calculaion store it's indices)
   stack<int> st;

   vector<int> ans(n, 0);

   // Traverse from right to left
   for (int i = n - 1; i >= 0; i--)
   {
      // pop the smaller elements from top of the stack
      while (!st.empty() && st.top() <= arr[i])
         st.pop();

      // No greater found to right of current ith element
      if (st.empty())
         ans[i] = -1;
      else
         ans[i] = st.top();

      st.push(arr[i]);
   }

   return ans;
}

// Find the next greater to left (NGL)
// EX: Arr --> {2, 3, 1, 5, 6, 4}
//     NGL --> {-1, -1, 3, -1, -1, 6}
vector<int> nextGreaterLeft(vector<int> &arr)
{
   int n = arr.size();
   stack<int> st;

   vector<int> ans(n, 0);

   // Travers from left to right
   for (int i = 0; i < n; i++)
   {
      // pop the smaller elements from top of the stack
      while (!st.empty() && st.top() <= arr[i])
         st.pop();

      // No greater found to right of current ith element
      if (st.empty())
         ans[i] = -1;
      else
         ans[i] = st.top();

      st.push(arr[i]);
   }

   return ans;
}

// Find the next Smaller to Right (NSR)
//  EX: Arr --> {2, 3, 1, 5, 6, 4}
//      NSR --> {1, 1, -1, 4, 4, -1}
vector<int> nextSmallestRight(vector<int> &arr)
{
   int n = arr.size();
   vector<int> ans(n, 0);

   stack<int> st; //(storing number itself in stack, but for range calculaion store it's indices)

   for (int i = n - 1; i >= 0; i--)
   {
      // Pop larger elemetns from stack
      while (!st.empty() && st.top() >= arr[i])
         st.pop();

      if (st.empty())
         ans[i] = -1;
      else
         ans[i] = st.top();

      st.push(arr[i]);
   }

   return ans;
}

// Find the next Smaller to Left (NSL)
//  EX: Arr --> {2, 3, 1, 5, 6, 4}
//      NSL -->{-1, 2, -1, 1, 5, 1}
vector<int> nextSmallestLeft(vector<int> &arr)
{
   int n = arr.size();
   vector<int> ans(n, 0);

   stack<int> st; //(storing number itself in stack, but for range calculaion store it's indices)

   for (int i = 0; i < n; i++)
   {
      // Pop larger elemetns from stack
      while (!st.empty() && st.top() >= arr[i])
         st.pop();

      if (st.empty())
         ans[i] = -1;
      else
         ans[i] = st.top();

      st.push(arr[i]);
   }

   return ans;
}

int main()
{
   vector<int> arr = {2, 3, 1, 5, 6, 4};

   vector<int> ans = nextSmallestLeft(arr);
   for (auto it : ans)
      cout << it << " ";
   cout << endl;
   return 0;
}