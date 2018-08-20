/*
 * Problem: http://leetcode.com/onlinejudge#question_57
 */
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

class Solution {
 public:
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> result;
    result.reserve(intervals.size() + 1);

    int i = 0;
    for (; i < intervals.size() && intervals[i].end < newInterval.start; ++i) {
      result.push_back(intervals[i]);
    }

    if (i == intervals.size() || newInterval.end < intervals[i].start) {
      result.push_back(newInterval);
    } else {
      newInterval.start = min(newInterval.start, intervals[i].start);
      newInterval.end = max(newInterval.end, intervals[i].end);
      while (++i < intervals.size() && intervals[i].start <= newInterval.end) {
        newInterval.end = max(newInterval.end, intervals[i].end);
      }
      result.push_back(newInterval);
    }
    for (; i < intervals.size(); ++i) {
      result.push_back(intervals[i]);
    }
    return result;
  }
};
