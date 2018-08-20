#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());

    vector<vector<int> > result;
    vector<int> prefix;
    findCombinations(candidates, 0, target, &result, &prefix);
    return result;
  }

 private:
  void findCombinations(const vector<int>& candidates, const int index,
                        const int target,
                        vector<vector<int>>* result, vector<int>* prefix) {
    if (target == 0) {
      result->push_back(*prefix );
      return;
    }

    // out of index or exceed
    if (index == candidates.size() || candidates[index] > target) {
      return;
    }
    // use candidates[index] once
    prefix->push_back(candidates[index]);
    findCombinations(candidates, index, target-candidates[index], result, prefix);
    prefix->pop_back();

    // no use candidates[index]
    findCombinations(candidates, index+1, target, result, prefix);
  }
};
