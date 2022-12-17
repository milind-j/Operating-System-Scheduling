#include <bits/stdc++.h>
#include "PriorityScheduling.h"
#include "FCFS.h"
#include "ShortestJobFirst.cpp "
#include "RoundRobin.cpp"

using namespace std;

int main()
{
	cout << "\nEnter number of processes: ";
	int n, i, j, temp, index;
	cin >> n;
	cout << endl;
	int process[n];
	int at[n];
	int bt[n];
	int quantum;
	int priority[n];
	for (int i = 0; i < n; i++)
	{
		process[i] = i + 1;
		cout << "Enter arrival time, burst time and priority of process " << i + 1 << ": ";
		cin >> at[i] >> bt[i] >> priority[i];
	}
	cout << "Enter time quantum: ";
	cin >> quantum;
	int atc[n];
	int btc[n];
	int processc[n];
	for (i = 0; i < n; i++)
	{
		atc[i] = at[i];
		btc[i] = bt[i];
		processc[i] = process[i];
	}
	// Sort according to arrival time
	for (i = 0; i < n; i++)
	{
		index = i;
		for (j = i + 1; j < n; j++)
		{
			if (atc[index] > atc[j])
			{

				index = j;
			}
		}
		temp = atc[i];
		atc[i] = atc[index];
		atc[index] = temp;

		temp = btc[i];
		btc[i] = btc[index];
		btc[index] = temp;

		temp = processc[i];
		processc[i] = processc[index];
		processc[index] = temp;
	}
	cout << "\n-----------------------------------------------------------------------------------------\n\n";
	cout << "\nRound Robin Scheduling:\n\n";
	// findavgTimerr(processc, n, btc, quantum, atc);

	for (int i = 0; i < n; i++)
	{
		po[i].arrival_time = at[i];
		po[i].burst_time = bt[i];
		// burst_remaining[i] = p[i].burst_time;
		po[i].pid = i + 1;
		// cout << endl;
	}
	round(n, quantum);
	cout << "\n-----------------------------------------------------------------------------------------\n\n";
	cout << "\nFCFS Scheduling:\n\n";
	findavgTimefs(processc, n, btc, atc);

	for (int i = 0; i < n; i++)

	{

		proc[i].at = at[i];

		proc[i].bt = bt[i];

		proc[i].pr = priority[i];

		proc[i].pno = i + 1;
	}

	// sort(proc, proc + n, comp);
	cout << "\n-----------------------------------------------------------------------------------------\n\n";
	cout << "\nPriority Scheduling:\n\n";
	findgcps(n);

	cout << "\n-----------------------------------------------------------------------------------------\n\n";

	cout << "\nShortest Job First Scheduling:\n\n";

	for (int i = 0; i < n; i++)
	{

		p[i].arrival_time = at[i];
		p[i].burst_time = bt[i];
		p[i].pid = i + 1;
	}
	calc(n);
	cout << "\n-----------------------------------------------------------------------------------------\n\n";
}