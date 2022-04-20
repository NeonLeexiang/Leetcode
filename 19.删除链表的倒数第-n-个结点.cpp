/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* findFromEnd(ListNode* head, int k) {
        ListNode* p1 = head;
        for (int i = 0; i < k; i++)
            p1 = p1->next;
        
        ListNode* p2 = head;

        while (p1) {
            p2 = p2->next;
            p1 = p1->next;
        }
        return p2;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // trick: 新建一个头节点，返回 dummy->next 即可
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        // use findFromEnd 去找到倒数第K个
        ListNode* delete_node = findFromEnd(dummy, n+1);    // 需要注意dummy有个多余的节点。

        delete_node->next = delete_node->next->next;
        return dummy->next;

    }
};
// @lc code=end

