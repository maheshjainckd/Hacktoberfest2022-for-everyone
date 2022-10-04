/**
 * @param {number} n
 * @return {number}
 */
var numTrees = function (n) {
  const cache = [];

  const dfs = (node) => {
    if (node === 1) return 1;
    if (cache[node]) return cache[node];

    let totalCount = 0;
    for (let i = 1; i <= node; i++) {
      const lCount = i > 1 ? dfs(i - 1) : 1;
      const rCount = i < node ? dfs(node - i) : 1;
      totalCount += lCount * rCount;
    }

    cache[node] = totalCount;

    return totalCount;
  };

  return dfs(n);
};

console.log(numTrees(3));
// output: 5
