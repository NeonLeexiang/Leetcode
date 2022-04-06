/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 一遍哈希表方法
        map<int, int>a;
        for (int i = 0; i < nums.size(); i++)
        {
            if (a.count(target-nums[i])) return {a[target-nums[i]], i};
            else a[nums[i]]=i;
        }
        return {};

    }
};
// @lc code=end
