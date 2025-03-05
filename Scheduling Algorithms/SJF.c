#include<stdio.h>
int main()
{
	int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
	 float wtavg, tatavg;
	printf("\nEnter the number of processes -- "); 
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		p[i]=i;
		printf("Enter Burst Time for Process %d -- ", i);
		 scanf("%d", &bt[i]);
	}
	for(i=0;i<n;i++)
	for(k=i+1;k<n;k++)
	if(bt[i]>bt[k])
	{
		temp=bt[i]; bt[i]=bt[k]; bt[k]=temp;
		 temp=p[i]; p[i]=p[k]; p[k]=temp;
	}
	wt[0] = wtavg = 0; 
	tat[0] = tatavg = bt[0]; 
	for(i=1;i<n;i++)
	{
		wt[i] = wt[i-1] +bt[i-1];
		tat[i] = tat[i-1] +bt[i]; 
		wtavg = wtavg + wt[i]; 
		tatavg = tatavg + tat[i];
	}

	printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
	for(i=0;i<n;i++)
	printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i], bt[i], wt[i], tat[i]); 
	printf("\nAverage Waiting Time -- %f", wtavg/n);
	printf("\nAverage Turnaround Time -- %f", tatavg/n);
}
//output
Enter the number of processes -- 5
Enter Burst Time for Process 0 -- 8
Enter Burst Time for Process 1 -- 9
Enter Burst Time for Process 2 -- 5
Enter Burst Time for Process 3 -- 4
Enter Burst Time for Process 4 -- 2

	 PROCESS 	BURST TIME 	 WAITING TIME	 TURNAROUND TIME

	 P4 		 2 		 0 		 2
	 P3 		 4 		 2 		 6
	 P2 		 5 		 6 		 11
	 P0 		 8 		 11 		 19
	 P1 		 9 		 19 		 28
Average Waiting Time -- 7.600000
Average Turnaround Time -- 13.200000
