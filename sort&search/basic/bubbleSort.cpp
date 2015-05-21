#include <iostream>
#include <algorithm>
using namespace std;

void bubbleSort(int arr[], int number_used){
  int last = number_used - 1;
  while(last){
    for(int i = 0; i < last; i++){
      if(arr[i] > arr[i+1]){
	swap(arr[i], arr[i+1]);
      }
    }
    last--;
  }
}

int main(){
  int arr[] = {22,4,33,1};
  bubbleSort(arr, 4);
  for(int i = 0; i < 4; i++){
    cout << arr[i] << endl;
  }
  return 0;
}
