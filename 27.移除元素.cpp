/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        int fast = 0;
        if (!nums.size()) return 0;
        while (fast < nums.size()) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
                // fast++;  // 注意语言逻辑，if 运行完 fast 还会做一次++
            }
            fast++;
        }
        // 注意不是 slow + 1，因为 slow会++，所以 slow 对应的位置是被填上的位置。
        return slow;
    }
};
// @lc code=end

