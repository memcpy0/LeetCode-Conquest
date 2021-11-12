/*
** Problem: https://leetcode-cn.com/problems/k-inverse-pairs-array/
** Article: https://memcpy0.blog.csdn.net/article/details/121276035
** Author: memcpy0
*/
class Solution {
public:
    int kInversePairs(int n, int k) {
        if (k > n * (n - 1) / 2 || k < 0) return 0; // 边界情况
        if (k == 0 || k == n * (n - 1) / 2) return 1;

        const int mod = 1e9 + 7;
        vector<vector<int>> dp(2, vector<int>(k + 1));
        for (int i = 1; i <= n; ++i) {
            int bound = min(k, i * (i - 1) / 2); // i个数,逆序对数量最大为i*(i-1)/2
            dp[i & 1][0] = 1; // 边界情况
            for (int j = 1; j <= bound; ++j) {
                dp[i & 1][j] = (dp[i & 1][j - 1] + dp[!(i & 1)][j]) % mod;
                if (j >= i)
                    dp[i & 1][j] = (dp[i & 1][j] - dp[!(i & 1)][j - i] + mod) % mod;
            }
        }
        return dp[n & 1][k];
    }
};