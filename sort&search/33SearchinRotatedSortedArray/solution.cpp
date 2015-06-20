/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
class Solution {
public:
  int search(vector<int>& nums, int target) {
    int min = findMinIndex(nums);
    vector<int> monoton;
    for(int i = min; i < nums.size(); i++){
      monoton.push_back(nums[i]);
    }
    for(int i = 0; i < min; i++){
      monoton.push_back(nums[i]);
    }
    int monoIndex = searchST(monoton, target);
    if(monoIndex == -1) return -1;
    else return (monoIndex + min) % nums.size();
  }
    
  int searchST(vector<int>& nums, int target) {
    if(nums.size() == 0) return 0;
    int start = 0, end = nums.size() - 1, mid;
    while(start + 1 < end){
      mid = start + (end - start) / 2;
      if(nums[mid] >= target){
	end = mid;
      }
      else{
	start = mid;
      }
    }
    if(nums[start] == target) return start;
    else if(nums[end] == target) return end;
    else return -1;
  }
  int findMinIndex(vector<int>& nums) {
    int target = nums[nums.size()-1];
    int start = 0, end = nums.size() - 1, mid;
    while(start + 1 < end){
      mid = start + (end - start) / 2;
      if(nums[mid] > target){
	start = mid;
      }
      else if(nums[mid] < target){
	end = mid;
      }
    }
    if(nums[start] < nums[end]) return start;
    else return end;
  }
};
