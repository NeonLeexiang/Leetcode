# Leetcode 刷题日记

刷题日记基于 🔗[`labuladong 的算法小抄`](https://github.com/labuladong/fucking-algorithm)  
  
<br/>
<br/>
<br/>

👇 以下是 `labuladong fucking-algorithm` 介绍页面  

---

# labuladong 的算法小抄

<p align='center'>
<a href="https://labuladong.github.io/algo" target="_blank"><img alt="Website" src="https://img.shields.io/website?label=%E5%9C%A8%E7%BA%BF%E7%94%B5%E5%AD%90%E4%B9%A6&style=flat-square&down_color=blue&down_message=%E7%82%B9%E8%BF%99%E9%87%8C&up_color=blue&up_message=%E7%82%B9%E8%BF%99%E9%87%8C&url=https%3A%2F%2Flabuladong.gitee.io%2Falgo&logo=Gitea"></a>
<a href="https://github.com/labuladong/fucking-algorithm" target="_blank"><img alt="GitHub" src="https://img.shields.io/github/stars/labuladong/fucking-algorithm?label=Stars&style=flat-square&logo=GitHub"></a>
</p>

<p align='center'>
<a href="https://www.github.com/labuladong" target="_blank"><img src="https://img.shields.io/badge/作者-@labuladong-000000.svg?style=flat-square&logo=GitHub"></a>
<a href="https://www.zhihu.com/people/labuladong" target="_blank"><img src="https://img.shields.io/badge/%E7%9F%A5%E4%B9%8E-@labuladong-000000.svg?style=flat-square&logo=Zhihu"></a>
<a href="https://i.loli.net/2020/10/10/MhRTyUKfXZOlQYN.jpg" target="_blank"><img src="https://img.shields.io/badge/公众号-@labuladong-000000.svg?style=flat-square&logo=WeChat"></a>
<a href="https://space.bilibili.com/14089380" target="_blank"><img src="https://img.shields.io/badge/B站-@labuladong-000000.svg?style=flat-square&logo=Bilibili"></a>
</p>

---
<br/>
<br/>
<br/>


---


## Log

| date | file | Log|
| ---- | ---- | ----|
| 2022-04-25 | [`BaseCode.md`](./BaseCode.md) | 添加 `BaseCode.md` 用于记录一些基础的代码 |
| 2022-04-25 | `...` | 完成递归链表章节题目 |
| 2022-04-25 | [`README.md`](./README.md) | 完善 `README` 文档并添加算法小抄介绍以及🔗链接 |
| 2022-04-25 | `...` | 结束 手把手刷链表算法 小节 |
| 2022-05-01 | `...` | 经过短暂的人生迷茫期，重新尝试做一个小镇做题家进阶卷王之路，继续开始刷题。并完成了差分数组专题 |
| 2022-05-06 | `...` | 滑动窗口法 |
| 2022-05-09 | `...` | 结束滑动窗口法 |
| 2022-05-20 | `...` | 开启二叉树章节 |
| 2022-05-22 | [`TreeTraverse.md`](./TreeTraverse.md) | 用于记录二叉树章节内容 |








---

## 第一章: 双指针技巧秒杀七道链表题目
  
  * 「虚拟头结点」技巧，也就是 dummy 节点。

    ```
        ListNode* dummy = new ListNode(-1)
    ```
> 使用了虚拟头结点的技巧，也是为了防止出现空指针的情况，比如说链表总共有 5 个节点，题目就让你删除倒数第 5 个节点，也就是第一个节点，那按照算法逻辑，应该首先找到倒数第 6 个节点。但第一个节点前面已经没有节点了，这就会出错。但有了我们虚拟节点 dummy 的存在，就避免了这个问题，能够对这种情况进行正确的删除。


  *  学会使用优先级队列，会对于一些排序问题省事。同时需要了解优先级队列的时间复杂度空间复杂度问题。  
> `优先队列 pq 中的元素个数最多是 k，所以一次 poll 或者 add 方法的时间复杂度是 O(logk)；所有的链表节点都会被加入和弹出 pq，所以算法整体的时间复杂度是 O(Nlogk)，其中 k 是链表的条数，N 是这些链表的节点总数。`

  * 分治思想的学习。
  * 快慢指针

> 每当慢指针 slow 前进一步，快指针 fast 就前进两步，这样，当 fast 走到链表末尾时，slow 就指向了链表中点。同理可以实现很多类似的问题。  

> 需要注意的是，如果链表长度为偶数，也就是说中点有两个的时候，我们这个解法返回的节点是靠后的那个节点。

> 另外，这段代码稍加修改就可以直接用到判断链表成环的算法题上。判断链表是否包含环. 判断链表是否包含环属于经典问题了，解决方案也是用快慢指针：每当慢指针 slow 前进一步，快指针 fast 就前进两步。如果 fast 最终遇到空指针，说明链表中没有环；如果 fast 最终和 slow 相遇，那肯定是 fast 超过了 slow 一圈，说明链表中含有环。

> 如何判断链表中环的起点，可以利用一个思维：当快慢指针相遇时，让其中任一个指针指向头节点，然后让它俩以相同速度前进，再次相遇时所在的节点位置就是环开始的位置。
  
* 递归解决反转列表。
> 1. 递归函数要有 base case 。
> 2. 别忘了解决边界问题。

**链表是一种兼具递归和迭代性质的数据结构**
> 必须有一个思维去看待递归问题，首先必须看问题是否能分解为子问题，然后再去找 base case. 可以从边界的角度考虑 base case。

* 数组问题-合理使用前缀和有时候使用前缀和可以减少成员函数的运算开销。
> 比方说，你们班上有若干同学，每个同学有一个期末考试的成绩（满分 100 分），那么请你实现一个 API，输入任意一个分数段，返回有多少同学的成绩在这个分数段内。

> 那么，你可以先通过计数排序的方式计算每个分数具体有多少个同学，然后利用前缀和技巧来实现分数段查询的 API：
 ```cpp
 int[] scores; // 存储着所有同学的分数
// 试卷满分 100 分
int[] count = new int[100 + 1]
// 记录每个分数有几个同学
for (int score : scores)
    count[score]++
// 构造前缀和
for (int i = 1; i < count.length; i++)
    count[i] = count[i] + count[i-1];
// 利用 count 这个前缀和数组进行分数段查询
```

**有时候也要合理利用「空间换时间」**  

**有时候也需要学会使用 HashMap 优化算法时间** 

* 学会使用差分数组技巧解决一系列的 IO 比较大的算法题目
> 对于一些 IO 比较大的问题，比如比较多索引修改操作的项目，我们考虑牺牲部分空间去换取高效的增删改查操作的时间效率。差分数组就是一个非常好的小技巧去解决类似的问题。

* 双指针技巧秒杀七道数组题目
> 从某种层面上来看数组很多时候也有着链表的特性，只不过数组可以直接索引。  
> 链表的双指针技巧同样也可以用在数组上面，比如快慢指针技巧，可以派生成快慢索引去进行一些增删改查操作。

* 滑动窗口算法
```cpp
int left = 0, right = 0;

while (right < s.size()) {
    // 增大窗口
    window.add(s[right]);
    right++;
    
    while (window needs shrink) {
        // 缩小窗口
        window.remove(s[left]);
        left++;
    }
}
```
<br/>
<br/>
滑动窗口算法的思路是这样：  

1、我们在字符串 S 中使用双指针中的左右指针技巧，初始化 left = right = 0，把索引左闭右开区间 [left, right) 称为一个「窗口」。

> PS：理论上你可以设计两端都开或者两端都闭的区间，但设计为左闭右开区间是最方便处理的。因为这样初始化 left = right = 0 时区间 [0, 0) 中没有元素，但只要让 right 向右移动（扩大）一位，区间 [0, 1) 就包含一个元素 0 了。如果你设置为两端都开的区间，那么让 right 向右移动一位后开区间 (0, 1) 仍然没有元素；如果你设置为两端都闭的区间，那么初始区间 [0, 0] 就包含了一个元素。这两种情况都会给边界处理带来不必要的麻烦。

2、我们先不断地增加 right 指针扩大窗口 [left, right)，直到窗口中的字符串符合要求（包含了 T 中的所有字符）。

3、此时，我们停止增加 right，转而不断增加 left 指针缩小窗口 [left, right)，直到窗口中的字符串不再符合要求（不包含 T 中的所有字符了）。同时，每次增加 left，我们都要更新一轮结果。

4、重复第 2 和第 3 步，直到 right 到达字符串 S 的尽头。

这个思路其实也不难，第 2 步相当于在寻找一个「可行解」，然后第 3 步在优化这个「可行解」，最终找到最优解，也就是最短的覆盖子串。左右指针轮流前进，窗口大小增增减减，窗口不断向右滑动，这就是「滑动窗口」这个名字的来历。



* 二维数组的花式遍历技巧
> 这里建议配合原博文 gif 图食用更有效。包括顺时针旋转，逆时针旋转，都涉及比较巧妙的思维。
  
* 二分查找框架
> 详细可以查看 [BaseCode.md](./BaseCode.md)中的框架  

> 分析二分查找的一个技巧是：不要出现 else，而是把所有情况用 else if 写清楚，这样可以清楚地展现所有细节。  

> 计算 mid 时需要防止溢出，代码中 left + (right - left) / 2 就和 (left + right) / 2 的结果相同，但是有效防止了 left 和 right 太大，直接相加导致溢出的情况。

* 二分搜索的套路框架
```cpp
// 函数 f 是关于自变量 x 的单调函数
int f(int x) {
    // ...
}

// 主函数，在 f(x) == target 的约束下求 x 的最值
int solution(int[] nums, int target) {
    if (nums.length == 0) return -1;
    // 问自己：自变量 x 的最小值是多少？
    int left = ...;
    // 问自己：自变量 x 的最大值是多少？
    int right = ... + 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (f(mid) == target) {
            // 问自己：题目是求左边界还是右边界？
            // ...
        } else if (f(mid) < target) {
            // 问自己：怎么让 f(x) 大一点？
            // ...
        } else if (f(mid) > target) {
            // 问自己：怎么让 f(x) 小一点？
            // ...
        }
    }
    return left;
}
```

* 优先队列需要专门一个章节去进行了解

### 手把手刷二叉树算法
> 快速排序就是个二叉树的前序遍历，归并排序就是个二叉树的后序遍历

快速排序算法
```cpp
void sort(int[] nums, int lo, int hi) {
    /****** 前序遍历位置 ******/
    // 通过交换元素构建分界点 p
    int p = partition(nums, lo, hi);
    /************************/

    sort(nums, lo, p - 1);
    sort(nums, p + 1, hi);
}
```

归并排序算法
```cpp
// 定义：排序 nums[lo..hi]
void sort(int[] nums, int lo, int hi) {
    int mid = (lo + hi) / 2;
    // 排序 nums[lo..mid]
    sort(nums, lo, mid);
    // 排序 nums[mid+1..hi]
    sort(nums, mid + 1, hi);

    /****** 后序位置 ******/
    // 合并 nums[lo..mid] 和 nums[mid+1..hi]
    merge(nums, lo, mid, hi);
    /*********************/
}
```


<br/>


前中后序是遍历二叉树过程中处理每一个节点的三个特殊时间点，绝不仅仅是三个顺序不同的 List：

前序位置的代码在刚刚进入一个二叉树节点的时候执行；

后序位置的代码在将要离开一个二叉树节点的时候执行；

中序位置的代码在一个二叉树节点左子树都遍历完，即将开始遍历右子树的时候执行。

你注意本文的用词，我一直说前中后序「位置」，就是要和大家常说的前中后序「遍历」有所区别：你可以在前序位置写代码往一个 List 里面塞元素，那最后得到的就是前序遍历结果；但并不是说你就不可以写更复杂的代码做更复杂的事。


![image](https://labuladong.gitee.io/algo/images/二叉树收官/2.jpeg)

