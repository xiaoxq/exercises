#include <memory>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    unique_ptr<ListNode> pre_head(new ListNode(0));
    pre_head->next = head;

    ListNode* pre_swap = pre_head.get();
    while (pre_swap && pre_swap->next && pre_swap->next->next) {
      ListNode* n1 = pre_swap->next;
      ListNode* n2 = pre_swap->next->next;
      ListNode* n3 = pre_swap->next->next->next;
      pre_swap->next = n2;
      n2->next = n1;
      n1->next = n3;
      pre_swap = n1;
    }
    return pre_head->next;
  }
};
