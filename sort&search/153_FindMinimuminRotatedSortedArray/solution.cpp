/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/
 /*
   /|
  / |
 /  |
----|----    
    |   /
    |  /
    | /
    |/
 */
class Solution {
public:
  int findMin(vector<int>& nums) {
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
    if(nums[start] < nums[end]) return nums[start];
    else return nums[end];
  }
};
