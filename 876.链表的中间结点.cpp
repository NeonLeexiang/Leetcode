/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
 */

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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // 快慢指针
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            // 这里因为fast一下子跳两次，所以注意边界条件。
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;

    }
};
// @lc code=end

