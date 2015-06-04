/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

  Follow up:
  If this function is called many times, how would you optimize it?

  Related problem: Reverse Integer
*/

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    for(int i = 0, j = 31; i < j; ){
      n = swapBit(n, i, j);
      i++; j--;
    }
    return n;
  }
  int swapBit(int n, int i, int j){
    if(((n >> i) & 1) != ((n >> j) & 1)){
      n ^= (1 << i) | (1 << j);
    }
    return n;
  }
};
