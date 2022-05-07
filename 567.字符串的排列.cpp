/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> need;
        map<char, int> window;

        for (char c: s1) need[c]++;
        
        int left = 0;
        int right = 0;

        int valid = 0;

        // // 记录最小覆盖子串的起始索引及长度
        // int start = 0;
        // int len = __INT_MAX__;

        while (right < s2.size()) {
            // c 是将移入窗口的字符
            char c = s2[right];
            // 扩大窗口
            right++;
            // 进行窗口内数据的一系列更新
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }

            // 判断左侧窗口是否要收缩
            while (right - left >= s1.size()) {
                // 在这里判断是否找到了合法的子串
                if (valid == need.size()) {
                    return true;
                }
                // d 是将移出窗口的字符
                char d = s2[left];
                // 缩小窗口
                left++;
                // 进行窗口内数据的一系列更新
                if (need.count(d)) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }
        // 如果没有找到就返回 false
        return false;
    }
};
// @lc code=end

