/*
** Problem: https://leetcode.cn/problems/reducing-dishes/
** Article: https://memcpy0.blog.csdn.net/article/details/133973182
** Author: memcpy0
*/
// 动态规划+排序
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        int ans = 0;
        // dp[i][j]表示前i道菜中选择j道菜时可以得到的最大喜爱时间
        // dp[i][j]=max(dp[i][j], dp[i-1][j-1]+j*s[i])
        // dp[i][j]=max(dp[i][j], dp[i-1][j]), if i-1>=j
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i][j] = dp[i - 1][j - 1] + satisfaction[i - 1] * j;
                if (j < i) dp[i][j] = max(dp[i - 1][j], dp[i][j]);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
// BEST: 贪心+排序+前缀和+递推
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(), satisfaction.rend());
        int f = 0; // f(0) = 0
        int s = 0; // satisfaction 的前缀和
        for (int x : satisfaction) {
            s += x;
            if (s <= 0) { // 后面不可能找到更大的 f(k)
                break;
            }
            f += s; // f(k) = f(k-1) + s
        }
        return f;
    }
};