class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int> >pascalsTri;
    for(int i = 0; i < numRows; i++){
      vector<int> curRow;
      for(int j = 0; j <= i; j++){
	if(j == i || j == 0){
	  curRow.push_back(1);
	}
	else{
	  curRow.push_back(pascalsTri[i-1][j-1] + pascalsTri[i-1][j]);
	}
      }
      pascalsTri.push_back(curRow);
    }
    return pascalsTri;
  }
};
