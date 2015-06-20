class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> rangeIndex(2, -1);
    if(nums.size() == 0){
      return rangeIndex;
    }
    int start = 0;
    int end = nums.size() - 1;
    int mid;
        
    // search first position
    while(start + 1 < end){
      mid = start + (end - start) / 2;
      if(nums[mid] >= target){
	end = mid;
      }
      else {
	start = mid;
      }
    }
    if(nums[start] == target){
      rangeIndex[0] = start;
    }
    else if(nums[end] == target){
      rangeIndex[0] = end;
    }
        
    // search for last position
    start = 0;
    end = nums.size() - 1;
    while(start + 1 < end){
      mid = start + (end - start) / 2;
      if(nums[mid] <= target){
	start = mid;
      }
      else {
	end = mid;
      }
    }
    if(nums[end] == target){
      rangeIndex[1] = end;
    }
    else if(nums[start] == target){
      rangeIndex[1] = start;
    }
    return rangeIndex;
  }
};
