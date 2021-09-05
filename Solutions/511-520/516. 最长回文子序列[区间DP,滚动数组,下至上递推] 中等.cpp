/*
** Problem: https://leetcode-cn.com/problems/longest-palindromic-subsequence/
** Article: https://memcpy0.blog.csdn.net/article/details/120108474
** Author: memcpy0
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.size() <= 1) return s.size();
        int n = s.size();
        vector<vector<int>> dp(2, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                dp[i & 1][j] = (i == j ? 1 : 
                    max(dp[!(i & 1)][j - 1] + (s[i] == s[j] ? 2 : 0),
                        max(dp[!(i & 1)][j], dp[i & 1][j - 1]))
                );
            }
        }
        return dp[0][n - 1];
    }
};