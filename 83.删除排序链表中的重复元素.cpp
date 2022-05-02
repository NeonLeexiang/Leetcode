/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;     // 注意特殊的边界

        // 还是利用快慢指针的技巧
        ListNode* slow = head;
        ListNode* fast = head;
        
        // 注意 fast !fast 的语法区别
        while (fast) {
            if (fast->val != slow->val) {
                slow->next = fast;
                slow = slow->next;
            }
            fast = fast->next;
        }
        // 需要注意的是这个是链表，所以要注意最后面要断开与重复元素的连接
        slow->next = nullptr;
        return head;
    }
};
// @lc code=end

