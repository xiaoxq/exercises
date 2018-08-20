#include <vector>
using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    return searchRotated(nums, target, 0, nums.size());
  }

 private:
  // [left, right)
  int searchRotated(const vector<int>& nums, const int target,
                    int left, int right) {
    while (left + 1 < right) {
      const int mid = (left + right) / 2;
      if (nums[left] < nums[mid]) {
        if (target >= nums[left] && target < nums[mid]) {
          // search [left, mid)
          return searchOrdered(nums, target, left, mid);
        } else {
          // search [mid, right)
          left = mid;
        }
      } else {
        if (target >= nums[mid] && target <= nums[right - 1]) {
          // search [mid, right)
          return searchOrdered(nums, target, mid, right);
        } else {
          right = mid;
        }
      }
    }
    if (left + 1 == right && nums[left] == target) {
      return left;
    }
    return -1;
  }

  int searchOrdered(const vector<int>& nums, const int target,
                    int left, int right) {
    if (target < nums[left] || target > nums[right - 1]) {
      return -1;
    }
    while (left + 1 < right) {
      const int mid = (left + right) / 2;
      if (target < nums[mid]) {
        right = mid;
      } else {
        left = mid;
      }
    }
    if (left + 1 == right && nums[left] == target) {
      return left;
    }
    return -1;
  }
};
