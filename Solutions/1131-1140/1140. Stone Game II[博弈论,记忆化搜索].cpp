/*
** Problem: https://leetcode.cn/problems/stone-game-ii/
** Article: https://memcpy0.blog.csdn.net/article/details/129273436
** Author: memcpy0
*/
class Solution {
private:
    vector<int> suffix_sum;
    int n;
    int dp[200][200];
    int dfs(int i, int m) {
        if (i + 2 * m >= n)
            return dp[i][m] = suffix_sum[i];
        int temp = INT_MAX;
        for (int x = 1; x <= 2 * m; ++x) {
            int b = max(x, m);
            if (dp[i + x][b]) temp = min(dp[i + x][b], temp);
            else temp = min(dfs(i + x, b), temp);
        }
        return dp[i][m] = suffix_sum[i] - temp;
    }
public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suffix_sum.resize(n); 
        suffix_sum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i)
            suffix_sum[i] = piles[i] + suffix_sum[i + 1];
        return dp[0][1] = dfs(0, 1); 
        // dfs(i,m)返回爱丽丝从0开始取石头,开始最多只能取1堆得到的最大石头数
    }
};