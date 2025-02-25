/*
 * @lc app=leetcode.cn id=142 lang=cpp
 * @lcpr version=30204
 *
 * [142] 环形链表 II
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
  ListNode* detectCycle(ListNode* head)
  {
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        ListNode* index1 = slow;
        ListNode* index2 = head;
        while (index1 != index2) {
          index1 = index1->next;
          index2 = index2->next;
        }
        return index2;
      }
    }

    return nullptr;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,0,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1]\n-1\n
// @lcpr case=end

 */
