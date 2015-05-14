/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/

class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    const int m = matrix.size();
    if(m < 1) return;
    const int n = matrix[0].size();
    vector<bool> row(m, false);
    vector<bool> column(n, false);
        
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
	if(matrix[i][j] == 0){
	  row[i] = true;
	  column[j] = true;
	}
      }
    }
       
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
	if(row[i]) matrix[i][j] = 0;
	else if(column[j]) matrix[i][j] = 0;
      }
    }
        
  }
};
