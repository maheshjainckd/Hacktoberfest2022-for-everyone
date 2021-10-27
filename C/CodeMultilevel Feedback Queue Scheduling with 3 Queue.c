#include<stdio.h>
void main()
{
	int no_of_process;
	int time_quantum_q1 = 8 ;
	int time_quantum_q2 = 16 ;
	int swap_var;
	int i,j;
	 	printf("\n\t\t\t\t\t   Multilevel FeedBack Queue Scheduling \n");
        printf("\t\t\t\t==================================================\n");;
	    printf("\t\t\t\t--------------------------------------------------\n");
	printf("\n -----------------------------------------------------------------------------------------------\n");
	printf("Enter no of processes: ");
	scanf("%d",&no_of_process);
	
	int process_number[no_of_process];	
	int arrival_time[no_of_process];
	int burst_time[no_of_process];
	int turnaround_time[no_of_process];
	int waiting_time[no_of_process];
	int buffer_burst_time[no_of_process];
	int processed_queue[no_of_process];
	int q1[no_of_process];
	int q2[no_of_process];
	int q3[no_of_process];
	float average_wt=0;
	float average_tat=0;
	for(i=0;i<no_of_process;i++)
	{	
		
		process_number[i] = i+1;
		printf("\n |---------------------------------------------------------------------------|\n");
		printf("\nEnter Details for process P%d \n",process_number[i]);
		printf("Enter arrival time : ");
		scanf("%d",&arrival_time[i]);
		printf("Enter Burst time : ");
		scanf("%d",&burst_time[i]);
		buffer_burst_time[i] = burst_time[i];
		waiting_time[i]=0;
		turnaround_time[i]=0;
		processed_queue[i] = 0;
		printf("\n |---------------------------------------------------------------------------|\n");
	
	}
	
	
	
	
	
	printf("\nProcess deatils before sorting of process a/c arrival time");
	printf("\n -----------------------------------------------------------------------------------------------\n");
	printf("|    Process\t|\tAT\t|\tBT\t|\tWT\t|\tTAT\t|\tQueue\t|\n");
	printf(" -----------------------------------------------------------------------------------------------\n");
	for(i=0;i<no_of_process;i++)
	{
		printf("|\tP%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n",process_number[i],arrival_time[i],burst_time[i],waiting_time[i],turnaround_time[i],processed_queue[i]);
	}
	printf(" -----------------------------------------------------------------------------------------------\n");
	
	//sorting of processes a/c to arrival time.
	
	for(i=0;i<no_of_process-1;i++)
		{
		  for(j=i+1;j<no_of_process;j++)
		  {
			if(arrival_time[i] > arrival_time[j])
				{
					swap_var = burst_time[i];
					burst_time[i] = burst_time[j];
					burst_time[j] = swap_var;
					swap_var = buffer_burst_time[i];
					buffer_burst_time[i] = buffer_burst_time[j];
					buffer_burst_time[j] = swap_var;
					swap_var = arrival_time[i];
					arrival_time[i] = arrival_time[j];
					arrival_time[j] = swap_var;
					swap_var = process_number[i];
					process_number[i] = process_number[j];
					process_number[j] = swap_var;
				}
			}
		}
	int time = arrival_time[0];
		
	printf("\nProcess deatils after sorting of process a/c arrival time");
	printf("\n -----------------------------------------------------------------------------------------------\n");
	printf("|    Process\t|\tAT\t|\tBT\t|\tWT\t|\tTAT\t|\tQueue\t|\n");
	printf(" -----------------------------------------------------------------------------------------------\n");
	for(i=0;i<no_of_process;i++)
	{
		printf("|\tP%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n",process_number[i],arrival_time[i],burst_time[i],waiting_time[i],turnaround_time[i],processed_queue[i]);
	}
	printf(" -----------------------------------------------------------------------------------------------\n");
	
	
	//logic for multilevel feedback scheduling
	
	
	//queue1
	for(i=0;i<no_of_process;i++)
	{
		time += time_quantum_q1;
		buffer_burst_time[i] -= time_quantum_q1;
		q1[i] = buffer_burst_time[i];
			
		if(buffer_burst_time[i] <= 0)
		{
			q1[i] = 0;
			waiting_time[i] = 	time - arrival_time[i]-burst_time[i];
			turnaround_time[i] = time-arrival_time[i];
			processed_queue[i] = 1;	
		}		
	}
	
	
	//queue2
	for(i=0;i<no_of_process;i++)
	{
		if(q1[i]>0)
		{
		
			if(q1[i] >=  time_quantum_q2)
				{
					time += time_quantum_q2;
					q1[i] -= time_quantum_q2;
					q2[i] = q1[i];
			
					if(q1[i] <= 0)
					{
						q2[i] = 0;
						waiting_time[i] = 	time - arrival_time[i]-burst_time[i];
						turnaround_time[i] = time-arrival_time[i];
						processed_queue[i] = 2;	
					}
				}
			else 
				{
					time += q1[i];
					q1[i] = 0;
					q2[i] = q1[i];
					waiting_time[i] = 	time - arrival_time[i]-burst_time[i];
					turnaround_time[i] = time-arrival_time[i];
					processed_queue[i] = 2;					
				}	
		}		
	}	
	
	
	
	//queue3
	for(i=0;i<no_of_process;i++)
	{
		if(q2[i]>0)
		{

		time += q2[i];
		q2[i] =0;
		q3[i] = q2[i];
			
		if(q2[i] <= 0)
		{
			buffer_burst_time[i] = 0;
			waiting_time[i] = 	time - arrival_time[i]-burst_time[i];
			turnaround_time[i] = time-arrival_time[i];
			processed_queue[i] = 3;	
		}
		
		}			
	}	
	
	
	printf("\nProcess deatils after scheduling of process.");
	printf("\n -----------------------------------------------------------------------------------------------\n");
	printf("|    Process\t|\tAT\t|\tBT\t|\tWT\t|\tTAT\t|\tQueue\t|\n");
	printf(" -----------------------------------------------------------------------------------------------\n");
	for(i=0;i<no_of_process;i++)
	{
		printf("|\tP%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n",process_number[i],arrival_time[i],burst_time[i],waiting_time[i],turnaround_time[i],processed_queue[i]);
	}
	printf(" -----------------------------------------------------------------------------------------------\n");

	for(i=0;i<no_of_process;i++)
	{
		average_wt += waiting_time[i];
		average_tat += turnaround_time[i];
	}
	
	printf("Average Waiting Time --> %f \n Average Turnaround Time --> %f",average_wt/no_of_process,average_tat/no_of_process);


}
