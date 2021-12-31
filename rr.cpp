#include <iostream>
#include <vector>
#include <string>

using namespace std;

void sortProcess(vector<string> p, int *a, int *b, int n)
{

    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
                swap(p[i], p[j]);
                swap(b[i], b[j]);
            }
        }
    }
}

void FCFS(vector<string> p, int *a, int *b, int n)
{
    int i, j, *ct, *tat, *wt;
    float sumWt = 0, sumTat = 0;
    ct = new int[n];
    tat = new int[n];
    wt = new int[n];
    //main algo
    for (i = 0; i < n; i++)
    {

        if (i == 0)
            ct[i] = b[i] + a[i];
        else
            ct[i] = ct[i - 1] + b[i];
        tat[i] = ct[i] - a[i];
        wt[i] = tat[i] - b[i];
    }

    cout << " P      AT       WT       CT       TAT\n";
    for (i = 0; i < n; i++)
    {

        cout << p[i] << "       " << a[i] << "      " << wt[i] << "         " << ct[i] << "         " << tat[i] << endl;
        sumTat += tat[i];
        sumWt += wt[i];
    }

    cout << "Total turn around time is " << sumTat << "   Average turn around time is " << sumTat / n << endl;
    cout << "Total waiting time is " << sumWt << "    Average waiting time is " << sumWt / n << endl;
}

int main()
{
    int *arrivalTime, *burstTime, n, i;
    vector<string> process;
    string pname;
    cout << "Enter number of processes\n";
    cin >> n;
    arrivalTime = new int[n];
    burstTime = new int[n];
    cout << "Enter processes\n";
    for (i = 0; i < n; i++)
    {
        cout << "Enter process name" << endl;
        cin >> pname;
        process.push_back(pname);
        cout << "Enter arrival time for process" << endl;
        cin >> arrivalTime[i];
        cout << "Enter burst time for process " << endl;
        cin >> burstTime[i];
    }
    sortProcess(process, arrivalTime, burstTime, n);
    FCFS(process, arrivalTime, burstTime, n);
}