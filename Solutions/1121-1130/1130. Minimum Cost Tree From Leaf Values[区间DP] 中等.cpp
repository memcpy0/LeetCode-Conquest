/*
** Problem: https://leetcode.cn/problems/minimum-cost-tree-from-leaf-values
** Article: https://memcpy0.blog.csdn.net/article/details/111707603
** Author: memcpy0
*/
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size(); // dp[i][j]表示子数组[i,j]对应的子树中所有非叶节点的最小总和
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX >> 2)); 
        vector<vector<int>> mval(n, vector<int>(n)); // m[i][j]表示子数组[i,j]的最大值
        for (int j = 0; j < n; ++j) { // j在后面
            mval[j][j] = arr[j];
            dp[j][j] = 0;
            for (int i = j - 1; i >= 0; --i) { // 从小区间开始
                mval[i][j] = max(arr[i], mval[i + 1][j]);
                for (int k = i; k < j; ++k)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] +
                        mval[i][k] * mval[k + 1][j]);
            }
        }
        return dp[0][n - 1];
    }
};