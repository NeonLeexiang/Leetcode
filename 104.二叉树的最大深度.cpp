/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 记录最大深度
    int res = 0;
    // 记录遍历到节点的深度
    int depth = 0;
    int maxDepth(TreeNode* root) {
        traverse(root);
        return res;
    }

    void traverse(TreeNode* root) {
        if (root==nullptr) return;

        // 前序位置
        depth++;
        if (root->left == nullptr && root->right == nullptr) {
            // 到达叶子结点，更新最大深度
            res = max(res, depth);
        }
        traverse(root->left);
        traverse(root->right);
        // 后序位置重制 depth
        depth--;
    }

};
// @lc code=end

