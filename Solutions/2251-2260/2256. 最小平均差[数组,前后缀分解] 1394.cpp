/*
** Problem: https://leetcode.cn/problems/minimum-average-difference/
** Article: https://memcpy0.blog.csdn.net/article/details/133859988
** Author: memcpy0
*/
// BEST:O(1)空间
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        typedef long long ll;
        int n = nums.size();
        ll pre = 0, suf = 0;
        for (int v : nums) suf += v;
        int minDiff = INT_MAX, minIdx = -1;
        for (int i = 0; i < n; ++i) {
            pre += nums[i]; // 前缀和
            suf -= nums[i]; // 后缀和
            int d = abs(pre / (i + 1) - (i == n - 1 ? 0 : suf / (n - i - 1)));
            if (d < minDiff) {
                minDiff = d;
                minIdx = i;
            }
        }
        return minIdx;
    }
};