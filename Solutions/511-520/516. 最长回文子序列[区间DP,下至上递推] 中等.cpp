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
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                dp[i][j] = (i == j ? 1 : //长度为1时特判
                    max(dp[i + 1][j - 1] + (s[i] == s[j] ? 2 : 0), //长度不为1时 //可能都包含,或都不包含
                        max(dp[i + 1][j], dp[i][j - 1])) //不包含s[i]或s[j]
                );
            }
        }
        return dp[0][n - 1];
    }
};