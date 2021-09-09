/*
** Problem: https://leetcode-cn.com/problems/maximal-square/
** Article: https://memcpy0.blog.csdn.net/article/details/120205494
** Author: memcpy0
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(2, vector<int>(n + 1)); 
        //dp[i][j]为以第i-1行第j-1列为右下角,能构成的最大的正方形边长
        //dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
        int maxEdge = 0; //最长的正方形边长
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i & 1][j] = 1 + min(min(dp[!(i & 1)][j], dp[i & 1][j - 1]), dp[!(i & 1)][j - 1]);
                    maxEdge = max(maxEdge, dp[i & 1][j]);
                } else dp[i & 1][j] = 0; //记得清零
            }
        }
        return maxEdge * maxEdge;
    } 
};