/*
** Problem: https://leetcode.cn/problems/sum-in-a-matrix/
** Article: https://memcpy0.blog.csdn.net/article/details/131544351
** Author: memcpy0
*/
// BEST: 排序
class Solution {
public:
    int matrixSum(vector<vector<int>> &nums) {
        for (auto &row: nums)
            sort(row.begin(), row.end());
        int ans = 0, n = nums[0].size();
        for (int j = 0; j < n; j++) {
            int mx = 0;
            for (auto &row: nums)
                mx = max(mx, row[j]);
            ans += mx;
        }
        return ans;
    }
};