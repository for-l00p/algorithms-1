#include <iostream>
#include <vector>
using namespace std;

void print2dVector(const vector<vector<int> >& v){
  int row = v.size();
  if(!row) return;
  int col = v[0].size();
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

void rotateImg(vector<vector<int> >& matrix, bool clkWise){
  int m = matrix.size();
  if(m == 0) return;
  int n = matrix[0].size();
  vector<vector<int> > rotMatrix(n, vector<int>(m));
  
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(clkWise){
	rotMatrix[j][m-1-i] = matrix[i][j];
      }
      else{
	rotMatrix[n-1-j][i] = matrix[i][j];
      }
    }
  }
  matrix.resize(n);
  for(int i = 0; i < n; i++){
    matrix[i].resize(m);
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      matrix[i][j] = rotMatrix[i][j];
    }
  }
}

int main(){
  vector<vector<int> >image;
  vector<int> line;
  for(int i = 0; i < 2; i++){
    cout << "now input a value for row " << i<< ", -1 to end the line\n";
    int val;
    cin >> val;
    while(val != -1){
      line.push_back(val);
      cout << "input a value, -1 to end the line\n";
      cin >> val;
    }
    image.push_back(line);
    line.clear();
  }
  print2dVector(image);
  cout << "rotate clockwise \n";
  rotateImg(image, true);
  print2dVector(image);
  cout << "rotate anti-clockwise \n";
  rotateImg(image, false);
  print2dVector(image);
  return 0;
}
