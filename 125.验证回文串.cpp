/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int len = s.length();
//         int i = 0;
//         int j = len - 1;
//         while (i < j) {
//             if (!(('A'<=s[i] && s[i]<='Z') || ('a'<=s[i] && s[i]<='z') || ('0'<=s[i] && s[i]<='9'))) {
//                 i++;
//                 continue;
//             }
//             if (!(('A'<=s[j] && s[j]<='Z') || ('a'<=s[j] && s[j]<='z')|| ('0'<=s[j] && s[j]<='9'))) {
//                 j--;
//                 continue;
//             }
//             int asc_i = int(s[i]);
//             int asc_j = int(s[j]);

//             if (asc_i - int('a') >= 0)
//                 asc_i = int('A') + asc_i - int('a');
//             if (asc_j - int('a') >= 0)
//                 asc_j = int('A') + asc_j - int('a');
            
//             cout<<asc_i<<endl;
//             cout<<asc_j<<endl;

//             if (asc_i != asc_j)
//                 return false;
//             i++; j--;
//         }
//         return true;

//     }
// };

// 接下来是标准答案，标准答案的写法具有更多的字符串内置方法
// 有时候也需要掌握一些内置函数可以更加方便快捷地解决很多问题
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                ++left;
            }
            while (left < right && !isalnum(s[right])) {
                --right;
            }
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                ++left;
                --right;
            }
        }
        return true;
    }
};
// @lc code=end

