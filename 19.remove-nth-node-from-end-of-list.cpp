/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=30204
 *
 * [19] 删除链表的倒数第 N 个结点
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
  ListNode* removeNthFromEnd(ListNode* head, int n)
  {
    ListNode* dummyHead = new ListNode(0, head);
    ListNode* cur = dummyHead;
    for (int i = 0; i < n; ++i) {
      cur = cur->next;
    }
    cur = cur->next;

    ListNode* preTarget = dummyHead;
    for (; cur != nullptr;) {
      preTarget = preTarget->next;
      cur = cur->next;
    }

    ListNode* tmp = preTarget->next;
    preTarget->next = tmp->next;
    delete tmp;

    head = dummyHead->next;
    delete dummyHead;
    return head;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */
