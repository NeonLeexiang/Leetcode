/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */

// @lc code=start
class Solution {
    private: vector<int> preSum;
    // private: Random rand = Random();
    private: 
        // int leftBound(vector<int>& nums, int target) {
        //     int left = 0;
        //     int right = nums.size() - 1;
        //     // 搜索区间为 [left, right]
        //     while (left <= right) {
        //         int mid = left + (right - left) / 2;
        //         // 收缩右侧边界
        //         if (nums[mid] == target) right = mid - 1;
        //         // 搜索区间变为 [mid+1, right]
        //         else if (nums[mid] < target) left = mid + 1;
        //         // 搜索区间变为 [left, mid-1]
        //         else if (nums[mid] > target) right = mid - 1;
        //     }
        //     // 检查出界情况
        //     if (left >= nums.size() || nums[left] != target) return -1;
        //     return left; 
        // }
        int left_bound(vector<int>& nums, int target) {
            if (nums.size()==0) return -1;
            int left = 0;
            int right = nums.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target) right = mid;
                else if (nums[mid] < target) left = mid + 1;
                else if (nums[mid] > target) right = mid;
            }
            return left;
        }

public:
    Solution(vector<int>& w) {
        int n = w.size();
        // 构建前缀和数组，偏移一位留给 preSum[0]
        preSum = vector<int> (n+1);
        preSum[0] = 0;
        // preSum[i] = sum(w[0,...i-1])
        for (int i = 1; i <= n; i++) {
            preSum[i] = preSum[i-1] + w[i-1];
        }
    }

    int pickIndex() {
        int n = preSum.size();
        // 在区间 [1, preSum[n-1]] 中随机选择一个数字
        int target = rand() % preSum[n-1] + 1;
        // for (int i=0; i < n; i++)
        //     cout<<preSum[i]<<'\t';
        // cout<<'\n'<<target<<endl;
        // 获取 target 在前缀和数组 preSum 中的索引
        // 别忘了前缀和数组 preSum 和原始数组 w 有一位索引偏移
        return left_bound(preSum, target) - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

