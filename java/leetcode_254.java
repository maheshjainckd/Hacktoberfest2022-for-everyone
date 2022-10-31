public leetcode {
    public List<List<Integer>> getFactors(int n) {
        List<List<Integer>> result = new LinkedList<List<Integer>>();
        process(2, result, new LinkedList<Integer>(), n);
        return result;
    }
    private void process(int start, List<List<Integer>> result, List<Integer> curr, int n) {
        if (n == 1) {
            if (curr.size() > 1) {
                result.add(new LinkedList<Integer>(curr));
            }
        }
        for (int i = start; i <= n; i ++) {
            if (n % i == 0) {
                curr.add(i);
                process(i, result, curr, n / i);
                curr.remove(curr.size() - 1);
            }
        }
    }
}
