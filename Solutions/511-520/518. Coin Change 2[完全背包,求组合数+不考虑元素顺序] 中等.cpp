/*
** Problem: https://leetcode.cn/problems/coin-change-ii/
** Article: https://memcpy0.blog.csdn.net/article/details/115265696
** Author: memcpy0
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) 
            for (int j = coins[i - 1]; j <= amount; ++j) 
                    dp[j] += dp[j - coins[i - 1]];
        return dp[amount];
    }
};