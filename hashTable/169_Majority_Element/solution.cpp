/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> m;
    for(int i = 0; i < nums.size(); i++){
      if(m.find(nums[i]) != m.end()){
	(m.find(nums[i])->second)++;
      }
      else{
	m[nums[i]] = 1;
      }
    }
    // iterating through all nums
    unordered_map<int, int>::const_iterator iter;
    for(iter = m.begin(); iter != m.end(); iter++){
      if(iter->second > nums.size()/2){
	return iter->first;
      }
    }
  }
};
