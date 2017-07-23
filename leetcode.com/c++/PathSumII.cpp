/*
 * Problem: http://leetcode.com/onlinejudge#question_113
 */

#include <vector>
using namespace std;

#define NULL 0

// Definition for binary tree
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum)
	{
		vector<int> prefix;
		vector<vector<int> > result;
		pathSum( root, sum, prefix, result );
		return result;
	}
private:
	void pathSum(TreeNode *root, int sum,
			vector<int>& prefix, vector<vector<int> >& result )
	{
		if( root==NULL )
			return;

		sum -= root->val;
		prefix.push_back( root->val );

		if( sum==0 && root->left==NULL && root->right==NULL )
			result.push_back( prefix );
		else
		{
			pathSum( root->left, sum, prefix, result );
			pathSum( root->right, sum, prefix, result );
		}

		prefix.pop_back();
	}
};
