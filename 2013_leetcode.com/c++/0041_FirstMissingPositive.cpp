#include <vector>
using namespace std;

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      while (nums[i] >= 1 && nums[i] <= nums.size() &&
             nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) {
        swap(nums, i, nums[i] - 1);
      }
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    return nums.size() + 1;
  }

 private:
  void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
};
