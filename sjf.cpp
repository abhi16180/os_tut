#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
//sort the process based on arrival time
void sortArrivalTime(vector<string> &p, int *a, int *b, int n)
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
//sort processes based on burst time if arrival time is same.
void sortBurstTime(int *arrival_time, vector<string> &process, int *burst_time, int n)

{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arrival_time[i] == arrival_time[j])

            {
                if (burst_time[i] > burst_time[j])

                {
                    swap(process[i], process[j]);
                    swap(arrival_time[i], arrival_time[j]);
                    swap(burst_time[i], burst_time[j]);
                }
            }
        }
    }
}

void print(vector<string> &p, int *a, int *b, int *ct, int *tat, int *wt, int n)
{
    int i, sumWt = 0, sumTat = 0;
    cout << " P " << setw(10) << "AT" << setw(10) << "BT" << setw(10) << "CT" << setw(10) << "TAT" << setw(10) << "WT\n";
    for (i = 0; i < n; i++)
    {

        cout << p[i] << setw(10) << a[i] << setw(10) << b[i] << setw(10) << ct[i] << setw(10) << tat[i] << setw(10) << wt[i] << endl;
        sumTat += tat[i];
        sumWt += wt[i];
    }

    cout << "Total turn around time is " << sumTat << "   Average turn around time is " << (float)sumTat / n << endl;
    cout << "Total waiting time is " << sumWt << "    Average waiting time is " << (float)sumWt / n << endl;
}

void SJF(vector<string> p, int *a, int *b, int n)
{
    int i, j, temp, val = 0, *ct, *tat, *wt;
    float sumWt = 0, sumTat = 0;
    ct = new int[n];
    tat = new int[n];
    wt = new int[n];
    //main algo
    //for the first process
    ct[0] = b[0] + a[0];
    tat[0] = ct[0] - a[0];
    wt[0] = tat[0] - b[0];
    //for remaining processes
    for (i = 1; i < n; i++)
    { //to keep track of completion time of previous process
        temp = ct[i - 1];
        // assume shortest job is b[i]
        int shortest_bt = b[i];
        //check for bt less than shortest_bt
        for (j = i; j < n; j++)
        {

            if (temp >= a[j] && shortest_bt >= b[j])
            {
                shortest_bt = b[j];
                val = j;
            }
        }

        ct[val] = temp + b[val];
        tat[val] = ct[val] - a[val];
        wt[val] = tat[val] - b[val];
        swap(a[val], a[i]);
        swap(b[val], b[i]);
        swap(ct[val], ct[i]);
        swap(wt[val], wt[i]);
        swap(tat[val], tat[i]);
        swap(p[val], p[i]);
    }
    print(p, a, b, ct, tat, wt, n);
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
    //take user input
    for (i = 0; i < n; i++)
    {
        cout << "Enter process name " << endl;
        cin >> pname;
        process.push_back(pname);
        cout << "Enter arrival time for process " << endl;
        cin >> arrivalTime[i];
        cout << "Enter burst time for process " << endl;
        cin >> burstTime[i];
    }
    //call sort process function
    sortArrivalTime(process, arrivalTime, burstTime, n);
    //sort based on bust time
    sortBurstTime(arrivalTime, process, burstTime, n);
    //call SJF function
    SJF(process, arrivalTime, burstTime, n);
}