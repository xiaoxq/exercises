#include <tuple>
#include <vector>
using namespace std;

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    vector<tuple<int, int>> height_width;
    int largest = 0;

    for (const int height : heights) {
      // Settle those higher than current height.
      int cur_width = 0;
      while (!height_width.empty()) {
        int pre_height, width;
        std::tie(pre_height, width) = height_width.back();
        if (pre_height <= height) {
          break;
        }
        cur_width += width;
        largest = max(largest, pre_height * cur_width);
        height_width.pop_back();
      }
      height_width.emplace_back(height, cur_width + 1);
    }

    // Settle all.
    int cur_width = 0;
    for (auto it = height_width.rbegin(); it != height_width.rend(); ++it) {
      int height, width;
      std::tie(height, width) = *it;
      cur_width += width;
      largest = max(largest, cur_width * height);
    }
    return largest;
  }
};
