/*
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/


class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int> >resultSets;
    // for nums = [1,2,3] generate [000] to [111]
    // for nums = [0] generate [0] to [1]
    for(int i = 0; i < int(pow(2, nums.size())); i++){
      vector<int> aSubset;
      for(int j = 0; j < 32; j++){
	if((i >> j) & 1){
	  aSubset.push_back(nums[j]);
	}
      }
      resultSets.push_back(aSubset);
      return resultSets;
    }
  }
};
