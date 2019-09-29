#include <algorithm>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

typedef ListNode* ListNodePtr;

// to make min heap
bool cmpListNode(const ListNodePtr l1, const ListNodePtr l2) {
  if (l1 == nullptr) {
    return true;
  }
  if (l2 == nullptr) {
    return false;
  }
  return l1->val > l2->val;
}

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    make_heap(lists.begin(), lists.end(), cmpListNode);
    ListNode *head = nullptr, *tail = nullptr;
    while (!lists.empty() && lists[0] != nullptr) {
      if (tail == nullptr) {
        head = tail = lists[0];
      } else {
        tail->next = lists[0];
        tail = tail->next;
      }
      lists[0] = lists[0]->next;
      pop_heap(lists.begin(), lists.end(), cmpListNode);
      push_heap(lists.begin(), lists.end(), cmpListNode);
    }
    return head;
  }
};
