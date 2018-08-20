#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.empty()) {
      return result;
    }
    permute(nums, 0, &result);
    return result;
  }

 private:
  void permute(vector<int>& nums, int i, vector<vector<int>>* result) {
    if (i == nums.size()) {
      result->push_back(nums);
      return;
    }

    unordered_set<int> used;
    for (int j = i; j < nums.size(); ++j) {
      if (used.find(nums[j]) == used.end()) {
        swap(nums, i, j);
        permute(nums, i + 1, result);
        swap(nums, i, j);
        used.insert(nums[j]);
      }
    }
  }

  inline void swap(vector<int>& nums, int i, int j) {
    if (i != j) {
      int temp = nums[i];
      nums[i] = nums[j];
      nums[j] = temp;
    }
  }
};
