public class Array2 {
    // Print a Pattern According to The Given Value of A.

    // Example: For A = 3 pattern looks like:

    // 1 0 0

    // 1 2 0

    // 1 2 3
    public int[][] solve(int A) {
        int[][] ans = new int[A][A];

        for (int i = 0; i < A; ++i) {
            for (int j = 0; j <= i; ++j)
                ans[i][j] = j + 1;
        }
        return ans;
    }
}
