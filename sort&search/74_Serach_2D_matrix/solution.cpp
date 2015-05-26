/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = binarySearchRowWise(matrix, target, 0, matrix.size()-1);
    row--;
    if(row < 0) return false;
    int column = binarySearchColumnWise(matrix, row, target, 0, matrix[0].size()-1);
    if(column == -1){
      return false;
    }
    else{
      return true;
    }
        
  }
  int binarySearchRowWise(vector<vector<int> >&matrix, int target, int first, int last){
    if(first > last) return first;
  int mid = (first + last)/2;
  if(target == matrix[mid][0]) return mid + 1;
  if(target < matrix[mid][0]){
    return binarySearchRowWise(matrix, target, first, mid-1);
  }
  return binarySearchRowWise(matrix, target, mid+1, last);
}
  int binarySearchColumnWise(vector<vector<int> >&matrix, const int row, int target, int first, int last){
    if(first > last) return -1;
int mid = (first + last)/2;
if(target == matrix[row][mid]) return mid;
if(target < matrix[row][mid]){
  return binarySearchColumnWise(matrix, row, target, first, mid - 1);
 }
return binarySearchColumnWise(matrix, row, target, mid + 1, last);
}
};
