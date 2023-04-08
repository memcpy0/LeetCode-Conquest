/*
** Problem: https://leetcode.cn/problems/moving-stones-until-consecutive-ii/
** Article: https://memcpy0.blog.csdn.net/article/details/130025561
** Author: memcpy0
*/
class Solution {
public:
    vector<int> numMovesStonesII(vector<int> &s) {
        sort(s.begin(), s.end());
        int n = s.size();
        int e1 = s[n - 2] - s[0] - n + 2;
        int e2 = s[n - 1] - s[1] - n + 2;
        int max_move = max(e1, e2);
        if (e1 == 0 || e2 == 0) // 特殊情况：没有空位
            return {min(2, max_move), max_move};
        int max_cnt = 0, left = 0;
        for (int right = 0; right < n; ++right) { // 滑动窗口：枚举右端点
            while (s[right] - s[left] + 1 > n) // 窗口大小大于 n
                ++left;
            max_cnt = max(max_cnt, right - left + 1); // 维护窗口内的最大石子数
        }
        return {n - max_cnt, max_move};
    }
};