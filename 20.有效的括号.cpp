/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> temp;
        for (int i=0; i < s.size();i++){
            // 需要注意 stack 如果是empty的情况下是不可以进行top()操作的，因为会爆内存错误。
            if (temp.empty() || s[i] == '(' || s[i] == '{' || s[i] == '[') 
                temp.push(s[i]);
            else {
                if (s[i] == ')' && temp.top() == '(')
                    temp.pop();
                else if (s[i] == ']' && temp.top() == '[')
                    temp.pop();
                else if (s[i] == '}' && temp.top() == '{')
                    temp.pop();
                else return false;
            }     
        }
        if (temp.empty())
            return true;
        else return false;
    }
};
// @lc code=end

