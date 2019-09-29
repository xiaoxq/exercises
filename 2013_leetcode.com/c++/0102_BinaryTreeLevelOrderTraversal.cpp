#include <queue>
#include <vector>
using namespace std;

// Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> result;
    if (root == nullptr) {
      return result;
    }

    vector<int> level;
    queue<TreeNode *> toVisit({root, nullptr});
    while (true) {
      TreeNode *cur = toVisit.front();
      toVisit.pop();
      // end a level
      if (cur == nullptr) {
        result.push_back(level);
        if (toVisit.empty()) {
          break;
        }
        // add a new End-Of-Level
        level.clear();
        toVisit.push(nullptr);
      } else {
        level.push_back(cur->val);
        if (cur->left) {
          toVisit.push(cur->left);
        }
        if (cur->right) {
          toVisit.push(cur->right);
        }
      }
    }
    return result;
  }
};
