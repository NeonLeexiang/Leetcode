/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size())
            return 0;
        int slow = 0;
        int fast = 0;

        while (fast < nums.size()) {
            if (nums[fast] != nums[slow]) {
                slow++;     // 先让 slow 先移动到下一个位置作为修改的位置。
                nums[slow] = nums[fast];
            }
            fast++;     // 移动快指针
        }
        // 注意数组索引从0开始
        return slow+1;
    }
};
// @lc code=end

