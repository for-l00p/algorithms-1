#include <iostream>
#include <algorithm>
using namespace std;

void sort2(int A[], int i, int j);
int partition(int A[], int i, int j, int p);

int main(){
  int A[] = {2,4,3,1};
  sort2(A, 0, 3);
  for(int i = 0; i < 4; i++){
    cout << A[i] << endl;
  }
  return 0;
}

// input: Array A of at least j elements. Integer i and j.
// Result: A permutation of the i through j elements A such that
// A[i] <= A[i+1] <= A[i+2] <= ... <= A[j]
void sort2(int A[], int i, int j){
  if(i < j){
    //int p = Median(A, i, j);
    int p = A[i];
    int s = partition(A, i, j, p);
    sort2(A, i, s-1);
    sort2(A, s+1, j);
  }
}

// input: array A of at least j elements, integer i and j. array element p
// output: A permutation of array A such that A[s] = p and A[i'] <= p <= A[j'] 
// for i <= i' <= s <= j' <= j. Return s.
int partition(int A[], int i, int j, int p){
  int low = i;
  int high = j;
  while(low < high){
    if(A[low] < p){
      low++;
    }
    else if(A[high] > p){
      high--;
    }
    else{
      swap(A[low], A[high]);
      if(A[low] == p && A[high] == p){
	low++;
      }
    }
  }
  return high;
}

