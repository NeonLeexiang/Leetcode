/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
// class Solution {
// public:
//     // 完了，真的好菜，一题递归都做不出来，甚至基本的循环也写不出来。
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         if (l1 == nullptr) {
//             return l2;
//         } else if (l2 == nullptr) {
//             return l1;
//         } else if (l1->val < l2->val) {
//             l1->next = mergeTwoLists(l1->next, l2);
//             return l1;
//         } else {
//             l2->next = mergeTwoLists(l1, l2->next);
//             return l2;
//         }
//     }
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* preHead = new ListNode(-1);
        ListNode* pre = preHead;
        while (list1 && list2){
            if (list1->val < list2->val) {
                pre->next = list1;
                list1 = list1->next;
            }
            else {
                pre->next = list2;
                list2 = list2->next;
            }
            pre = pre->next;
        }
        pre->next = list1 == nullptr ? list2 : list1;
        return preHead->next;
    }
};



// @lc code=end

