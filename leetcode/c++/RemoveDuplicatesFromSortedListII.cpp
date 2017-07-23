/*
 * Problem: http://leetcode.com/onlinejudge#question_82
 */

#define NULL 0

// Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode *deleteDuplicates(ListNode *head)
	{
		ListNode *checkingPoint = head, *tail = NULL;
		head = NULL;

		while( checkingPoint!=NULL )
		{
			bool duplicate = false;
			while( checkingPoint->next!=NULL && checkingPoint->next->val==checkingPoint->val )
			{
				duplicate = true;
				checkingPoint = checkingPoint->next;
			}
			// include tail
			if( !duplicate )
			{
				if(tail==NULL)
					head = tail = checkingPoint;
				else
				{
					tail->next = checkingPoint;
					tail = tail->next;
				}
			}
			checkingPoint = checkingPoint->next;
		}
		if(tail)
			tail->next = NULL;
		return head;
	}
};
