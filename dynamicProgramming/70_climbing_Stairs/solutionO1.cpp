/*
only save the last two result.
*/

class Solution {
public:
  int climbStairs(int n) {
    int cur = 1, one_back = 1, two_back = 1;
    for(int i = 2; i <= n; i++){
      cur = one_back + two_back;
      two_back = one_back;
      one_back = cur;
    }
    return cur;
  }
};
