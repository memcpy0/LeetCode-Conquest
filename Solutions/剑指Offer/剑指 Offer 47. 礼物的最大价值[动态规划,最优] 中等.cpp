/*
** Problem: https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/
** Article: https://memcpy0.blog.csdn.net/article/details/111714419
** Author: memcpy0
*/
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n + 1);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dp[j + 1] = max(dp[j], dp[j + 1]) + grid[i][j];
        return dp[n];
    }
};