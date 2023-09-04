/*
** Problem: https://leetcode-cn.com/problems/unique-paths
** Article: https://memcpy0.blog.csdn.net/article/details/107001072
** Author: memcpy0
*/
// 动态规划
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[210][210] = {0};
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == 1 && j == 1) dp[i][j] = 1;
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        } 
        return dp[m][n];
    }
};
// BEST: 组合数学
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for (int x = n, y = 1; y < m; ++x, ++y)
            ans = ans * x / y;
        return ans;
    }
};