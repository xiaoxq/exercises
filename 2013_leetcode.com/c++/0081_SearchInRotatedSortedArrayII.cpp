#include <vector>
using namespace std;

class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    return searchRotated(nums, 0, nums.size(), target);
  }

 private:
  bool searchRotated(const vector<int>& nums, int left, int right,
                     const int target) {
    if (left == right) {
      return false;
    }
    while (left + 1 < right) {
      const int mid = (left + right) / 2;
      if (nums[mid] == target) {
        return true;
      } else if (nums[mid] > nums[left]) {
        // Left part is sorted.
        if (target >= nums[left] && target < nums[mid]) {
          return searchSorted(nums, left, mid, target);
        } else {
          left = mid;
        }
      } else if (nums[mid] < nums[right - 1]) {
        // right part is sorted.
        if (target >= nums[mid] && target < nums[right - 1]) {
          return searchSorted(nums, mid, right, target);
        } else {
          right = mid;
        }
      } else if (searchRotated(nums, left, mid, target)) {
        return true;
      } else {
        left = mid;
      }
    }
    return nums[left] == target;
  }

  bool searchSorted(const vector<int>& nums, int left, int right,
                    const int target) {
    // CHECK_LT(left, right);
    while (left + 1 < right) {
      const int mid = (left + right) / 2;
      if (nums[mid] > target) {
        right = mid;
      } else {
        left = mid;
      }
    }
    return nums[left] == target;
  }
};
