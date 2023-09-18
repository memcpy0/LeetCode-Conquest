/*
** Problem: https://leetcode.cn/problems/gaM7Ch
** Article: https://memcpy0.blog.csdn.net/article/details/133000449
** Author: memcpy0
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        for (int i = 0; i < coins.size(); ++i)
            for (int j = coins[i]; j <= amount; ++j)
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        return dp[amount] <= amount ? dp[amount] : -1;
    }
};