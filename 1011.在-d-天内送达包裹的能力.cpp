/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution {
public:
    int sumWeight(vector<int>& weights, int ship) {
        // f(x) 设定要非常准确细心才行
        int days = 1;
        int sum_i = 0;
        for(int weight: weights) {
            if (sum_i+weight > ship) {
                days++;
                sum_i=0;
            }
            sum_i += weight;
        }
        return days;
    }

    // 注意它是单调递减数列
    int left_bound(vector<int>& weights, int target, int max_values) {
        // 最小速度即左边界
        // 需要结合题目，因为运载能力下限不可能比单个货物重量还要轻，所以需要max
        int left = *max_element(weights.begin(), weights.end());
        int right = max_values;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (sumWeight(weights, mid)==target) right = mid;
            else if (sumWeight(weights, mid) < target) right = mid;
            else if (sumWeight(weights, mid) > target) left = mid+1;
        }
        return left;
        
    }

    int shipWithinDays(vector<int>& weights, int days) {
        // 同时也要确定合适对应的上限
        int max_values = accumulate(weights.begin(), weights.end(), 0);
        return left_bound(weights, days, max_values);
    }
};
// @lc code=end

