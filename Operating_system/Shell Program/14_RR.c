//  14. Write a program in C to implement RR.(need to test)
#include <stdio.h>

int main(void)
{
    int n, slice;
    int total_w_arr = 0;
    int total_t_arr = 0;
    int time = 0;
    int flag;
    printf("enter the no of process: ");
    scanf("%d", &n);

    int burst_arr[n];
    int remaining[n];
    int w_arr[n];
    int turn_arr[n];

    for(int i = 0; i < n; i++)
    {
        printf("enter the burst time forthe process %d: ", i + 1);
        scanf("%d", &burst_arr[i]);
    }

    printf("enter time slice: ");
    scanf("%d", &slice);

    for(int i = 0; i < n; i++)
    {
        remaining[i] = burst_arr[i];
        w_arr[i] = 0;
    }
    do
    {
        flag = 0;
        for(int i = 0; i < n; i++)
        {
            if (remaining[i] > 0)
            {
                flag = 1;
                int prev_time = time;
                if (remaining[i] > slice)
                {
                    time += slice;
                    remaining[i] -= slice;
                }
                else
                {
                    time += remaining[i];
                    w_arr[i] = time - burst_arr[i];
                    remaining[i] = 0;
                }
                for(int j = 0; j < n; j++)
                {
                    if (j != i && remaining[j] > 0 && prev_time < time)
                    {
                        w_arr[j] += (time - prev_time);
                    }
                }
            }
        }
    } while (flag);

    for(int i = 0; i < n; i++)
    {
        turn_arr[i] = burst_arr[i] + w_arr[i];
        
        total_w_arr += w_arr[i];
        total_t_arr += turn_arr[i];
    }
    printf("process \t burst time \t waiting time \t turn around time\n");
    for(int i = 0;i<n;i++){
        printf("P%d \t\t %d \t\t %d \t\t %d \n",i+1,burst_arr[i],w_arr[i],turn_arr[i]);
    }
    printf("the average waiting time is : %.2f ms\n", (float)total_w_arr / n);

    return 0;
}



// output

// enter the no of process: 4
// enter the burst time forthe process 1: 9
// enter the burst time forthe process 2: 3
// enter the burst time forthe process 3: 7
// enter the burst time forthe process 4: 1
// enter time slice: 2
// process 	 burst time 	 waiting time 	 turn around time
// P1 		      9 		      11 		     20 
// P2 		      3 		      7 		     10 
// P3 		      7 		      12 		     19 
// P4 		      1 		      6 		     7 
// the average waiting time is : 9.00 ms
