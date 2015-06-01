class Solution {
public:
  int numDecodings(string s) {
    return recursion(s, s.length());
  }
  // starting from s[0] to s[n-1]
  // return decoding ways of this s.substr(0, n).
  int recursion(string &s, int pos){
    int* dp = new int[s.length()+1];
    for(int i = 0; i <= s.length(); i++) dp[i] = 0;
    if(s.length()) dp[0] = 1;
    for(int i = 0; i < s.length(); i++){
      if(s[i] != '0'){
	dp[i+1] += dp[i];
      }
      if(i > 0 && isValid(s[i-1], s[i])){
	dp[i+1] += dp[i-1];
      }
    }
    int result = dp[s.length()];
    delete dp;
    return result;
  }
    
  bool isValid(char tens, char ones){
    if(tens == '0') return false;
    if(tens == '1' && ones <= '9') return true;
    if(tens == '2' && ones <= '6') return true;
    else return false;
  }
};
