#include <bits/stdc++.h>
using namespace std;

struct processs
{
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

bool compare1(processs p1, processs p2)
{
    return p1.arrival_time < p2.arrival_time;
}

bool compare2(processs p1, processs p2)
{
    return p1.pid < p2.pid;
}
struct processs po[100];
void round(int n, int tq)
{
    vector<int> gantt;
    gantt.push_back(-1);
    float avg_turnaround_time;
    float avg_waiting_time;

    int total_turnaround_time = 0;
    int total_waiting_time = 0;

    int burst_remaining[100];
    int idx;
    for (int i = 0; i < n; i++)
        burst_remaining[i] = po[i].burst_time;
    cout << setprecision(2) << fixed;

    sort(po, po + n, compare1);

    queue<int> q;
    int current_time = 0;
    q.push(0);
    int completed = 0;
    int mark[100];
    memset(mark, 0, sizeof(mark));
    mark[0] = 1;

    while (completed != n)
    {
        idx = q.front();
        q.pop();

        if (burst_remaining[idx] == po[idx].burst_time)
        {
            po[idx].start_time = max(current_time, po[idx].arrival_time);

            current_time = po[idx].start_time;
        }

        if (burst_remaining[idx] - tq > 0)
        {
            burst_remaining[idx] -= tq;
            current_time += tq;
            gantt.push_back(po[idx].pid);
        }
        else
        {
            current_time += burst_remaining[idx];
            burst_remaining[idx] = 0;
            completed++;

            po[idx].completion_time = current_time;
            po[idx].turnaround_time = po[idx].completion_time - po[idx].arrival_time;
            po[idx].waiting_time = po[idx].turnaround_time - po[idx].burst_time;
            gantt.push_back(po[idx].pid);
            total_turnaround_time += po[idx].turnaround_time;
            total_waiting_time += po[idx].waiting_time;
        }
        for (int i = 1; i < n; i++)
        {
            if (burst_remaining[i] > 0 && po[i].arrival_time <= current_time && mark[i] == 0)
            {
                q.push(i);
                mark[i] = 1;
            }
        }
        if (burst_remaining[idx] > 0)
        {
            q.push(idx);
        }

        if (q.empty())
        {
            for (int i = 1; i < n; i++)
            {
                if (burst_remaining[i] > 0)
                {
                    q.push(i);
                    mark[i] = 1;
                    break;
                }
            }
        }
    }

    avg_turnaround_time = (float)total_turnaround_time / n;
    avg_waiting_time = (float)total_waiting_time / n;

    sort(po, po + n, compare2);

    cout << endl;
    cout << "Processes\t"

         << "Burst_Time\t"

         << "Turn_Around_Time\t"
         << "WaitingTime\t"

         << "\n"
         << endl;

    for (int i = 0; i < n; i++)
    {
        cout << po[i].pid << "\t\t" << po[i].burst_time << "\t\t" << po[i].turnaround_time << "\t\t\t" << po[i].waiting_time << "\t"
             << "\n"
             << endl;
    }
    cout
        << "Average Turnaround Time = " << avg_turnaround_time << endl;
    cout << "Average Waiting Time = " << avg_waiting_time << endl;
    cout << "***** GANTT CHART *****" << endl;
    for (int i = 1; i < gantt.size(); i++)
    {
        if (i != gantt.size() - 1)
            cout << "P" << gantt[i] << "->";
        else
            cout << "P" << gantt[i];
    }
}
