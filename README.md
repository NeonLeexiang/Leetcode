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
