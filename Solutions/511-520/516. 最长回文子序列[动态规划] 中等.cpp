/*
** Problem: https://leetcode-cn.com/problems/longest-palindromic-subsequence/
** Article: 
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.size() <= 1) return s.size();
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                dp[i][j] = (i == j ? 1 : 
                    max((s[i] == s[j] ? dp[i + 1][j - 1] + 2 : 0),
                        max(dp[i + 1][j], dp[i][j - 1]))
                );
            }
        }
        return dp[0][n - 1];
    }
};