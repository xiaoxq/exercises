#include <vector>
using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    int w = 0;
    for (int r = 1; r < nums.size(); ++r) {
      if (nums[w] == nums[r]) {
        continue;
      }
      nums[++w] = nums[r];
    }
    return w + 1;
  }
};
