/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
class Difference {
    private: vector<int> diff;
    
    public:

    Difference(vector<int>& nums) {
        diff = vector<int> (nums.size());

        diff[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            diff[i] = nums[i] - nums[i - 1];
    }
    void increment(int i, int j, int val) {
        diff[i] += val;
        if (j + 1 < diff.size())
            diff[j+1] -= val;
    }
    vector<int> result() {
        vector<int> res(diff.size());
        res[0] = diff[0];
        for (int i = 1; i < diff.size(); i++)
            res[i] = res[i-1] + diff[i];
        return res;
    }
};



class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> nums(1001);
        Difference df(nums);
        for (vector<int> trip: trips) {
            int val = trip[0];
            int i = trip[1];
            // 这里需要注意乘客在 j 站之前就下车了，也就是区间是 i 到 j-1
            int j = trip[2]-1;
            df.increment(i, j, val);
        }
        vector<int> res = df.result();
        for (int i = 0; i < res.size(); i++)
            if (capacity < res[i])
                return false;
        return true;

    }
};
// @lc code=end

