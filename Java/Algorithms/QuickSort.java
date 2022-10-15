import java.util.Random;

import java.util.Scanner;

class QuickSort {

    static int comparisons = 0;

    static int[] arr;

    static void quickSort(int low, int high) {

        if (low < high) {

            comparisons += 1;

            int j = partition(low, high);

            quickSort(low, j - 1);

            quickSort(j + 1, high);

        }

    }

    static int partition(int low, int high) {

        int pivot = arr[low];

        int i = low, j = high;

        while (i < j) {

            comparisons += 1;

            while (i < high && arr[i] <= pivot) {

                comparisons += 2;

                i = i + 1;

            }

            while (j > low && arr[j] >= pivot) {

                comparisons += 2;

                j = j - 1;

            }

            if (i < j) {

                comparisons += 1;

                interchange(i, j);

            }

        }

        arr[low] = arr[j];

        arr[j] = pivot;

        return j;

    }

    static void interchange(int i, int j) {

        int temp = arr[i];

        arr[i] = arr[j];

        arr[j] = temp;

    }

    public static void main(String[] args) {

        int n;

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter value of n: ");

        n = scanner.nextInt();

        arr = new int[n];

        System.out.println("Quick Sort");

        System.out.println("1. Best/Average Case");

        System.out.println("2. Worst Case");

        int ch = scanner.nextInt();

        switch (ch) {

        case 1:

            Random random = new Random(3000);

            for (int i = 0; i < n; i++) {

                arr[i] = random.nextInt();

            }

            break;

        case 2:

            for (int i = 0; i < n; i++) {

                arr[i] = i + 1;

            }

            break;

        }

        long start = System.nanoTime();

        quickSort(0, n - 1);

        long end = System.nanoTime();

        System.out.println("Sorted Array");

        for (int i = 0; i < n; i++) {

            System.out.println(arr[i]);

        }

        System.out.println("Time taken: " + (end - start));

        System.out.println("Comparisons: " + comparisons);

    }

}
