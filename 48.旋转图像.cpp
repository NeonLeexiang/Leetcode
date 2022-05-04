/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // 利用一个巧妙的思维，先将二维矩阵沿对角线反转
        // 然后再对每一列进行反转
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // 然后再对列进行一个反转
        // 注意这样的一个遍历方式的不同
        for (auto &row: matrix) {
            reverse(row);
        }

    }

    void reverse(vector<int>& arr) {
        int i = 0;
        int j = arr.size() - 1;
        while (j > i) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++; j--;
        }
    }
};
// @lc code=end

