#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left + 1 < right) {
      const int mid = (left + right) / 2;
      if (nums[mid] > target) {
        right = mid;
      } else if (nums[mid] < target) {
        left = mid;
      } else {
        return {searchLeft(nums, target, left, mid),
                searchRight(nums, target, mid + 1, right)};
      }
    }
    if (left + 1 == right && nums[left] == target) {
      return {left, left};
    }
    return {-1, -1};
  }

 private:
  // Find the first target, or return right.
  int searchLeft(const vector<int>& nums, const int target, int left,
                 int right) {
    while (left < right) {
      const int mid = (left + right) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return right;
  }

  // Find the last target, or return left - 1.
  int searchRight(const vector<int>& nums, const int target, int left,
                  int right) {
    while (left < right) {
      const int mid = (left + right) / 2;
      if (nums[mid] > target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left - 1;
  }
};
