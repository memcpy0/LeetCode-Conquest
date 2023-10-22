/*
** Problem: https://leetcode.cn/problems/constrained-subsequence-sum/
** Article: https://memcpy0.blog.csdn.net/article/details/133981009
** Author: memcpy0
*/
// BEST: 动态规划+单调队列优化
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        // 存储动态规划结果的数组
        vector<int> f(n);
        // 我们直接放入f[0]的值，防止处理边界情况
        f[0] = nums[0];
        // 单调队列
        deque<int> q;
        // 一开始唯一的j为0
        q.push_back(0);
        int ans = nums[0];
        for (int i = 1; i < n; ++i) {
            // 如果队首的j与i的差值大于k，则不满足要求，弹出
            while (!q.empty() && i - q.front() > k) q.pop_front();
            // 此时队首的j即为最优的j值
            f[i] = max(f[q.front()], 0) + nums[i];
            ans = max(ans, f[i]);
            
            // 维护队列的单调性，不断从队尾弹出元素
            while (!q.empty() && f[i] >= f[q.back()]) q.pop_back();
            // 将i作为之后的新j值放入队尾
            q.push_back(i);
        }
        return ans;
    }
};