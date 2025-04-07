// Write a program in C to implement FCFS.

#include <stdio.h>
int main()
{
    int p;
    int time = 0;
    printf("enter the no of process: ");
    scanf("%d", &p);
    int pr_arr[p];
    int waiting[p];
    int turn_around[p];
    for (int i = 0; i < p; i++)
    {
        printf("enter the burst time for the process %d: ", i + 1);
        scanf("%d", &pr_arr[i]);
    }

    for (int i = 0; i < p; i++)
    {
        waiting[i] = time;
        time += pr_arr[i];
        turn_around[i] = time;
    }

    float av_time = 0;
    float turn_time = 0;

    printf("\n");
    for (int i = 0; i < p; i++)
    {
        av_time += waiting[i];
    }
    av_time = av_time / p;

    for (int i = 0; i < p; i++)
    {
        turn_time += turn_around[i];
    }
    turn_time = turn_time / p;

    printf("process \t burst time \t waiting time \t turn around time\n");
    for (int i = 0; i < p; i++)
    {
        printf("P%d \t\t %d \t\t %d \t\t %d \n", i + 1, pr_arr[i], waiting[i], turn_around[i]);
    }
    printf("\n");
    printf("the average waiting time: %.2f ms\n", av_time);
    printf("the average turn around time: %.2f ms\n", turn_time);
}



// output

// enter the no of process: 4
// enter the burst time for the process 1: 6
// enter the burst time for the process 2: 2
// enter the burst time for the process 3: 3
// enter the burst time for the process 4: 5

// process 	 burst time 	 waiting time 	 turn around time
//   P1 		      6 		      0 		       6 
//   P2 		      2 		      6 		       8 
//   P3 		      3 		      8 		       11 
//   P4 		      5 		     11 		       16 

// the average waiting time: 6.25 ms
// the average turn around time: 10.25 ms
