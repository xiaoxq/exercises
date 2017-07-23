/*
 * Problem: http://leetcode.com/onlinejudge#question_95
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
	vector<TreeNode *> generateTrees(int n)
	{
		vector< vector<TreeNode*> > subtreeSets;
		subtreeSets.push_back( vector<TreeNode*>(1,(TreeNode*)NULL) );
		for( int i=1; i<=n; ++i )
			genSubtrees( subtreeSets, i );

		// release unused trees
		queue<TreeNode*> toDel;
		for( int i=0; i<n; ++i )
		{
			for( vector<TreeNode*>::iterator it=subtreeSets[i].begin(); it!=subtreeSets[i].end(); ++it )
				toDel.push( *it );
		}
		while( !toDel.empty() )
		{
			TreeNode* pickOne = toDel.front(); toDel.pop();
			if( pickOne->left )
				toDel.push( pickOne->left );
			if( pickOne->right )
				toDel.push( pickOne->right );
			delete pickOne;
		}

		return subtreeSets[n];
	}
private:
	void genSubtrees( vector< vector<TreeNode*> >& subtreeSets, int n )
	{
		vector<TreeNode*> result;
		for( int left=0; left<n; ++left )
		{
			int right = n-1-left;
			vector<TreeNode*>& leftSubtrees = subtreeSets[left];
			vector<TreeNode*>& rightSubtrees = subtreeSets[right];
			for( vector<TreeNode*>::const_iterator lit=leftSubtrees.begin(); lit!=leftSubtrees.end(); ++lit )
			{
				for( vector<TreeNode*>::const_iterator rit=rightSubtrees.begin(); rit!=rightSubtrees.end(); ++rit )
				{
					TreeNode* root = new TreeNode( left+1 );
					root->left = copySubtree( *lit, 0 );
					root->right = copySubtree( *rit, left+1 );
					result.push_back( root );
				}
			}
		}
		subtreeSets.push_back( result );
	}

	// copy a tree with an offset value
	TreeNode* copySubtree( const TreeNode* root, int offset )
	{
		if( root==NULL )
			return NULL;
		TreeNode* node = new TreeNode( root->val + offset );
		node->left = copySubtree(root->left, offset);
		node->right = copySubtree(root->right, offset);
		return node;
	}
};
