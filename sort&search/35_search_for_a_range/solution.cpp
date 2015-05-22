// Thanks http://blog.csdn.net/kenden23/article/details/17068717
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> indexRange(2, -1);
    int mid = binarySearch(nums, target, 0, nums.size()-1);
    if(mid == -1) return indexRange;
    for(int i = mid; i >= 0 && nums[i] == nums[mid]; i--){
      indexRange[0] = i;
    }
    for(int i = mid; i < nums.size() && nums[i] == nums[mid]; i++){
      indexRange[1] = i;
    }
    return indexRange;
  }
    
  int binarySearch(vector<int>& nums, int target, int first, int last){
    if(first > last){
      return -1;
    }
    int mid = (first + last)/2;
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
};
