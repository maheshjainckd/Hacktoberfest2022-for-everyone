//Tower of Hanoi
#include<stdio.h>
#include<time.h>

void hanoi(int n,char sc,char dest,char aux){
	if(n==1)
		printf("Move disk %d from %c to %c\n",n,sc,dest);
	else{
		hanoi(n-1,sc,aux,dest);
		printf("Move disk %d from %c to %c\n",n,sc,dest);
		hanoi(n-1,aux,dest,sc);
	}
}
int main(){
	int n;
	clock_t start,end;
	double cpu_time_used;
	printf("Enter the number of disk\n");
	scanf("%d",&n);
	start=clock();
	hanoi(n,'S','D','A');
	end=clock();
	cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
	printf("Time complexity is=%lf",cpu_time_used);
}
