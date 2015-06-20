class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // last position of <
    if(matrix.size() == 0) return false;
    int start = 0, end = matrix.size()-1, mid, row;
    while(start + 1 < end){
      mid = start + (end - start) / 2;
      if(matrix[mid][0] <= target){
	start = mid;
      }
      else{
	end = mid;
      }
    }
    if(matrix[end][0] <= target){
      row = end;
    }
    else if(matrix[start][0] <= target){
      row = start;
    }
    else{
      return false;
    }
    // find first position in this row. // still need to compare.
    start = 0; 
    end = matrix[row].size()-1;
    while(start + 1 < end){
      mid = start + (end - start) / 2;
      if(matrix[row][mid] == target){
	return true;
      }
      else if(matrix[row][mid] < target){
	start = mid;
      }
      else{
	end = mid;
      }
    }
    if(matrix[row][start] == target){
      return true;
    }
    else if(matrix[row][end] == target){
      return true;
    }
    else return false;
  }
};
