/*
 * Problem: http://leetcode.com/onlinejudge#question_23
 */

#include <vector>
#include <algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

typedef ListNode* ListNodePtr;

// to make min heap
bool cmpListNode( const ListNodePtr& l1, const ListNodePtr& l2 )
{
	return l1->val > l2->val;
}

class Solution
{
public:
	ListNode *mergeKLists(vector<ListNode *> &lists)
	{
		for( vector<ListNode *>::iterator it=lists.begin(); it!=lists.end(); )
		{
			if( *it==NULL )
				it = lists.erase( it );
			else
				++it;
		}

		make_heap( lists.begin(), lists.end(), cmpListNode );
		ListNode *head = NULL, *tail = NULL;
		while( !lists.empty() )
		{
			if( tail==NULL )
			{
				head = tail = lists.front();
			}
			else
			{
				tail->next = lists.front();
				tail = tail->next;
			}
			pop_heap( lists.begin(), lists.end(), cmpListNode );

			ListNodePtr& back = *lists.rbegin();
			back = back->next;
			if( back==NULL )
				lists.pop_back();
			else
				make_heap( lists.begin(), lists.end(), cmpListNode );
		}
		return head;
	}
};
