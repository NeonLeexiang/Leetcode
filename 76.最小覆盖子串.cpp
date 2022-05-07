/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> need;
        map<char, int> window;

        for (char c: t) need[c]++;
        
        int left = 0;
        int right = 0;

        int valid = 0;

        // 记录最小覆盖子串的起始索引及长度
        int start = 0;
        int len = __INT_MAX__;

        while (right < s.size()) {
            // c 是将移入窗口的字符
            char c = s[right];
            // 扩大窗口
            right++;
            // 进行窗口内数据的一系列更新
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }

            // 判断左侧窗口是否要收缩
            while (valid == need.size()) {
                // 在这里更新最小覆盖子串
                if (right - left < len) {
                    // 记录并判断是否最小覆盖子串
                    start = left;
                    len = right - left;
                }
                // d 是将移出窗口的字符
                char d = s[left];
                // 缩小窗口
                left++;
                // 进行窗口内数据的一系列更新
                if (need.count(d)) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }
        // 返回最小覆盖子串
        return len == __INT_MAX__ ? "" : s.substr(start, len);
        
    }
};
// @lc code=end

