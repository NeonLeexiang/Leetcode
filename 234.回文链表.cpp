/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    ListNode* left = nullptr;


    bool traverse(ListNode* right) {
        if (!right) return true;
        bool res = traverse(right->next);
        // 后序遍历代码
        res = res && (right->val == left->val);
        left = left->next;
        return res;
    }


    bool isPalindrome(ListNode* head) {
        left = head;
        return traverse(head);
    }
};
// @lc code=end

