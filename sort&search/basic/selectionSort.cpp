#include <algorithm>
#include <iostream>
using namespace std;

void selectionSort(int arr[], int number_used);
int indexOfSmallest(int arr[], int number_used, int start);

int main(){
  int arr[] = {2,4,1,3};
  selectionSort(arr, 4);
  for(int i = 0; i < 4; i++){
    cout << arr[i] << endl;
  }
  return 0;
}


void selectionSort(int arr[], int number_used){
  for(int i = 0; i < number_used; i++){
    int next_index_of_smallest = indexOfSmallest(arr, number_used, i);
    swap(arr[i], arr[next_index_of_smallest]);
  }
}

int indexOfSmallest(int arr[], int number_used, int start){
  int candidate = arr[start];
  int index_of_candidate = start;
  for(int i = start; i < number_used; i++){
    if(arr[i] < candidate){
      candidate = arr[i];
      index_of_candidate = i;
    }
    else{
      continue;
    }
  }
  return index_of_candidate;
}
