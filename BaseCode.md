# Base Code
---
这个文件是用来记录一些常用的模版代码，一些基本的子问题的代码。  


## 第一章
### 反转链表等子问题代码

反转指定区间的代码：

```cpp
/** 反转区间 [a, b) 的元素，注意是左闭右开 */
ListNode reverse(ListNode a, ListNode b) {
    ListNode pre, cur, nxt;
    pre = null; cur = a; nxt = a;
    // while 终止的条件改一下就行了
    while (cur != b) {
        nxt = cur.next;
        cur.next = pre;
        pre = cur;
        cur = nxt;
    }
    // 返回反转后的头结点
    return pre;
}
```

反转以 a 为头节点的链表代码：

```cpp
// 反转以 a 为头结点的链表
ListNode reverse(ListNode a) {
    ListNode pre, cur, nxt;
    pre = null; cur = a; nxt = a;
    while (cur != null) {
        nxt = cur.next;
        // 逐个结点反转
        cur.next = pre;
        // 更新指针位置
        pre = cur;
        cur = nxt;
    }
    // 返回反转后的头结点
    return pre;
}
```

对应二叉树的遍历基础代码，链表也有对应的前序遍历和后序遍历  

二叉树的遍历：
```cpp
void traverse(TreeNode root) {
    // 前序遍历代码
    traverse(root.left);
    // 中序遍历代码
    traverse(root.right);
    // 后序遍历代码
}
```
  
链表的递归遍历 
```cpp
void traverse(ListNode head) {
    // 前序遍历代码
    traverse(head.next);
    // 后序遍历代码
}
```

差分数组技巧
```cpp
class Difference {
    // 差分数组
    private: vector<int> diff;
    public:
    Difference(vector<int>& nums) {
        // assert nums.size() > 0;
        diff = vector<int>(nums.size());
        diff[0] = nums[0];
        for (int i=1; i < nums.size(); i++)
            diff[i] = nums[i] - nums[i-1];
    }
    void increment(int i, int j, int val) {
        diff[i] += val;
        if (j+1 < diff.size())
            diff[j+1] -= val;
    }
    vector<int> result() {
        vector<int> res(diff.size());
        res[0] = diff[0];
        for (int i = 1; i < diff.size(); i++)
            res[i] = res[i-1] + diff[i];
        return res; 
    }
};
```

滑动窗口算法核心框架
```cpp
// 滑动窗口算法框架 
// labuladong 写法
void slidingWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c: t) need[c]++;

    int left = 0, right = 0;
    int valid = 0;

    while (right < s.size()) {
        char c = s[right];
        // 右移（增大）窗口
        right++;
        // 进行窗口内数据的一系列更新

        while (window needs shrink) {
            char d = s[left];
            // 左移（缩小）窗口
            left++;
            // 进行窗口内数据的一系列更新
        }
    }
}
```

经典数据结构算法-> 二分查找
```cpp
int binarySearch(int[] nums, int target) {
    // 一左一右两个指针相向而行
    int left =0, right = nums.length - 1;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid -1;
    }
    return -1;
}
```

<br/>
滑动窗口法  

```cpp
/* 滑动窗口算法框架 */
void slidingWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;
    
    int left = 0, right = 0;
    int valid = 0; 
    while (right < s.size()) {
        // c 是将移入窗口的字符
        char c = s[right];
        // 增大窗口
        right++;
        // 进行窗口内数据的一系列更新
        ...

        /*** debug 输出的位置 ***/
        printf("window: [%d, %d)\n", left, right);
        /********************/
        
        // 判断左侧窗口是否要收缩
        while (window needs shrink) {
            // d 是将移出窗口的字符
            char d = s[left];
            // 缩小窗口
            left++;
            // 进行窗口内数据的一系列更新
            ...
        }
    }
}
```
