#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    if (nums.empty()) {
      return result;
    }

    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      // no duplicate
      if (i == 0 || nums[i] != nums[i-1]) {
        twoSum(nums, i, result);
      }
    }
    return result;
  }

 private:
  void twoSum(const vector<int>& num, const int minNumIndex,
              vector<vector<int>>& result) {
    int left = minNumIndex + 1, right = num.size() - 1, sum = -num[minNumIndex];
    while (left < right) {
      // no duplicate
      if (left > minNumIndex + 1 && num[left] == num[left - 1]) {
        ++left;
        continue;
      }

      const int cur_sum = num[left] + num[right];
      if (cur_sum == sum) {
        result.push_back({num[minNumIndex], num[left], num[right]});
        ++left;
        --right;
      } else {
        cur_sum > sum ? --right : ++left;
      }
    }
  }
};
