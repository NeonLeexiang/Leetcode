/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // pay attention to the initial
        ListNode* lst = nullptr;
        ListNode* p = nullptr;
        
        int res = 0;
        int carry = 0;
        int n1 = 0;
        int n2 = 0;

        while (l1 || l2) {
            // just use l1 l2, since they are parameter
            n1 = l1 ? l1->val: 0;
            n2 = l2 ? l2->val: 0;
            res = n1 + n2 + carry;
            if (!lst) {
                // need to initialize the head node
                lst = p = new ListNode(res % 10);
            } else {
                p->next = new ListNode(res % 10);
                p = p->next;
            }
            carry = res / 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry > 0) p->next = new ListNode(carry);
        return lst;
    }
};
// @lc code=end

