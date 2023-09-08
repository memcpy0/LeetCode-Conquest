/*
** Problem: https://leetcode.cn/problems/minimum-time-to-repair-cars
** Article: https://memcpy0.blog.csdn.net/article/details/132752428
** Author: memcpy0
*/
// BEST: 二分+计数+提前退出
class Solution {
public:
    long long repairCars(vector<int> &ranks, int cars) {
        int min_r = ranks[0], cnt[101]{}; // 数组比哈希表更快
        for (int r : ranks) {
            min_r = min(min_r, r);
            cnt[r]++;
        }
        long long left = 0, right = 1LL * min_r * cars * cars;
        while (left + 1 < right) {
            long long mid = (left + right) / 2, s = 0;
            for (int r = min_r; r <= 100 && s < cars; r++) // 至多循环 100 次
                s += (long long) sqrt(mid / r) * cnt[r];
            (s >= cars ? right : left) = mid;
        }
        return right;
    }
};