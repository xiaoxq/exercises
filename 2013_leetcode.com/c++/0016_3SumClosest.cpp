#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int closest = INT_MAX;
    for (int i = 0; i < nums.size() - 2; ++i) {
      if (i == 0 || nums[i] != nums[i - 1]) {
        const int cur_closest =
            twoSumClosestDiff(nums, i + 1, target - nums[i], closest);
        if (abs(cur_closest) < abs(closest)) {
          closest = cur_closest;
        }
        if (closest == 0) {
          return target;
        }
      }
    }
    return target - closest;
  }

 private:
  int twoSumClosestDiff(const vector<int>& nums, const int index,
                        const int target, int closest) {
    int left = index, right = nums.size() - 1;
    while (left < right) {
      const int diff = target - nums[left] - nums[right];
      if (diff == 0) {
        return 0;
      }
      if (abs(diff) < abs(closest)) {
        closest = diff;
      }
      if (diff > 0) {
        ++left;
      } else {
        --right;
      }
    }
    return closest;
  }
};
