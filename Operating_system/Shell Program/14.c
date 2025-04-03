// Write a program in C to implement RR.

#include <stdio.h>

void rr(int n, int burst[], int slice)
{
    int w_time[n];
    int turn_time[n];
    int remaining[n];
    int total_w_time = 0;
    int total_t_time = 0;
    int i;
    int time = 0;
    int sum;

    for (i = 0; i < n; i++)
    {
        remaining[i] = burst[i];
        w_time[i] = 0;
    }

    do
    {
        sum = 1;
        for (i = 0; i < n; i++)
        {
            if (remaining[i] > 0)
            {
                sum = 0;
                int prev_time = time;
                if (remaining[i] > slice)
                {
                    time += slice;
                    remaining[i] -= slice;
                }
                else
                {
                    time += remaining[i];
                    w_time[i] = time - burst[i];
                    remaining[i] = 0;
                }

                for (int j = 0; j < n; j++)
                {
                    if (j != i && remaining[j] > 0 && prev_time < time)
                    {
                        w_time[j] += (time - prev_time);
                    }
                }
            }
        }
    } while (!sum);

    for (i = 0; i < n; i++)
    {
        turn_time[i] = burst[i] + w_time[i];
        
        total_w_time += w_time[i];
        total_t_time += turn_time[i];
    }

    for (i = 0; i < n; i++)
    {
        printf("P%d        %d           %d              %d\n", i + 1, burst[i], w_time[i], turn_time[i]);
    }

    printf("\nThe average waiting time: %.2f ms\n", (float)total_w_time / n);
}

int main()
{
    int n, i, slice;
    printf("\nnumber of processes: ");
    scanf("%d", &n);

    int burst[n];
    for (i = 0; i < n; i++)
    {
        printf("burst time for process%d: ", i + 1);
        scanf("%d", &burst[i]);
    }

    printf("\ntime slice: ");
    scanf("%d", &slice);

    rr(n, burst, slice);

    return 0;
}