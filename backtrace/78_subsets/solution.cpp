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
    vector<vector<int> >result;
    if(nums.empty()){
      return result;
    }
    sort(nums.begin(), nums.end());
    vector<int> list;
    backTrack(result, list, nums, 0);
    return result;
  }
private:
  void backTrack(vector<vector<int> >& result, vector<int>& list, vector<int>& nums, int pos){
    result.push_back(list);
    for(int i = pos; i < nums.size(); i++){
      list.push_back(nums[i]);
      backTrack(result, list, nums, i+1);
      list.pop_back();
    }
  }
};
