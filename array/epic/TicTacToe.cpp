#include <iostream>
using namespace std;

int findCount(const char matrix[4][4], int row, int col, char c);

int main(){
  char matrix[4][4] = { { 'r', 'r', 'r', 'b' }, 
		      { 'b', 'r', 'b', 'r' },
		      { 'b', 'r', 'r', 'b' }, 
		      { 'b', 'r', 'b', 'b' } };
  int red_count = findCount(matrix, 4, 4, 'r');
  int blue_count = findCount(matrix, 4, 4, 'b');
  cout << "Count of red triplets: " << red_count << endl;
  cout << "Count of blue triplets: " << blue_count << endl;
}

int findCount(const char matrix[4][4], int row, int col, char c){
  int count = 0;
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col - 2; j++){
      if(matrix[i][j] == c && matrix[i][j+1] == c && matrix[i][j+2] == c){
	count++;
      }
    }
  }
  for(int i = 0; i < row - 2; i++){
    for(int j = 0; j < col; j++){
      if(matrix[i][j] == c && matrix[i+1][j] == c && matrix[i+2][j] == c){
	count++;
      }
    }
  }
  for(int i = 0; i < row - 2; i++){
    for(int j = 0; j < col - 2; j++){
      if(matrix[i][j] == c && matrix[i+1][j+1] == c && matrix[i+2][j+2] == c){
	count++;
      }
    }
  }

  // right-upper to left-down, start the index complying the condition.
  for(int i = 0; i + 2 < row; i++){
    for(int j = col - 1; j - 2 >=  0; j--){
      if(matrix[i][j] == c && matrix[i+1][j-1] == c && matrix[i+2][j-2] == c){
	count++;
      }
    }
  }
  return count;
}
      
