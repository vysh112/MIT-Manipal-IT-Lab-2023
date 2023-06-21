#include <iostream>
#include <algorithm>

using namespace std;

struct process
{
    int pid;    // process ID
    int at;     // arrival time
    int bt;     // burst time
    int rt;     // remaining time
    int ct;     // completion time
    int tat;    // turnaround time
    int wt;     // waiting time
    int rem_bt; // remaining burst time
    int pt;     // priority
};

bool compare(process a, process b)
{
    return a.at < b.at;
}

int main()
{
    cout << "1. preemptive SJF\n2. RR\n3. non-pre priority\n";
    int ch;
    cin >> ch;

    switch (ch)
    {
    case 1:
    {
        int n;
        cout << "Enter the number of processes: ";
        cin >> n;

        process p[n];
        for (int i = 0; i < n; i++)
        {
            cout << "Enter Arrival Time and Burst Time for Process " << i + 1 << ": ";
            cin >> p[i].at >> p[i].bt;
            p[i].pid = i + 1;
            p[i].rt = p[i].bt;
        }

        sort(p, p + n, compare); // sort the processes according to their arrival time

        int currentTime = 0, completed = 0;
        float avg_tat = 0, avg_wt = 0;

        cout << "\nGantt Chart\n-----------\n";
        cout << "0";
        while (completed < n)
        {
            int min_rt = 1000, selected = -1; // selected process with minimum remaining time
            for (int i = 0; i < n; i++)
            {
                if (p[i].at <= currentTime && p[i].rt < min_rt && p[i].rt > 0)
                {
                    min_rt = p[i].rt;
                    selected = i;
                }
            }

            if (selected == -1)
            { // if no process is selected, increment the current time
                currentTime++;
                continue;
            }

            p[selected].rt--; // execute the process for 1 unit of time
            currentTime++;

            cout << " | P" << p[selected].pid << " | " << currentTime;

            if (p[selected].rt == 0)
            { // if the process has completed execution
                completed++;
                int tat = currentTime - p[selected].at; // turnaround time
                int wt = tat - p[selected].bt;          // waiting time
                avg_tat += tat;
                avg_wt += wt;
            }
        }

        avg_tat /= n;
        avg_wt /= n;

        cout << "\n\nAverage Turnaround Time = " << avg_tat << endl;
        cout << "Average Waiting Time = " << avg_wt << endl;
    }
    break;
    case 2:
    {
        int n, tq;
        cout << "Enter the number of processes: ";
        cin >> n;
        cout << "Enter the time quantum: ";
        cin >> tq;

        process p[n];
        for (int i = 0; i < n; i++)
        {
            cout << "Enter Arrival Time and Burst Time for Process " << i + 1 << ": ";
            cin >> p[i].at >> p[i].bt;
            p[i].pid = i + 1;
            p[i].rem_bt = p[i].bt; // set the remaining burst time of the i-th process
        }

        int currentTime = 0;
        float avg_tat = 0, avg_wt = 0;
        bool done;

        while (true)
        {
            done = true;
            for (int i = 0; i < n; i++)
            {
                if (p[i].rem_bt > 0)
                {
                    done = false;
                    if (p[i].rem_bt <= tq)
                    {
                        currentTime += p[i].rem_bt;
                        p[i].rem_bt = 0;
                        p[i].ct = currentTime;        // set the completion time of the i-th process
                        p[i].tat = p[i].ct - p[i].at; // calculate the turnaround time of the i-th process
                        p[i].wt = p[i].tat - p[i].bt; // calculate the waiting time of the i-th process
                    }
                    else
                    {
                        currentTime += tq;
                        p[i].rem_bt -= tq;
                    }
                }
            }
            if (done)
                break;
        }

        for (int i = 0; i < n; i++)
        {
            avg_tat += p[i].tat;
            avg_wt += p[i].wt;
        }

        avg_tat /= n;
        avg_wt /= n;

        cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
        for (int i = 0; i < n; i++)
        {
            cout << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << endl;
        }
        cout << "\nAverage Turnaround Time = " << avg_tat << endl;
        cout << "Average Waiting Time = " << avg_wt << endl;
    }
    break;
    case 3:
    {
        int n;
        cout << "Enter the number of processes: ";
        cin >> n;

        process p[n];
        for (int i = 0; i < n; i++)
        {
            cout << "Enter Arrival Time, Burst Time,priority for Process " << i + 1 << ": ";
            cin >> p[i].at >> p[i].bt >> p[i].pt;
            p[i].pid = i + 1;
            p[i].rt = p[i].bt;
        }

        sort(p, p + n, compare); // sort the processes according to their arrival time

        int currentTime = 0, completed = 0;
        float avg_tat = 0, avg_wt = 0;

        cout << "\nGantt Chart\n-----------\n";
        cout << "0";
        while (completed < n)
        {
            int man_pt = -1, selected = -1; // selected process with maximum priority
            for (int i = 0; i < n; i++)
            {
                if (p[i].at <= currentTime && p[i].pt > man_pt && p[i].rt > 0)
                {
                    man_pt = p[i].pt;
                    selected = i;
                }
            }

            if (selected == -1)
            { // if no process is selected, increment the current time
                currentTime++;
                continue;
            }

            p[selected].rt--; // execute the process for 1 unit of time
            currentTime++;

            cout << " | P" << p[selected].pid << " | " << currentTime;

            if (p[selected].rt == 0)
            { // if the process has completed execution
                completed++;
                int tat = currentTime - p[selected].at; // turnaround time
                int wt = tat - p[selected].bt;          // waiting time
                avg_tat += tat;
                avg_wt += wt;
            }
        }

        avg_tat /= n;
        avg_wt /= n;

        cout << "\n\nAverage Turnaround Time = " << avg_tat << endl;
        cout << "Average Waiting Time = " << avg_wt << endl;
    }
    break;
    default:
        break;
    }

    return 0;
}
