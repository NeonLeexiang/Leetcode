/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
    // 预先设置一个数组用于保存相应的前缀和
    private: vector<int> preSum;
public:
    NumArray(vector<int>& nums) {
        // 新建数组时同时保存对应的前缀和，这样尽可能减少成员函数的使用时间。
        preSum = vector<int> (nums.size()+1);
        for (int i = 1; i < preSum.size(); i++) 
            preSum[i] = preSum[i-1] + nums[i-1];
    }
    
    int sumRange(int left, int right) {
        // 这样可以直接访问对象中的 private 数组进行前缀和查询
        return preSum[right+1] - preSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

