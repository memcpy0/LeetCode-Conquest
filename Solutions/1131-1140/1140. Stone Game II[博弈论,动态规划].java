/*
** Problem: https://leetcode.cn/problems/stone-game-ii/
** Article: https://memcpy0.blog.csdn.net/article/details/129273436
** Author: memcpy0
*/
class Solution {
    public int stoneGameII(int[] piles) {
        int n = piles.length, sum = 0;
        int[][] dp = new int[n][n + 1];
        for (int i = n - 1; i >= 0; --i) { // 直接用一个sum替代了前缀和数组
            sum += piles[i];
            for (int M = 1; M <= n; ++M) {
                if (i + 2 * M >= n) // 考虑边界情况
                    dp[i][M] = sum;
                else 
                    for (int x = 1; x <= 2 * M; ++x)
                        dp[i][M] = Math.max(dp[i][M], sum - dp[i + x][Math.max(M, x)]);
            }
        }
        return dp[0][1];
    }
}