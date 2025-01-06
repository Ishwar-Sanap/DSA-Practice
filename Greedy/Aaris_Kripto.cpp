#include <bits/stdc++.h>
using namespace std;

#define int long long

// https://www.codechef.com/problems/SHOOT0

/*
Aarsi and Krypto were competing in a shooting game.
You are given a matrix AA of size 1 * M representing a shooting board. The cells of the matrix contain information about which player took a shot at which cell:
• If A(i,j)=0A(i,j)​=0, no player took a shot at that cell.
• If A(i,j)=1A(i,j)​=1, Aarsi took a shot at that cell.
• If A(i,j)=2A(i,j)​=2, Krypto took a shot at that cell.
• If A(i,j)=3A(i,j)​=3, both players took a shot at that cell.
Let the bullseye cell be (x1​,y1​), then, for a shot at cell (x2​,y2​), the score of the shot is calculated as 
max⁡(∣x1−x2∣,∣y1−y2∣). The score of a player is the sum of scores of all shots by that player.
Your task is to consider each cell in the matrix as the bullseye cell and find the value of ∣∣Aarsi's score - Krypto's score∣∣ accordingly.

1 5
2 1 3 0 1

Output 5 2 1 0 1

*/
int32_t main()
{
    // your code goes here

    int t = 0;
    cin >> t;
    while (t--)
    {

        int n = 0, m = 0;
        cin >> n >> m;

        vector<int> arr(m, 0);
        int cnt_k = 0, sum_k = 0;
        int cnt_A = 0, sum_A = 0;

        for (int i = 0; i < m; i++)
        {
            cin >> arr[i];
            if (arr[i] == 1 || arr[i] == 3) // Aaris
            {
                cnt_A++;
                sum_A += i + 1;
            }

            if (arr[i] == 2 || arr[i] == 3) // kripto
            {
                cnt_k++;
                sum_k += i + 1;
            }
        }

        int curr_cnt_k = 0, curr_sum_k = 0;
        int curr_cnt_A = 0, curr_sum_A = 0;
        for (int line = 1; line <= m; line++)
        {
            int AScore = 0, KScore = 0;

            if (arr[line - 1] == 1 || arr[line - 1] == 3) // Aaris
            {
                curr_cnt_A++;
                curr_sum_A += line;
            }
            if (arr[line - 1] == 2 || arr[line - 1] == 3) // kripto
            {
                curr_cnt_k++;
                curr_sum_k += line;
            }

            // Aaris Score Left + right part
            int left = ((curr_cnt_A * line) - curr_sum_A);
            int right = (sum_A - curr_sum_A) - (cnt_A - curr_cnt_A) * line;
            AScore = left + right;

            // kripto Score Left + right part
            left = ((curr_cnt_k * line) - curr_sum_k);
            right = (sum_k - curr_sum_k) - ((cnt_k - curr_cnt_k) * line);
            KScore = left + right;

            cout << abs(AScore - KScore) << " ";
        }
        cout << endl;
    }
}
