/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 还是使用双指针的思想，但是我们可以想到的是，如果是有交点，那两个链表长度部分加起来应该会相等
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while (p1 != p2) {
            if (!p1) p1 = headB;
            else p1 = p1->next;
            if (!p2) p2 = headA;
            else p2 = p2->next;
        }        
        return p1;
    }
};
// @lc code=end

