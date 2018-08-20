#include <vector>
using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left + 1 < right) {
      const int mid = (left + right) / 2;
      if (target < nums[mid]) {
        right = mid;
      } else {
        left = mid;
      }
    }
    return nums[left] >= target ? left : right;
  }
};
