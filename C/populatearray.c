#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool chkprime(int n){
    bool prime = true;

    for (int i = 2 ; i < n ; i++){
        if ((n%i) == 0){
            prime = false;
            break;
        }
    }
    return prime;
}

void main(){
    // clock_t start = clock();

    struct timeval t1,t2,t3,t4;
    srand(time(0));

    int arr[100][100];
    bool prime = true;
    
    gettimeofday(&t1,NULL);
    for(int i = 0 ; i < 100 ; i++){
        for(int j = 0 ; j < 100 ; j++){
            arr[i][j] = rand() % 100 + 1;
        }
    }
    gettimeofday(&t2,NULL);

    gettimeofday(&t3, NULL);
    for(int i = 0 ; i < 100 ; i++){
        for(int j = 0 ; j < 100 ; j++){
            prime = chkprime(arr[i][j]);
            if (prime == true) {
                printf("%d is a prime number\n",arr[i][j]);
            }
        }
    }
    gettimeofday(&t4,NULL);
    // clock_t end = clock();
    // double time_elapsed_in_seconds = (end - start)/(double)CLOCKS_PER_SEC;
    // printf("The time taken is : %f\n", time_elapsed_in_seconds);

    

    double p1,p2;
    p1 = t2.tv_usec - t1.tv_usec;
    printf("The time taken for populating a 100x100 array is : %10.2fus\n", p1);

    p2 = t4.tv_usec - t3.tv_usec;
    printf("The time taken to search for prime numbers in a 100x100 array is : %10.2fus\n", p2);




}

