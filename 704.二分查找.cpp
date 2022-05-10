/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while (left <= right) {
            // 计算 mid 时需要防止溢出，
            // 代码中 left + (right - left) / 2 就和 (left + right) / 2 的结果相同，
            // 但是有效防止了 left 和 right 太大，直接相加导致溢出的情况。
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
        }
        return -1;

    }
};
// @lc code=end

