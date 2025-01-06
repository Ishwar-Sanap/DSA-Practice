
/*
//***************************** Fixed SIZED SLIDING WINDOW *****************************
In this case you have given the subarray size (Window Size), and you have to perform some operations on that k size subarray and want to return maximum or minimum


int i = 0, j = 0;
while (j < n)
{
        1)calculations

        2) make the window size equal to give size
        if(winSize(j-i+1) < k)
            j++;

        3)window size is hit
        else if(winSize == k)
        {
            i)find ans ==>> calculations

            ii) calculations to remove i

            iii) Maintaining the window size and slide it

            i++;
            j++;
        }
}


Ex Q. finding the maximum sum of the subArray of size k

int i = 0;
int j = 0;

long currSum = 0, maxSum = 0;
while (j < N)
{
    // do calculattions when we are moving J
    currSum += Arr[j];

    // if window size is less than k
    // we have to increas the window size
    if ((j - i + 1) < K)
    {
        j++;
    }

    // window size is equal to k  (i.e window size is hitt)
    // take the currSum and maintain the maximum of it
    //  so as we are moving to next in widow so remove the element from currSum that is not in
    //  the current window now.

    else
    {
        //  ---- when window is hitt ----
        // 1) calculate the ans from window
        maxSum = max(maxSum, currSum);

        // 2) calculations to remove i
        currSum -= Arr[i];

        // 3) slide window
        i++;
        j++;
    }
}
return maxSum;
*/

/***************************** VARIABLE SIZED SLIDING WINDOW *****************************
(window size is not given , sum or any conditions are given and we want to maximize or minmize window

General Format

int i = 0,j = 0
while (j < n)
{
    1) calculations

    2) if(condition < k)
            j++;

    3) else if (condition >= k)
    {
        while (condition > k)
        {
            remove calculations for i
            i++;
        }

        if(condition == k)
		    {
		        ans calculations
			// calculate maximum or minimum length from calculations we did   
		    }

        j++;

    }
}


ex : Q find the largest subArray of (sum == k )condition




int i = 0, j = 0;
int maxi = 0;
long long sum = 0;
while (j < n)
{
    // calculations
    sum += arr[j];

    // Checks Conditions..
    if (sum < k)
        j++;

    else if (sum == k)
    {
        // calculations of ans from one candiate
        maxi = max(maxi, (j - i + 1));
        j++;
    }

    else if (sum > k)
    {
        while (sum > k)
        {
            //Remove calculations for i
            sum -= arr[i];
            i++;
        }
        j++;
    }
}
return maxi;

*/
