/*
s3 = 'aad'
      [j-1]
        a   a   b
    T   T   T   F   
d   F   F                     
b         
b

*/

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    // incase Input:"", "", "a"
    if(s3.length() > s1.length() + s2.length()) return false;
    vector<vector<bool> >dp(s2.length()+1, vector<bool>(s1.length()+1, false));
    for(int i = 0; i <= s2.length(); i++){
      for(int j = 0; j <= s1.length(); j++){
	if(i == 0 && j == 0) {
	  dp[i][j] = true;
	  continue;
	}
	if(j-1 >= 0 && s3[i+j-1] == s1[j-1]) dp[i][j] = dp[i][j-1];
	if(i-1 >= 0 && s3[i+j-1] == s2[i-1]) dp[i][j] = dp[i][j] + dp[i-1][j];
      }
    }
    return dp[s2.length()][s1.length()];
  }
};
