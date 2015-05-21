#include <algorithm>
#include <iostream>
using namespace std;

void insertionSort(int arr[], int number_used){
  for(int i = 1; i < number_used; i++){
    int j = i - 1;
    while(j >= 0 && arr[j] > arr[j+1]){
      swap(arr[j], arr[j+1]);
      j--;
    }
  }
}

int main(){
  int arr[] = {2,4,3,1};
  insertionSort(arr, 4);
  for(int i = 0; i < 4; i++){
    cout << arr[i] << endl;
  }
  return 0;
}
