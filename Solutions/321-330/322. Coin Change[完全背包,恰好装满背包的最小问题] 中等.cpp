/*
** Problem: https://leetcode.cn/problems/coin-change/
** Article: https://memcpy0.blog.csdn.net/article/details/109458595
** Author: memcpy0
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1); // dp[i]表示值为i的时候, 最少的硬币数量
        dp[0] = 0; // 完全背包
        for (int i = 0; i < coins.size(); ++i) 
            for (int j = coins[i]; j <= amount; ++j)
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        if (dp[amount] <= amount) return dp[amount]; // 可以凑够总金额
        return -1; // 如果dp[amount]>amount,则说明它是从某个无法凑够j-coins[i]的位置转移过来的
    }
};