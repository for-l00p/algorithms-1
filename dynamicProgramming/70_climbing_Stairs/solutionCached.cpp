class Solution {
public:
  int climbStairs(int n) {
    unordered_map<int, int>cache;
    return climbStairsCached(n, cache);
  }
  int climbStairsCached(int n, unordered_map<int, int>& cache){
    if(n < 2) return 1;
    if(cache.find(n) != cache.end()){
      return cache[n];
    }
    int val = climbStairsCached(n-1, cache) + climbStairsCached(n-2, cache);
    cache[n] = val;
    return val;
  }
};
