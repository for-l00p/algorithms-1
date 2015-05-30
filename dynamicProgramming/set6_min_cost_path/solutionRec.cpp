class Solution {
public:
  /**
   * @param grid: a list of lists of integers.
   * @return: An integer, minimizes the sum of all numbers along its path
   */
  int minPathSum(vector<vector<int> > &grid) {
    return recursion(grid, grid.size() - 1, grid[0].size()-1);
  }
  int recursion(const vector<vector<int> >& grid, int i, int j){
    if( i == 0 & j == 0) return grid[i][j];
    else if(i == 0) return grid[i][j] + recursion(grid, i, j - 1);
    else if(j == 0) return grid[i][j] + recursion(grid, i - 1, j);
    else
      return grid[i][j] + std::min(recursion(grid, i - 1, j), recursion(grid, i, j - 1));
  }
};
