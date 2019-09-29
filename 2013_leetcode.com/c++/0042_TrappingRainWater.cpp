#include <vector>
using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    if (height.size() <= 2) {
      return 0;
    }

    vector<int> highest_to_left = height;
    for (int i = 1; i < height.size(); ++i) {
      highest_to_left[i] = max(highest_to_left[i], highest_to_left[i - 1]);
    }

    int result = 0;
    int highest_to_right = height.back();
    for (int i = height.size() - 2; i >= 1; --i) {
      int water = min(highest_to_right, highest_to_left[i]) - height[i];
      if (water > 0) {
        result += water;
      }
      highest_to_right = max(highest_to_right, height[i]);
    }
    return result;
  }
};
