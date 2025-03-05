#include<stdio.h>

int main() {
    int i, n, t, ct[10], bu[10], wa[10], tat[10], remaining_burst[10], max;
    float awt = 0, att = 0, temp = 0;

    printf("Enter the number of processes -- ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter Burst Time for process %d -- ", i + 1);
        scanf("%d", &bu[i]);
        remaining_burst[i] = bu[i];
        ct[i] = bu[i];
    }

    printf("\nEnter the size of time slice -- ");
    scanf("%d", &t);

    int time = 0;
    int completed = 0;

    while(completed < n) {
        for(i = 0; i < n; i++) {
            if (remaining_burst[i] > 0) {
                if (remaining_burst[i] <= t) {
                    time += remaining_burst[i];
                    tat[i] = time;
                    remaining_burst[i] = 0;
                    completed++;
                } else {
                    time += t;
                    remaining_burst[i] -= t;
                }
            }
        }
    }

    for(i = 0; i < n; i++) {
        wa[i] = tat[i] - ct[i];
        att += tat[i];
        awt += wa[i];
    }

    printf("\nThe Average Turnaround Time is -- %f", att / n);
    printf("\nThe Average Waiting Time is -- %f", awt / n);

    printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++) {
        printf("\tP%d\t\t%d\t\t%d\t\t%d\n", i + 1, ct[i], wa[i], tat[i]);
    }

    return 0;
}
//output
Enter the number of processes -- 5

Enter Burst Time for process 1 -- 8

Enter Burst Time for process 2 -- 9

Enter Burst Time for process 3 -- 5

Enter Burst Time for process 4 -- 4

Enter Burst Time for process 5 -- 2

Enter the size of time slice -- 3

The Average Turnaround Time is -- 22.400000
The Average Waiting Time is -- 16.799999
	PROCESS	BURST TIME	WAITING TIME	TURNAROUND TIME
	P1		8		17		25
	P2		9		19		28
	P3		5		17		22
	P4		4		19		23
	P5		2		12		14
