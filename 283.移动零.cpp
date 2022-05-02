/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] != 0) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        // 注意运行到这里其实是 fast 已经到末尾了，但是 slow 还没有到
        while (slow < nums.size()) {
            nums[slow] = 0;
            slow++;
        }
    }
};
// @lc code=end

