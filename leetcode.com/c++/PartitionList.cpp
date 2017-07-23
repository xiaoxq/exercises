/*
 * Problem: http://leetcode.com/onlinejudge#question_86
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
	ListNode *partition(ListNode *head, int x)
	{
		ListNode *smallerHead = NULL, *smallerTail = NULL;
		ListNode *greaterHead = NULL, *greaterTail = NULL;
		while( head!=NULL )
		{
			// goto smaller list
			if( head->val < x )
			{
				if( smallerTail==NULL )
					smallerHead = smallerTail = head;
				else
				{
					smallerTail->next = head;
					smallerTail = smallerTail->next;
				}
			}
			// goto greater list
			else
			{
				if( greaterTail==NULL )
					greaterHead = greaterTail = head;
				else
				{
					greaterTail->next = head;
					greaterTail = greaterTail->next;
				}
			}
			head = head->next;
		}
		if( smallerHead==NULL )
			return greaterHead;

		smallerTail->next = greaterHead;
		if( greaterTail )
			greaterTail->next = NULL;
		return smallerHead;
	}
};
