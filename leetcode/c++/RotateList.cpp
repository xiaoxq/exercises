/*
 * Problem: http://leetcode.com/onlinejudge#question_61
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
	ListNode *rotateRight(ListNode *head, int k)
	{
		if( head==NULL )
			return NULL;

		int len = 1;
		ListNode *tail = head;
		while( tail->next!=NULL )
		{
			++len;
			tail = tail->next;
		}
		tail->next = head;

		len = len - (k%len);
		while( --len )
			head = head->next;

		tail = head;
		head = head->next;
		tail->next = NULL;
		return head;
	}
};
