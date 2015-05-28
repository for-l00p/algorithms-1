/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int> >pascalsTri;
    recursion(pascalsTri, numRows-1);
    return pascalsTri;
  }
  void recursion(vector<vector<int> >& pascalsTri, int nthRow){
    if(nthRow < 0) return;
    recursion(pascalsTri, nthRow-1);
    vector<int> curRow;
    curRow.push_back(1);
    for(int i = 1; i < nthRow; i++){
      curRow.push_back(pascalsTri[nthRow-1][i-1] + pascalsTri[nthRow-1][i]);
    }
    if(nthRow) curRow.push_back(1);
    return pascalsTri.push_back(curRow);
  }
};
