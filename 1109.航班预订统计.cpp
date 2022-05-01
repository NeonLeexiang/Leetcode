/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
class Difference {
    // 差分数组
    private: vector<int> diff;
    public:
    Difference(vector<int>& nums) {
        // assert nums.size() > 0;
        diff = vector<int>(nums.size());
        diff[0] = nums[0];
        for (int i=1; i < nums.size(); i++)
            diff[i] = nums[i] - nums[i-1];
    }
    void increment(int i, int j, int val) {
        diff[i] += val;
        if (j+1 < diff.size())
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
    // vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    //     vector<int> m(n);
        
    //     // 需要十分注意，这种看起来简单的中等题目需要注意时间复杂度。
    //     // 这个解法是超时了。
    //     for (int i=0; i < bookings.size(); i++) {
    //         int start = bookings[i][0];
    //         int end = bookings[i][1];
    //         int book = bookings[i][2];
    //         for (start; start < end+1; start++)
    //             m[start-1] += book;
    //     }     

    //     return m;
    // }


    // 接下来我们使用差分数组解法。
    

    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> nums(n);
        Difference df = Difference(nums);
        for (vector<int> booking: bookings) {
            int i = booking[0] - 1;
            int j = booking[1] - 1;
            int val = booking[2];
            df.increment(i, j, val);
        }
        return df.result();
    }
};
// @lc code=end

