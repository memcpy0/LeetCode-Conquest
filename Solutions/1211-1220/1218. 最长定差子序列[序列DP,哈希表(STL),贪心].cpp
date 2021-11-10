/*
** Problem: https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference/
** Article: https://memcpy0.blog.csdn.net/article/details/121185552
** Author: memcpy0
*/
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        // dp[i][j]表示arr[0,i]中第i个数选择情况为j时的最长定差子序列长度
        vector<vector<int>> dp(2, vector<int>(n));
        dp[0][0] = 0, dp[1][0] = 1;
        unordered_map<int, int> hash;
        hash[arr[0]] = 0;
        for (int i = 1; i < n; ++i) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
            dp[1][i] = 1;
            int prev = arr[i] - difference;
            if (hash.find(prev) != hash.end())
                dp[1][i] = dp[1][hash[prev]] + 1;
            hash[arr[i]] = i; 
        } 
        return max(dp[0][n - 1], dp[1][n - 1]);
    }
};