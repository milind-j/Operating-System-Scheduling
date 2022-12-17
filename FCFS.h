// C++ program for implementation of FCFS scheduling
#include <iostream>
using namespace std;
int total_wt = 0, total_tat = 0;

// Function to find the waiting time for all processes
void findWaitingTimefs(int processes[], int n, int bt[], int wt[], int at[])
{
	int st[n];
	st[0] = 0;
	// waiting time for first process is 0
	wt[0] = 0;

	// calculating waiting time
	for (int i = 1; i < n; i++)
	{
		st[i] = st[i - 1] + bt[i - 1];
		wt[i] = st[i] - at[i];
	}
}

// Function to calculate turn around time
void findTurnAroundTimefs(int processes[], int n, int bt[], int wt[], int tat[], int at[])
{
	// calculating turnaround time by adding
	// bt[i] + wt[i]
	for (int i = 0; i < n; i++)
		tat[i] = bt[i] + wt[i];
}

// Function to calculate average time
void findavgTimefs(int processes[], int n, int bt[], int at[])
{
	int wt[n], tat[n];
	vector<int> gantt;
	gantt.push_back(-1);

	// Function to find waiting time of all processes
	findWaitingTimefs(processes, n, bt, wt, at);

	// Function to find turn around time for all processes
	findTurnAroundTimefs(processes, n, bt, wt, tat, at);

	// for(int i=0; i<n; i++){
	// 	ct[i] = st[i] + bt[i];
	// }

	// Display processes along with all details
	cout << "Process_No\tBurst_time\tTurn_Around_Time\tWaiting_Time" << endl;

	// Calculate total waiting time and total turn around time
	for (int i = 0; i < n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << i + 1 << "\t\t"
			 << "\t" << bt[i] << "\t\t " << tat[i] << "\t\t " << wt[i] << endl;
		gantt.push_back(i + 1);
	}

	cout << "\nAverage waiting time = " << (float)total_wt / (float)n;
	cout << "\nAverage turn around time = " << (float)total_tat / (float)n << endl;

	cout << "***** GANTT CHART *****" << endl;
	for (int i = 1; i < gantt.size(); i++)
	{
		if (i != gantt.size() - 1)
			cout << "P" << gantt[i] << "->";
		else
			cout << "P" << gantt[i];
	}
}