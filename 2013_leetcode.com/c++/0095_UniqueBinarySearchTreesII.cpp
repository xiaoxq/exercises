#include <queue>
#include <vector>
using namespace std;

// Definition for binary tree
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  vector<TreeNode*> generateTrees(int n) {
    if (n == 0) {
      return {};
    }
    vector<int> values;
    for (int i = 1; i <= n; ++i) {
      values.push_back(i);
    }
    return generateTrees(values);
  }

 private:
  vector<TreeNode*> generateTrees(const vector<int>& values) {
    vector<TreeNode*> result;
    if (values.empty()) {
      result.push_back(nullptr);
      return result;
    }
    if (values.size() == 1) {
      result.push_back(new TreeNode(values[0]));
      return result;
    }
    for (int i = 0; i < values.size(); ++i) {
      vector<int> left_values, right_values;
      for (int j = 0; j < i; ++j) {
        left_values.push_back(values[j]);
      }
      for (int j = i + 1; j < values.size(); ++j) {
        right_values.push_back(values[j]);
      }
      vector<TreeNode*> left_trees = generateTrees(left_values);
      vector<TreeNode*> right_trees = generateTrees(right_values);
      for (auto* left_node : left_trees) {
        for (auto* right_node : right_trees) {
          auto* root = new TreeNode(values[i]);
          root->left = left_node;
          root->right = right_node;
          result.push_back(root);
        }
      }
    }
    return result;
  }
};
