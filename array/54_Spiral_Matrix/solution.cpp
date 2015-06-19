/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> sentence;
    int iMin = 0, iMax = matrix.size() - 1;
    if(iMax < 0) return sentence;
    int jMin = 0, jMax = matrix[0].size()-1;
        
    while(true){
      for(int j = jMin; j <= jMax; j++){
	sentence.push_back(matrix[iMin][j]);
      }
      iMin++;
      if(iMin > iMax || jMin > jMax) break;
            
      for(int i = iMin; i <= iMax; i++){
	sentence.push_back(matrix[i][jMax]);
      }
      jMax--;
      if(iMin > iMax || jMin > jMax) break;
            
      for(int j = jMax; j >= jMin; j--){
	sentence.push_back(matrix[iMax][j]);
      }
      iMax--;
      if(iMin > iMax || jMin > jMax) break;
            
      for(int i = iMax; i >= iMin; i--){
	sentence.push_back(matrix[i][jMin]);
      }
      jMin++;
      if(iMin > iMax || jMin > jMax) break;
    }
        
    return sentence;
  }
};
