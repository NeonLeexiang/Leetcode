/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 */

// @lc code=start
class Solution {
public:
    string smallestSubsequence(string s) {
        // 新建栈
        stack<char> stk;
        // 用于计算对应字母数量
        // 因为是 ASCII 码形式，所以对应大小 256 够用了
        vector<int> count(256);

        // 先遍历一遍统计对应 count
        for (int i=0; i < s.size(); i++) {
            count[int(s[i])]++;
        }

        // 用于记录栈内是否有对应元素
        vector<bool> in_stack(256);

        for (char c: s) {
            // 每遍历过一个字符，都将对应的计数减一
            count[int(c)]--;

            if (in_stack[int(c)]) continue;

            while (!stk.empty() && int(stk.top()) > int(c)) {
                // 若之后不存在栈顶元素，则停止 pop
                if (count[int(stk.top())] == 0) break;

                // 若之后还有，则可以 pop
                int temp = int(stk.top());
                stk.pop();
                in_stack[temp] = false;
            }

            stk.push(c);
            in_stack[int(c)] = true;
        }

        string res;

        while(!stk.empty()) {
            char temp_char = stk.top();
            res.push_back(temp_char);
            stk.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
// @lc code=end

