/*
 * @lc app=leetcode.cn id=203 lang=cpp
 * @lcpr version=30204
 *
 * [203] 移除链表元素
 */

#ifdef _WIN32
#include "DataStructure.h"
#endif
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  ListNode* removeElements(ListNode* head, int val)
  {
    ListNode* dummyHead = new ListNode(0, head);

    ListNode* current = dummyHead;
    while (current != nullptr) {
      ListNode* tmp = current->next;
      if (tmp != nullptr && tmp->val == val) {
        current->next = tmp->next;
        delete tmp;
        continue;
      }
      current = current->next;
    }

    head = dummyHead->next;
    delete dummyHead;
    return head;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,6,3,4,5,6]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n1\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7]\n7\n
// @lcpr case=end

 */
