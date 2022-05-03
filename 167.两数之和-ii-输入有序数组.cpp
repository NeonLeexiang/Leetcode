/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int head = 0;
        int tail = numbers.size()-1;
        while (head != tail) {
            if (numbers[head] + numbers[tail] == target)
                return {head+1, tail+1};
            else if (numbers[head] + numbers[tail] < target)
                head++;
            else tail--;
        }
        // 有时候要养成一个习惯
        // c++的溢出用 -1
        return {-1, -1};
    }
};
// @lc code=end

