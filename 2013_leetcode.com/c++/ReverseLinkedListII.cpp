/*
 * Problem: http://leetcode.com/onlinejudge#question_92
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
	ListNode *reverseBetween(ListNode *head, int m, int n)
	{
		if( m==1 )
			return reverseKLinks( head, n-1 );

		ListNode* preHeadBeforeReverse = head;
		for( int i=2; i<m; ++i )
			preHeadBeforeReverse = preHeadBeforeReverse->next;
		ListNode* headBeforeReverse = preHeadBeforeReverse->next;
		preHeadBeforeReverse->next = reverseKLinks( headBeforeReverse, n-m );
		return head;
	}
private:
	ListNode* reverseKLinks( ListNode* head, int k )
	{
		if( k==0 )
			return head;

		ListNode* pre = NULL;
		ListNode* cur = head;
		for( int i=0; i<=k; ++i )
		{
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		head->next = cur;
		return pre;
	}
};
