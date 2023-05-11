/*
** Problem: https://leetcode.cn/problems/the-employee-that-worked-on-the-longest-task/
** Article: https://memcpy0.blog.csdn.net/article/details/130626293
** Author: memcpy0
*/
class Solution {
    public int hardestWorker(int n, int[][] logs) {
        int ans = logs[0][0], mt = logs[0][1];
        for (int i = 1; i < logs.length; ++i) {
            int t = logs[i][1] - logs[i - 1][1];
            if (t > mt || t == mt && logs[i][0] < ans) {
                mt = t;
                ans = logs[i][0];
            }
        }
        return ans;
    }
}