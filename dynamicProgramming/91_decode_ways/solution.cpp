/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

Show Tags
*/
class Solution {
public:
  int numDecodings(string s) {
    return recursion(s, s.length());
  }
  // starting from s[0] to s[n-1]
  // return decoding ways of this s.substr(0, n).
  int recursion(string &s, int pos){
    if(pos == 0) return 0;
    int numsWays = 0;
    if(s[pos-1] != '0'){
      numsWays += recursion(s, pos - 1);
    }
    if(pos >= 2 && isValid(s[pos-2], s[pos-1])){
      numsWays += recursion(s, pos - 2);
    }
    return numsWays;
  }
    
  bool isValid(char tens, char ones){
    if(tens == '0') return false;
    if(tens == '1' && ones <= '9') return true;
    if(tens == '2' && ones <= '6') return true;
    else return false;
  }
};
