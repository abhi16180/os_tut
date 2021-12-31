#include <iostream>

int main()
{
    int temp, val;
    mat[0][3] = mat[0][1] + mat[0][2];
    ct[0] = at[0] + bt[0];
    mat[0][5] = mat[0][3] - mat[0][1];
    tat[0] = ct[0] - at[0];

    mat[0][4] = mat[0][5] - mat[0][2];
    wt[0] = tat[0] - bt[0] "Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n" for (int i = 1; i < num; i++)
    {
        temp = mat[i - 1][3];
        int low = mat[i][2];
        for (int j = i; j < num; j++)
        {
            if (temp >= mat[j][1] && low >= mat[j][2])
            {
                low = mat[j][2];
                val = j;
            }
        }
        mat[val][3] = temp + mat[val][2];
        mat[val][5] = mat[val][3] - mat[val][1];
        mat[val][4] = mat[val][5] - mat[val][2];
        for (int k = 0; k < 6; k++)
        {
            swap(mat[val][k], mat[i][k]);
        }
    }
}

0->id 1->at 2->bt
