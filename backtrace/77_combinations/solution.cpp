/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int> > resultSet;
    if(!k || k > n) return resultSet;
    vector<int> combo;
    backTrack(n, k, 1, combo, resultSet);
    return resultSet;
  }
private:
  void backTrack(int n, int k, int pos, vector<int> &combo, vector<vector<int> >&resultSet){
    for(int i = pos; i <= n; i++){
      combo.push_back(i);
      if(combo.size() == k){
	resultSet.push_back(combo);
	combo.pop_back();
	continue;
      }
      backTrack(n, k, i+1, combo, resultSet);
      combo.pop_back();
    }
  }
};
