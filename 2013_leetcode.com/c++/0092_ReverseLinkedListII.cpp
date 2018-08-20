#include <memory>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (m == n) {
      return head;
    }

    unique_ptr<ListNode> pre_head(new ListNode(0));
    pre_head->next = head;

    // Find pre_change of pre_change->NodeM->...->NodeN->post_change->...
    ListNode* pre_change = pre_head.get();
    for (int i = 1; i < m; ++i) {
      pre_change = pre_change->next;
    }
    // Get pre_change->NodeM<-...<-NodeN(=node), post_change(=next)->...
    ListNode* node = pre_change->next;
    ListNode* next = node->next;
    for (int i = m; i < n; ++i) {
      ListNode* next_next = next->next;
      next->next = node;
      node = next;
      next = next_next;
    }
    // Connect sides.
    pre_change->next->next = next;
    pre_change->next = node;

    return pre_head->next;
  }
};
