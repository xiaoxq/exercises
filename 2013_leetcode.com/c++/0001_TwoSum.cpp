#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> pos;
    for (int i = 0; i < nums.size(); ++i) {
      const int remain = target - nums[i];
      if (pos.find(remain) != pos.end()) {
        return {pos[remain], i};
      } else {
        pos[nums[i]] = i;
      }
    }
    return {};
  }
};
