#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    vector<int> prefix;
    prefix.reserve(nums.size());
    getSubsets(nums, nums.begin(), &prefix, &result);
    return result;
  }

 private:
  void getSubsets(const vector<int>& nums, vector<int>::const_iterator cur,
                  vector<int>* prefix, vector<vector<int>>* result) {
    if (cur == nums.end()) {
      result->push_back(*prefix);
      return;
    }

    // Without current.
    getSubsets(nums, cur + 1, prefix, result);
    // With current.
    prefix->push_back(*cur);
    getSubsets(nums, cur + 1, prefix, result);
    prefix->pop_back();
  }
};
