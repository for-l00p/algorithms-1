/*
 s[~~~~~X```````]    +   s[~~~~~X*`````]
 t[~~X]                  t[~~]
 
 r   a   b   b   b   i   t
 [1  1   1   1   1   1   1   1]
 r   [0  1   1
 a   [0  0   1   1   1
 b   [0  0   0   1   2
 b   [0
 i   [0
 t   [0
 */
class Solution {
public:
  int numDistinct(string s, string t) {
    // initailze, left inheritance is 0;
    vector<vector<int> >dp(t.length()+1, vector<int>(s.length()+1, 0));
    // initilzie, upper inheritance is 1;
    for(int j = 0; j <= s.length(); j++) dp[0][j] = 1;
    for(int i = 0; i < t.length(); i++){
      for(int j = 0; j < s.length(); j++){
	// left inheritance by default. Appending a dummty char in s do no harm.
	dp[i+1][j+1] = dp[i+1][j];
	// upper inheritence when ending char match.
	if(t[i] == s[j]) {
	  dp[i+1][j+1] = dp[i+1][j+1] + dp[i][j];
	}
      }
    }
    return dp[t.length()][s.length()];
  }
};
