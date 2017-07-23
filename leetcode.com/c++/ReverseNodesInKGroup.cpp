/*
 * Problem: http://leetcode.com/onlinejudge#question_25
 */

#ifndef NULL
#define NULL 0
#endif

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
	ListNode *reverseKGroup(ListNode *head, int k)
	{
		ListNode* headAfterReverse = tryReverseAGroup( head, k );
		// reach the end or no need to reverse(k=1)
		if( head==headAfterReverse )
			return head;

		ListNode* newTail = head;
		head = headAfterReverse;

		// newTail->[n1(nextNewTail)->...->nk(headAfterReverse)]->next
		while( newTail!=NULL )
		{
			headAfterReverse = tryReverseAGroup(newTail->next,k);
			// reach the end
			if( headAfterReverse==newTail->next )
				break;

			// move forward: newTail->[nk(headAfterReverse)->...->n1(nextNewTail)]->next
			ListNode* nextNewTail = newTail->next;
			newTail->next = headAfterReverse;
			newTail = nextNewTail;
		}

		return head;
	}
private:
	// n1->...->nk->next, return nk, where next<-n1<-..<-nk
	// k>1
	ListNode* tryReverseAGroup( ListNode *n1, int k )
	{
		ListNode* cur = n1;
		for( int i=0; i<k; ++i )
		{
			// no enough
			if( cur==NULL )
				return n1;
			cur = cur->next;
		}
		cur = n1;

		ListNode* n2 = n1->next;
		for( int i=1; i<k; ++i )
		{
			ListNode* n3 = n2->next;
			n2->next = n1;
			n1 = n2;
			n2 = n3;
		}
		// now "n1" is nk, "n2" is nk->next
		cur->next = n2; // now n1->next is previous nk->next

		return n1;
	}
};

