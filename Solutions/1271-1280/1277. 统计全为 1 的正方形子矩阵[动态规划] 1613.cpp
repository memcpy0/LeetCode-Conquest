/*
** Problem: https://leetcode.cn/problems/count-square-submatrices-with-all-one
** Article: https://memcpy0.blog.csdn.net/article/details/133684118
** Author: memcpy0
*/
// BEST: 动态规划+O(n)空间, 同221.最大正方形
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n + 1);
        int ans = 0;
        int pre = 0, temp = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    temp = dp[j + 1];
                    dp[j + 1] = 1 + 
                        min(pre, 
                            min(dp[j + 1], dp[j]));
                    pre = temp; // pre为dp[i][j]
                    ans += dp[j + 1];
                } else pre = dp[j + 1], dp[j + 1] = 0; // 注意此时也要记录dp[i][j],并更新dp[i+1][j+1]
            }
        }
        return ans;
    }
};