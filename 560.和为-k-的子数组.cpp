/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    // int subarraySum(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     vector<int> preSum(n+1);
    //     for (int i=0; i < n; i++)
    //         preSum[i + 1] = preSum[i] + nums[i];
    //     int res = 0;

    //     for (int i = 1; i <= n; i++)
    //         for (int j = 0; j < i; j++)
    //             if (preSum[i] - preSum[j] == k)
    //                 res++; 
    //     return res;
    // }

    // 此方法只 beats 5.57% 的 runtime
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> m;
        // base case
        m[0] = 1;
        int res = 0;
        int sum0_i = 0;
        for (int i = 0; i < n; i++) {
            sum0_i += nums[i];
            int sum0_j = sum0_i - k;
            if (m.find(sum0_j) != m.end())
                res += m[sum0_j];
            if (m.find(sum0_i) == m.end())
                m[sum0_i] = 0;
            m[sum0_i] += 1;
        }
        return res;

    }
};

// 官方的解法： 
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         unordered_map<int, int> mp;
//         mp[0] = 1;
//         int count = 0, pre = 0;
//         for (auto& x:nums) {
//             pre += x;
//             if (mp.find(pre - k) != mp.end()) {
//                 count += mp[pre - k];
//             }
//             mp[pre]++;
//         }
//         return count;
//     }
// };
// @lc code=end

