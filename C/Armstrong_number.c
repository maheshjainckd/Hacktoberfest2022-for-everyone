#include <stdio.h>
#include <math.h>

int countDigits(int number) {
    int count = 0;
    while (number != 0) {
        number /= 10;
        count++;
    }
    return count;
}

int isArmstrong(int number) {
    int originalNumber, remainder, result = 0, n = countDigits(number);

    originalNumber = number;

    while (originalNumber != 0) {
        remainder = originalNumber % 10;
        result += pow(remainder, n);
        originalNumber /= 10;
    }

    if (result == number)
        return 1;  // It's an Armstrong number
    else
        return 0;  // It's not an Armstrong number
}

int main() {
    int lower, upper;

    printf("Enter the range (lower and upper limits): ");
    scanf("%d %d", &lower, &upper);

    printf("Armstrong numbers in the range %d to %d are: \n", lower, upper);
    for (int i = lower; i <= upper; i++) {
        if (isArmstrong(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
