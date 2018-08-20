#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> prefix;
    sort(nums.begin(), nums.end());
    getSubsets(nums, 0, &prefix, &result);
    return result;
  }

 private:
  void getSubsets(const vector<int>& nums, int index,
                 vector<int>* prefix, vector<vector<int>>* result) {
    if (index == nums.size()) {
      result->push_back(*prefix);
      return;
    }
    // Take current.
    prefix->push_back(nums[index]);
    getSubsets(nums, index + 1, prefix, result);
    prefix->pop_back();
    // Skip current.
    while (index + 1 < nums.size() && nums[index + 1] == nums[index]) {
      ++index;
    }
    getSubsets(nums, index + 1, prefix, result);
  }
};
