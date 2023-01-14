package Recursion;

public class ReduceSteps {
    public static int main(String[] args) {
        return counter(12030, 0);
    }

    public static int counter(int n, int steps) {
        if (n == 0) {
            return steps;
        }
        if (n % 2 == 0) {
            return counter(n / 2, steps + 1);
        }
        return counter(n - 1, steps + 1);
    }
}
