/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    return binarySearch(nums, target, 0, nums.size()-1);
  }
    
  int binarySearch(vector<int>& nums, int target, int first, int last){
    int mid = (first + last)/2;
    if(first > last){
      return first;
    }
    else{
      mid = (first + last)/2;
      if(target == nums[mid]){
	return mid;
      }
      else if(target < nums[mid]){
	return binarySearch(nums, target, first, mid - 1);
      }
      else if(target > nums[mid]){
	return binarySearch(nums, target, mid + 1, last);
      }
    }
  }
};
