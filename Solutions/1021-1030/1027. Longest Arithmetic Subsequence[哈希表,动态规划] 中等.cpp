/*
** Problem: https://leetcode.cn/problems/longest-arithmetic-subsequence/
** Article: https://memcpy0.blog.csdn.net/article/details/130302244
** Author: memcpy0
*/
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 2)); // dp[i][j]表示以nums[i],nums[j]结尾的最长等差数列的长度,初始化为2
        unordered_map<int, int> rec;
        int ans = 2;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int target = 2 * nums[i] - nums[j];
                if (rec.find(target) != rec.end()) dp[i][j] = dp[rec[target]][i] + 1;
                ans = max(dp[i][j], ans); 
            }
            rec[nums[i]] = i;
        }
        return ans;
    }
};

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int dp[n + 1][1020];
        int ans = 0;
        for (int i = 0; i < n; ++i) { // dp[i][j]表示以nums[i]结尾,公差为j的最长等差子序列的长度
            for (int j = 0; j < 1020; ++j) dp[i][j] = 1; // 都为1
            for (int j = 0; j < i; ++j) {
                int diff = nums[i] - nums[j] + 500;
                dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};