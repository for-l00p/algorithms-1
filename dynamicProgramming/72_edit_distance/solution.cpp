/*
dp[][] stores the numbers of steps needed from kitten to sitten.

    k   i   t   t   e   n
s   1   2   3   4   5   6
i   2   1   
t
t
e
n

---------------
update  |delete
---------------
insert  |target
---------------

*/
class Solution {
public:
  int minDistance(string word1, string word2) {
    vector<vector<int> >dp(word2.length()+1, vector<int>(word1.length()+1, 0));
    // initialze under empty string condition.
    for(int i = 0; i <= word2.length(); i++) dp[i][0] = i;
    for(int j = 0; j <= word1.length(); j++) dp[0][j] = j;
        
    for(int i = 0; i < word2.length(); i++){
      for(int j = 0; j < word1.length(); j++){
	// if ending char matches, the problem shrinks to left corner problem.
	if(word2[i] == word1[j]){
	  dp[i+1][j+1] = dp[i][j];
	}
	else{
	  dp[i+1][j+1] = 1 + std::min(dp[i][j], std::min(dp[i][j+1], dp[i+1][j]));
	}
      }
    }
    return dp[word2.length()][word1.length()];
  }
};
