#include <vector>
using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int w = 0;
    for (const int num : nums) {
      if (num != val) {
        nums[w++] = num;
      }
    }
    return w;
  }
};
