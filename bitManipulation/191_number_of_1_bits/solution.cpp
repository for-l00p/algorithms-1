class Solution {
public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    int i = 1;
    while(i <= n){
      if(i & n) count++;
      i << 1;
    }
    return count;
  }
};
