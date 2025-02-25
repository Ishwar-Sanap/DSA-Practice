#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/problems/police-and-thieves--141631/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

int catchThieves(char arr[], int n, int k)
{
   queue<int>policemen, theives;

   for(int i = 0; i<n; i++)
   {
        if(arr[i] == 'P')policemen.push(i);
        else  theives.push(i);
   }

   int cnt = 0;
   while(!policemen.empty() && !theives.empty())
   {
       
       int p = policemen.front();
       int t = theives.front();
       
       //Get the lowest index of policeman p and thief t. Make an allotment 
       // if |p-t| <= k and increment to the next p and t found. 
        if( abs(p- t) <= k)
        {   
            policemen.pop();
            theives.pop();
            cnt++;
        }
        else if(p < t) policemen.pop();

        else theives.pop();
   }

   return cnt;
}


int main()
{


    int n = 10, k = 4;
    char arr[] = {'P', 'T', 'P', 'P', 'P', 'P', 'T', 'P', 'T', 'T'};
    cout << catchThieves(arr, n, k);
    return 0;
}