#include<stdio.h>
int  main()
 {
  int bt[20], wt[20], tat[20], i, n; 
  float wtavg, tatavg;
  printf("\nEnter the number of processes -- ");
  scanf("%d", &n);
  for(i=0;i<n;i++)
  {
    printf("\nEnter Burst Time for Process %d -- ", i); 
    scanf("%d", &bt[i]);
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

  printf("\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
  for(i=0;i<n;i++)
  printf("\n\t P%d \t\t %d \t\t %d \t\t %d", i, bt[i], wt[i], tat[i]); 
  printf("\nAverage Waiting Time -- %f", wtavg/n); 
  printf("\nAverage Turnaround Time -- %f", tatavg/n);
}
//output:
Enter the number of processes -- 5

Enter Burst Time for Process 0 -- 8

Enter Burst Time for Process 1 -- 9

Enter Burst Time for Process 2 -- 5

Enter Burst Time for Process 3 -- 4

Enter Burst Time for Process 4 -- 2
	 PROCESS 	BURST TIME 	 WAITING TIME	 TURNAROUND TIME

	 P0 		 8 		 0 		 8
	 P1 		 9 		 8 		 17
	 P2 		 5 		 17 		 22
	 P3 		 4 		 22 		 26
	 P4 		 2 		 26 		 28
Average Waiting Time -- 14.600000
Average Turnaround Time -- 20.200001
