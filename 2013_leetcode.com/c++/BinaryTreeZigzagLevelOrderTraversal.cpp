/*
 * Problem: http://leetcode.com/onlinejudge#question_103
 */

#include <vector>
#include <stack>
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
	vector<vector<int> > zigzagLevelOrder(TreeNode *root)
	{
		vector<vector<int> > result;
		if( root==NULL )
			return result;

		vector<int> level;
		stack<TreeNode*> toVisit[2];
		int curStackIndex = 0;
		toVisit[curStackIndex].push( root );

		bool leftToRight = false;
		while( true )
		{
			stack<TreeNode*>& curStack = toVisit[curStackIndex%2];
			stack<TreeNode*>& nextStack = toVisit[(curStackIndex+1)%2];
			// end a level
			if( curStack.empty() )
			{
				result.push_back( level );
				if( nextStack.empty() )
					break;
				// swap
				++curStackIndex;
				level.clear();
				leftToRight = !leftToRight;
			}
			else
			{
				TreeNode *cur = curStack.top(); curStack.pop();
				level.push_back( cur->val );
				// note that stack will do one more reverse
				if( leftToRight )
				{
					if( cur->right )
						nextStack.push( cur->right );
					if( cur->left )
						nextStack.push( cur->left );
				}
				else
				{
					if( cur->left )
						nextStack.push( cur->left );
					if( cur->right )
						nextStack.push( cur->right );
				}
			}
		}
		return result;
	}
};
