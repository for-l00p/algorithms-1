#include <iostream>
using namespace std;

void printArr(int arr[], int size){
  for(int i = 0; i < size; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main(){
  int arr[8] = {0,0,1,1,1,0,0,1};
  printArr(arr, 8);
  int leftShift[8];
  for(int i = 0; i < 7; i++){
    leftShift[i] = arr[i+1];
  }
  leftShift[7] = 0;
  int rightShift[8];
  for(int i = 1; i < 8; i++){
    rightShift[i] = arr[i-1];
  }
  rightShift[0] = 0;
  for(int i = 0; i < 8; i++){
    arr[i] = leftShift[i] ^ rightShift[i];
  }
  printArr(arr, 8);
  return 0;
}
