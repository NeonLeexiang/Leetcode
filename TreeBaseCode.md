# TreeBaseCode
---
**This is for Tree Traverse Base Code**

## Base
---
```cpp
void traverse(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    // 前序位置
    traverse(root->left);
    // 中序位置
    traverse(root->right);
    // 后序位置
}
```

层序遍历
```cpp
// 输入一棵二叉树的根节点，层序遍历这棵二叉树
void levelTraverse(TreeNode root) {
    if (root == null) return;
    Queue<TreeNode> q = new LinkedList<>();
    q.offer(root);

    // 从上到下遍历二叉树的每一层
    while (!q.isEmpty()) {
        int sz = q.size();
        // 从左到右遍历每一层的每个节点
        for (int i = 0; i < sz; i++) {
            TreeNode cur = q.poll();
            // 将下一层节点放入队列
            if (cur.left != null) {
                q.offer(cur.left);
            }
            if (cur.right != null) {
                q.offer(cur.right);
            }
        }
    }
}
```

标准 `cpp` 实现:

```cpp
void levelTraverse(TreeNode* root) {
    if (root == nullptr) return;
    queue<TreeNode> q;
    q.push(root);

    while(!q.empty()) {
        int sz = q.size()
        for (int i = 0; i < sz; i++) {
            TreeNode* cur = q.pop();
            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullprt) q.push(cur->right);
        }
    }
}
```
