#include <algorithm>
#include <vector>
using namespace std;

// Definition for an interval.
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

bool cmpIntervalByStart(const Interval& l, const Interval& r) {
  return l.start < r.start;
}

class Solution {
 public:
  vector<Interval> merge(vector<Interval>& intervals) {
    if (intervals.empty()) {
      return intervals;
    }
    sort(intervals.begin(), intervals.end(), cmpIntervalByStart);
    int w = 0;
    for (int r = 1; r < intervals.size(); ++r) {
      if (intervals[r].start <= intervals[w].end) {
        intervals[w].end = max(intervals[w].end, intervals[r].end);
      } else {
        ++w;
        intervals[w].start = intervals[r].start;
        intervals[w].end = intervals[r].end;
      }
    }
    intervals.resize(w + 1);
    return intervals;
  }
};
