class Solution {
public:
  /**
   * @param grid: a list of lists of integers.
   * @return: An integer, minimizes the sum of all numbers along its path
   */
  int minPathSum(vector<vector<int> > &grid) {
    int* pathSum = new int[grid[0].size()];
    for(int i = 0; i < grid.size(); i++){
      for(int j = 0; j < grid[0].size(); j++){
	if(i == 0 && j == 0){
	  pathSum[j] = grid[i][j];
	}
	else if(i == 0){
	  pathSum[j] = grid[i][j] + pathSum[j - 1];
	}
	else if(j == 0){
	  pathSum[j] = grid[i][j] + pathSum[j];
	}
	else if(pathSum[j-1] < pathSum[j]){
	  pathSum[j] = grid[i][j] + pathSum[j-1];
	}
	else {
	  pathSum[j] = grid[i][j] + pathSum[j];
	}
      }
    }
    int result = pathSum[grid[0].size() - 1];
    delete pathSum;
    return result;
  }
};
