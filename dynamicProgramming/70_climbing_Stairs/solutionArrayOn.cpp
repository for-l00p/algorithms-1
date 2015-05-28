// improved version from hashmap, use array index to serve as hash key,
// take advantage of array access is O(n), save space without losing time scaling

class Solution {
public:
  int climbStairs(int n) {
    int * arr = new int[n+1] ;
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2; i <= n; i++){
      arr[i] = arr[i-1] + arr[i-2];
    }
    int returnVal = arr[n];
    delete []arr;
    return returnVal;
  }
};
