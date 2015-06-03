class Solution {
public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    while(n){
      if(1 & n) count++;
      n >> 1;
    }
    return count;
  }
};
