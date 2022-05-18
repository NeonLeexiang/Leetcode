/*
 * @lc app=leetcode.cn id=710 lang=cpp
 *
 * [710] 黑名单中的随机数
 */

// @lc code=start
class Solution {
public:
    // 考虑将 blacklist 数据放至数组末尾，这样只需要索引前sz个即可
    int sz; // 将非 blacklist 数据放至前 sz 个

    // 如果前 sz 个有 blacklist 进行重定位
    unordered_map<int, int> mapping;
    
    Solution(int n, vector<int>& blacklist) {
        sz = n - blacklist.size();

        for (int b : blacklist) {
            mapping[b] = 666;
        }

        int last = n - 1;
        // 在[0, sz] 中的 blacklist 数据建立索引
        for (int b : blacklist) {
            // 如果 b 已经在区间 [sz, n)
            // 可以直接忽略
            if (b >= sz) {
                continue;
            }
            while (mapping.count(last)) {
                last--;
            }
            mapping[b] = last;
            last--;
        }

    }
    
    int pick() {
        // 随机选取一个索引
        int index = rand() % sz;
        // 这个索引命中了黑名单，
        // 需要被映射到其他位置
        if (mapping.count(index)) {
            return mapping[index];
        }
        // 若没命中黑名单，则直接返回
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end

