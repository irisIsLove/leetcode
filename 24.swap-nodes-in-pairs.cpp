/*
 * @lc app=leetcode.cn id=24 lang=cpp
 * @lcpr version=30204
 *
 * [24] 两两交换链表中的节点
 */

// @lcpr-template-start
#ifdef _WIN32
#include "DataStructure.h"
#endif
// @lcpr-template-end
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
  ListNode* swapPairs(ListNode* head)
  {
    ListNode* dummyHead = new ListNode(0, head);
    ListNode* current = dummyHead;
    while (current->next != nullptr && current->next->next != nullptr) {
      ListNode* temp1 = current->next;
      ListNode* temp2 = current->next->next->next;

      current->next = temp1->next;
      current->next->next = temp1;
      temp1->next = temp2;
      current = current->next->next;
    }

    head = dummyHead->next;
    delete dummyHead;
    return head;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
