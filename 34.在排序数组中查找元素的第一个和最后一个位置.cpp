/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = leftBound(nums, target);
        int right = rightBound(nums, target);
        return {left, right};
    }

    int leftBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        // 搜索区间为 [left, right]
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // 收缩右侧边界
            if (nums[mid] == target) right = mid - 1;
            // 搜索区间变为 [mid+1, right]
            else if (nums[mid] < target) left = mid + 1;
            // 搜索区间变为 [left, mid-1]
            else if (nums[mid] > target) right = mid - 1;
        }
        // 检查出界情况
        if (left >= nums.size() || nums[left] != target) return -1;
        return left; 
    }

    int rightBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        // 搜索区间为 [left, right]
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // 收缩左侧边界
            if (nums[mid] == target) left = mid + 1;
            // 搜索区间变为 [mid+1, right]
            else if (nums[mid] < target) left = mid + 1;
            // 搜索区间变为 [left, mid-1]
            else if (nums[mid] > target) right = mid - 1;
        }
        // 检查出界情况
        if (right < 0 || nums[right] != target) return -1;
        return right; 
    }
};
// @lc code=end

