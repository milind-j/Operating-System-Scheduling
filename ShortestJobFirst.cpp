#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string.h>
using namespace std;

struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    // int response_time;
};
struct process p[100];
void calc(int n)
{
    vector<int> gantt;
    gantt.push_back(-1);
    float avg_turnaround_time;
    float avg_waiting_time;

    int total_turnaround_time = 0;
    int total_waiting_time = 0;

    float throughput;
    int is_completed[100];
    memset(is_completed, 0, sizeof(is_completed));

    cout << setprecision(2) << fixed;

    int current_time = 0;
    int completed = 0;
    int prev = 0;

    while (completed != n)
    {
        int idx = -1;
        int mn = 10000000;
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival_time <= current_time && is_completed[i] == 0)
            {
                if (p[i].burst_time < mn)
                {
                    mn = p[i].burst_time;
                    idx = i;
                }
                if (p[i].burst_time == mn)
                {
                    if (p[i].arrival_time < p[idx].arrival_time)
                    {
                        mn = p[i].burst_time;
                        idx = i;
                    }
                }
            }
        }
        if (idx != -1)
        {
            p[idx].start_time = current_time;
            p[idx].completion_time = p[idx].start_time + p[idx].burst_time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
            gantt.push_back(p[idx].pid);
            total_turnaround_time += p[idx].turnaround_time;
            total_waiting_time += p[idx].waiting_time;

            is_completed[idx] = 1;
            completed++;
            current_time = p[idx].completion_time;
            prev = current_time;
        }
        else
        {
            current_time++;
        }
    }

    avg_turnaround_time = (float)total_turnaround_time / n;
    avg_waiting_time = (float)total_waiting_time / n;

    cout << endl
         << endl;

    cout << "Processes\t"

         << "Burst_Time\t"
         << "WaitingTime\t"
         << "Turn_around_Time\t"

         << "\n"
         << endl;

    for (int i = 0; i < n; i++)
    {
        cout << p[i].pid << "\t\t" << p[i].burst_time << "\t\t" << p[i].waiting_time << "\t\t" << p[i].turnaround_time << "\t"
             << "\n"
             << endl;
    }
    cout << "Average Turnaround Time = " << avg_turnaround_time << endl;
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
