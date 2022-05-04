/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string palindrome(string s, int l, int r) {
        while (l>=0 && r<=s.length() && s[l] == s[r]) {
            l--; r++;
        }
        // cout<<s.substr(l+1, r-l-1)<<endl;
        // 注意 c++ 和 c之间的一些内置STL函数库的不同标准
        return s.substr(l+1, r-l-1);
    }

    string longestPalindrome(string s) {
        string res="";
        for (int i = 0; i < s.length(); i++) {
            string s1 = palindrome(s, i, i);
            string s2 = palindrome(s, i, i+1);
            // 注意这里的判断条件，长度相等的时候不能被后续子串所替代掉
            res = res.length() >= s1.length() ? res: s1;
            res = res.length() >= s2.length() ? res: s2;
        }
        return res;
    }
};
// @lc code=end

