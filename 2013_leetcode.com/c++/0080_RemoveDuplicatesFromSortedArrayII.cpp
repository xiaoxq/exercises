#include <vector>
using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2) {
      return nums.size();
    }

    int w = 2;
    for (int r = 2; r < nums.size(); ++r) {
      if (nums[r] != nums[w - 1] || nums[r] != nums[w - 2]) {
        nums[w++] = nums[r];
      }
    }
    return w;
  }
};
