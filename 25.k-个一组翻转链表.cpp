/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverse(ListNode* a, ListNode* b) {
        // 注意这里是循环遍历，并非递归的子问题。也可以理解为递归的子问题的一部分。
        ListNode* pre = nullptr;
        ListNode* cur = a;
        ListNode* next_p = a;
        // 注意 while 的终止条件
        while (cur != b) {
            next_p = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next_p;
        }
        return pre;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;
        ListNode* a = head;
        ListNode* b = head;
        // 因为这个是链表，所以要找到区间界限 b 的节点，所以进行遍历
        // 同时对应的这个也可以作为 base case
        for (int i = 0; i < k; i++) {
            if (!b) return head;    // 即不需要反转
            b = b->next;
        }
        ListNode* new_head = reverse(a, b);  //子问题，反转 a 和 b 之间的列表
        a->next = reverseKGroup(b, k);
        return new_head;
    }
};
// @lc code=end

