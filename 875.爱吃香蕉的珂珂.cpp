/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
public:
    int eatingHours(vector<int>& piles, int max_hours) {
        int need_time = 0;
        for (int j = 0; j < piles.size(); j++) {
            need_time += piles[j] / max_hours;
            if (piles[j] % max_hours) need_time++;
        }
        return need_time;
    }
    // 注意它是单调递减数列
    int left_bound(vector<int>& piles, int target, int max_values) {
        // 最小速度即左边界
        int left = 1;
        int right = max_values+1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (eatingHours(piles, mid)==target) right = mid;
            else if (eatingHours(piles, mid) < target) right = mid;
            else if (eatingHours(piles, mid) > target) left = mid+1;
        }
        return left;
        
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int max_values = *max_element(piles.begin(), piles.end());
        // for (auto c: hours_nums) cout<<c<<' ';
        return left_bound(piles, h, max_values);
    }
};
// @lc code=end

