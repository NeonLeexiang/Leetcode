/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        // 诸如此类问题都可以尝试使用双指针技巧解决问题
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            // temp 作为暂存数据
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};
// @lc code=end

