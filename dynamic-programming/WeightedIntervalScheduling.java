package com.topics.algorithms.dynamicProgramming;

import java.util.Arrays;
import java.util.Comparator;

public class WeightedIntervalScheduling {
    // A job has start time, finish time and profit.
    static class Job {
        int start, finish, profit;
        Job(int start, int finish, int profit) {
            this.start = start;
            this.finish = finish;
            this.profit = profit;
        }
    }
 
    // Find the latest job (in sorted array) that doesn't
    // conflict with the job[i]. If there is no compatible
    // job, then it returns -1.
    static int latestNonConflict(Job arr[], int i) {
        for (int j = i - 1; j >= 0; j--) {
            // finish before next is started
            if (arr[j].finish <= arr[i - 1].start)
                return j;
        }
        return -1;
    }
 
    static int findMaxProfitDP(Job arr[], int n) {
        // Create an array to store solutions subproblems.
        // Table[i] stores the profit for jobs till arr[i] (including arr[i])
        int[] table = new int[n];
        table[0] = arr[0].profit;
 
        // Fill entries in M[] using recursive property
        for (int i = 1; i < n; i++) {
            // Find profit including the current job
            int inclProf = arr[i].profit;
            int l = latestNonConflict(arr, i);
            if (l != -1)
                inclProf += table[l];
 
            // Store maximum of including and excluding
            table[i] = Math.max(inclProf, table[i - 1]);
        }
 
        // Store result and free dynamic memory allocated
        // for table[]
        int result = table[n - 1];
 
        return result;
    }
 
    // The main function that returns the maximum possible
    // profit from given array of jobs
    static int findMaxProfit(Job arr[], int n) {
        // Sort jobs according to finish time
        Arrays.sort(arr, new Comparator<Job>() {
            public int compare(Job j1, Job j2) {
                return j1.finish - j2.finish;
            }
        });
 
        return findMaxProfitDP(arr, n);
    }
 
    public static void main(String args[]) {
        int m = 4;
        Job arr[] = new Job[m];
        arr[0] = new Job(3, 10, 20);
        arr[1] = new Job(1, 2, 50);
        arr[2] = new Job(6, 19, 100);
        arr[3] = new Job(2, 100, 200);
        int n = arr.length;
        System.out.println("The optimal profit is "
                           + findMaxProfit(arr, n));
    }
}