#include <climit>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int min_sum = 0;
    int result = INT_MIN;

    for (const int num : nums) {
      sum += num;
      if (sum - min_sum > result) {
        result = sum - min_sum;
      }
      min_sum = min(min_sum, sum);
    }
    return result;
  }
};
