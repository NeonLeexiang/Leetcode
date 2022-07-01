/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    TreeNode* invertTree(TreeNode* root) {
        traverse(root);
        return root;
    }
    void traverse(TreeNode* root) {
        if (root == nullptr) return;

        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        traverse(root->left);
        traverse(root->right);

    }
};

/*
solution 2:

// 定义：将以 root 为根的这棵二叉树翻转，返回翻转后的二叉树的根节点
TreeNode invertTree(TreeNode root) {
    if (root == null) {
        return null;
    }
    // 利用函数定义，先翻转左右子树
    TreeNode left = invertTree(root.left);
    TreeNode right = invertTree(root.right);

    // 然后交换左右子节点
    root.left = right;
    root.right = left;

    // 和定义逻辑自恰：以 root 为根的这棵二叉树已经被翻转，返回 root
    return root;
}

*/

// @lc code=end

